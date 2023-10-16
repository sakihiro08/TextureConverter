#include"stdio.h"
#include"stdlib.h"
#include"TextureConverter.h"
#include <cassert>
#include <combaseapi.h>
#include"DirectXTex/DirectXTex.h"
enum Argument {
	kApplicationPath,
	kFilePath,

	NumArgument
};
int main(int argc,char* argv[])
{
	
	for (int i = 0; i < argc; i++)
	{
		printf(argv[i]);
		printf("\n");
	}
	assert(argc >= NumArgument);
	//Comライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));
    //テクスチャコンバータ
	TextureConverter converter;
	//テクスチャ大賞
	converter.ConvertTextureWiCToDDS(argv[kFilePath]);
	//COMライブラリの終了
	CoUninitialize();
	system("pause");
	return 0;
}