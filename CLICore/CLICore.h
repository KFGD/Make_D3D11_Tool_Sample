// CLICore.h

#pragma once
#pragma comment(lib, "Core")

using namespace System;
//class CTest;
class CD3D11Base;

namespace CLICore {

	public ref class Core
	{
		// TODO: 여기에 이 클래스에 대한 메서드를 추가합니다.
	protected:
		CD3D11Base* d3d11Base;
	public:
		Core();
		virtual ~Core();

		bool InitializeDirect3D(int hWnd);
		void UninitializeDirect3D();
		void Loop();
		void CreateBufferForTriangle();
		void DeleteBufferForTriangle();
	};
}
