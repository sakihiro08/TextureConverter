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
	//Com���C�u�����̏�����
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));
    //�e�N�X�`���R���o�[�^
	TextureConverter converter;
	//�e�N�X�`�����
	converter.ConvertTextureWiCToDDS(argv[kFilePath]);
	//COM���C�u�����̏I��
	CoUninitialize();
	system("pause");
	return 0;
}