#pragma once
#include <string>
#include"TextureConverter.h"
#include"DirectXTex/DirectXTex.h"
class TextureConverter
{
public:
	void ConvertTextureWiCToDDS(const std::string& filePath);
private:
	
	void LoadWICTextureFromFile(const std::string& filePath);
private:
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);
private:
	//�摜�̏��
	DirectX::TexMetadata metadata_;
	//�摜�C���[�W�̃R���e�i
	DirectX::ScratchImage scratchImage_;
private:
	//�t�H���_�p�X�ƃt�@�C�����𕪗�
	void SeparateFilePath(const std::wstring& filePath);
private:
	//�f�B���N�g���p�X
	std::wstring directoryPath_;
	//�t�@�C����
	std::wstring fileName_;
	//�f�B���N�g���p�X
	std::wstring fileExt_;
};
