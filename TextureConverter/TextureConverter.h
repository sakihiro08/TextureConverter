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
	//画像の情報
	DirectX::TexMetadata metadata_;
	//画像イメージのコンテナ
	DirectX::ScratchImage scratchImage_;
private:
	//フォルダパスとファイル名を分離
	void SeparateFilePath(const std::wstring& filePath);
private:
	//ディレクトリパス
	std::wstring directoryPath_;
	//ファイル名
	std::wstring fileName_;
	//ディレクトリパス
	std::wstring fileExt_;
};
