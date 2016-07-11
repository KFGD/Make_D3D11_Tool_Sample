#pragma once
#include <d3d11.h>
#include <dxgi.h>
#include <cstdio>
#include <Windows.h>

struct MyVertex { float x, y, z; };

class CD3D11Base
{

private:
	ID3D11Device* d3dDevice;				//하드웨어의 기능 지원 점검과 자원 할당에 사용되는 인터페이스
	ID3D11DeviceContext* immediateContext;	//렌더 대상 설정 및 자원을 그래픽 파이프라인에 바인딩하고 GPU가 수행할 렌더링 명령들을 지시하는 데에 사용되는 인터페이스
	IDXGISwapChain* dxgiSwapChain;

	//텍스처는 PipeLine으로부터 View를 통해서 Access가 가능함, Render-Target도 텍스처의 일종이기 때문에 역시 View를 이용하여 Access해야 한다
	ID3D11RenderTargetView* renderTargetView;	//Render-Target-View

	ID3D11VertexShader* vertexShader;
	ID3D11InputLayout* inputLayout;
	ID3D11PixelShader* pixelShader;
	ID3D11Buffer* vertexBuffer;

public:
	CD3D11Base();
	~CD3D11Base();
	bool InitializeDirect3D(HWND hWnd);
	void UninitializeDirect3D();
	void Loop();
	
private:
	void ReadData(const char* fileName, void** buffer, int* length);
};

