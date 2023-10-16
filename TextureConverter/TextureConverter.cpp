#include "TextureConverter.h"
#include <WinNls.h>
#include"DirectXTex/DirectXTex.h"
void TextureConverter::ConvertTextureWiCToDDS(const std::string& filePath)
{
	//�e�N�X�`���t�@�C������݂���
	LoadWICTextureFromFile(filePath);
}

void TextureConverter::LoadWICTextureFromFile(const std::string& filePath)
{
	HRESULT result;
	//�t�@�C���p�X���킢�Ǖ�����ɕϊ�
	std::wstring wfilePath = ConvertMultiByteStringToWideString(filePath);
	//WIC�e�N�X�`���̃��[�h
	result = DirectX::LoadFromWICFile(wfilePath.c_str(), DirectX::WIC_FLAGS::WIC_FLAGS_NONE, &metadata_, scratchImage_);
	assert(SUCCEEDED(result));
}

std::wstring TextureConverter::ConvertMultiByteStringToWideString(const std::string& mString)
{
	//���C�h������ɕϊ������T�C�̕�������v�Z
	int filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);
		//���C�h������
	std::wstring wString;
	wString.resize(filePathBufferSize);
	//���C�h������ɕϊ�
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &wString[0], filePathBufferSize);

	
	return std::wstring();
}

void TextureConverter::SeparateFilePath(const std::wstring& filePath)
{
	size_t pos1;
	std::wstring excepExt;
	//��؂蕶��
	pos1 = filePath.rfind('.');
	//�������q�b�g
	if (pos1 != std::wstring::npos)
	{
		//	��؂蕶���̌����t�@�C���g���q�Ƃ��ĕۑ�
		fileExt_ = filePath.substr(pos1 + 1, filePath.size() - pos1 - 1);
	    //��؂蕶���̑O�܂ł𔲂��o��
		excepExt = filePath.substr(0, pos1);
	}
	else {
		fileExt_ = L"";
		excepExt = filePath;
	}
	//��؂蕶��'\\'
	pos1 = excepExt.rfind('\\');
	if (pos1 != std::wstring::npos)
	{
		//��؂蕶���̑O�܂ł��ق���
		directoryPath_ = excepExt.substr(0, pos1 + 1);
		//��؂蕶���̌���

	}

}
