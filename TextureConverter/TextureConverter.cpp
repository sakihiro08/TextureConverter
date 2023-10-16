#include "TextureConverter.h"
#include <WinNls.h>
#include"DirectXTex/DirectXTex.h"
void TextureConverter::ConvertTextureWiCToDDS(const std::string& filePath)
{
	//テクスチャファイルをよみこむ
	LoadWICTextureFromFile(filePath);
}

void TextureConverter::LoadWICTextureFromFile(const std::string& filePath)
{
	HRESULT result;
	//ファイルパスをわいど文字列に変換
	std::wstring wfilePath = ConvertMultiByteStringToWideString(filePath);
	//WICテクスチャのロード
	result = DirectX::LoadFromWICFile(wfilePath.c_str(), DirectX::WIC_FLAGS::WIC_FLAGS_NONE, &metadata_, scratchImage_);
	assert(SUCCEEDED(result));
}

std::wstring TextureConverter::ConvertMultiByteStringToWideString(const std::string& mString)
{
	//ワイド文字列に変換したサイの文字列を計算
	int filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);
		//ワイド文字列
	std::wstring wString;
	wString.resize(filePathBufferSize);
	//ワイド文字列に変換
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &wString[0], filePathBufferSize);

	
	return std::wstring();
}

void TextureConverter::SeparateFilePath(const std::wstring& filePath)
{
	size_t pos1;
	std::wstring excepExt;
	//区切り文字
	pos1 = filePath.rfind('.');
	//検索がヒット
	if (pos1 != std::wstring::npos)
	{
		//	区切り文字の後ろをファイル拡張子として保存
		fileExt_ = filePath.substr(pos1 + 1, filePath.size() - pos1 - 1);
	    //区切り文字の前までを抜き出す
		excepExt = filePath.substr(0, pos1);
	}
	else {
		fileExt_ = L"";
		excepExt = filePath;
	}
	//区切り文字'\\'
	pos1 = excepExt.rfind('\\');
	if (pos1 != std::wstring::npos)
	{
		//区切り文字の前までをほぞん
		directoryPath_ = excepExt.substr(0, pos1 + 1);
		//区切り文字の後ろを

	}

}
