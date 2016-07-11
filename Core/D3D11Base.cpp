


CD3D11Base::CD3D11Base()
{
}


CD3D11Base::~CD3D11Base()
{
}

void CD3D11Base::ReadData(const char* fileName, void** buffer, int* length) {
	FILE* fp = fopen(fileName, "rb");
	*buffer = new char[*length];
	fread(*buffer, *length, 1, fp);
	fclose(fp);
}

bool CD3D11Base::InitializeDirect3D(HWND hWnd)
{
	// TODO: Initializing Direct3D
	swapChainDesc.BufferDesc = { 1280, 720,{ 60, 1 }, DXGI_FORMAT_R8G8B8A8_UNORM,

	if (FAILED(D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0,
		nullptr, 0, D3D11_SDK_VERSION, &swapChainDesc, &dxgiSwapChain, &d3dDevice,
		nullptr, &immediateContext)))
		return false;


	ID3D11Resource* backBuffer;
	dxgiSwapChain->GetBuffer(0, __uuidof(ID3D11Resource), (void**)&backBuffer);

	if (FAILED(d3dDevice->CreateRenderTargetView(backBuffer, nullptr, &renderTargetView)))
		return false;


							//
							//Output-Merger Stage:
							//


	void* vertexShaderData;
	int vertexShaderLength;
	ReadData("MyVertexShader.cso", (void**)&vertexShaderData, &vertexShaderLength);

	d3dDevice->CreateVertexShader(vertexShaderData, vertexShaderLength, nullptr, &vertexShader);

	D3D11_INPUT_ELEMENT_DESC inputEelementDescs[] = {
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },

	d3dDevice->CreateInputLayout(inputEelementDescs, _countof(inputEelementDescs), vertexShaderData, vertexShaderLength, &inputLayout);
	delete[] vertexShaderData;

	void* pixelShaderData;
	int pixelShaderLength;
	ReadData("MyPixelShader.cso", (void**)&pixelShaderData, &pixelShaderLength);

	d3dDevice->CreatePixelShader(pixelShaderData, pixelShaderLength, nullptr, &pixelShader);
	delete[] pixelShaderData;

	MyVertex vertices[] = {
		{ -0.5f, -0.5f, +0.0f },
		{ +0.0f, +0.5f, +0.0f },
		{ +0.5f, -0.5f, +0.0f }
	};



	d3dDevice->CreateBuffer(&vertexBufferDesc, &vertexBufferSubResourceData, &vertexBuffer);

	D3D11_VIEWPORT viewport = { 0, };
	viewport.Width = 1280;
	viewport.Height = 720;
	viewport.MaxDepth = 1.0f;

	return true;
}

void CD3D11Base::UninitializeDirect3D()
{
	// TODO: Uninitializing Direct3D
	vertexBuffer->Release();

	inputLayout->Release();
	pixelShader->Release();
	vertexShader->Release();

	renderTargetView->Release();

	immediateContext->Release();
	d3dDevice->Release();
	dxgiSwapChain->Release();
}

void CD3D11Base::Loop()
{
	// TODO: Rendering


	immediateContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	UINT stride = sizeof(MyVertex), offset = 0;

	immediateContext->Draw(3, 0);

	dxgiSwapChain->Present(0, 0);
}
