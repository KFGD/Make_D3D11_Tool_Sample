// 기본 DLL 파일입니다.

#include "stdafx.h"
#include "../Core/D3D11Base.h"
#include "CLICore.h"
#include <Windows.h>

namespace CLICore
{
	Core::Core() : d3d11Base(new CD3D11Base)
	{

	}
	Core::~Core()
	{
		if (d3d11Base)
		{
			delete d3d11Base;
			d3d11Base = nullptr;
		}
	}

	bool Core::InitializeDirect3D(int hWnd) {
		return d3d11Base->InitializeDirect3D((HWND)hWnd);
	}

	void Core::UninitializeDirect3D() {
		d3d11Base->UninitializeDirect3D();
	}

	void Core::Loop() {
		d3d11Base->Loop();
	}
}