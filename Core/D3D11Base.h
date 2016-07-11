#include <d3d11.h>
#include <dxgi.h>
#include <cstdio>
#include <Windows.h>

struct MyVertex { float x, y, z; };

class CD3D11Base
{

private:
	IDXGISwapChain* dxgiSwapChain;

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

