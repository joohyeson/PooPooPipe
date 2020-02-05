/*
 *juhye.son
 *11.13.2019
 *juhye.son990902@gmail.com
 *Texture.cpp
 * for inserting image files
 */
#include <cassert>
#include <filesystem>
#include "Image.h"
#include "Texture.h"
#include "glew.h"
#include "glCheck.h"
#include <iostream>
#include "Mesh.h"
#include "external/stb/include/stb_image.h"
Texture* TEXTURE = nullptr;
Texture::Texture()
{
	TEXTURE = this;
}
bool Texture::LoadFromPNG(const std::filesystem::path& file_path) noexcept
	{
		Image imageLoad;
		imageLoad.LoadFromPNG(file_path);
		return LoadFromImage(imageLoad);
	}

	bool Texture::LoadFromImage(const Image& image) noexcept
	{
		return LoadFromMemory(image.GetWidth(), image.GetHeight(), image.GetPixelsPointer());
	}

	bool Texture::LoadFromMemory(int image_width, int image_height, const Color4ub* colors) noexcept
	{
		assert(image_height > 0 && image_width > 0);

		width = image_width;
		height = image_height;

		DeleteTexture();
		glCheck(glGenTextures(1, &textureHandle));
		glCheck(glBindTexture(GL_TEXTURE_2D, textureHandle));
		glCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
		glCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
		glCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
		glCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
		glCheck(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, colors));
		glCheck(glBindTexture(GL_TEXTURE_2D, textureHandle));

		return textureHandle != NULL;
	}

	void Texture::SelectTextureForSlot(const Texture& texture, unsigned slot) noexcept
	{
		glCheck(glBindTexture(GL_TEXTURE_2D, texture.textureHandle));
		glCheck(glActiveTexture(GL_TEXTURE0 + slot));
	}

	void Texture::DeleteTexture() noexcept
	{
		glCheck(glDeleteTextures(1, &textureHandle));
	}

	Texture::~Texture() noexcept
	{
		DeleteTexture();

	}

	Texture::Texture(Texture&& other) noexcept
		: textureHandle{ other.textureHandle }, width{ other.width }, height{ other.height }
	{
		other.textureHandle = 0;
		other.width = 0;
		other.height = 0;
	}

	Texture& Texture::operator=(Texture&& other) noexcept
	{
		if (this == &other)
			return *this;
		DeleteTexture();
		textureHandle = other.textureHandle;
		width = other.width;
		height = other.height;
		other.textureHandle = 0;
		other.width = 0;
		other.height = 0;
		return *this;
	}

	GLuint Texture::CreateTexture(char const* filename, int i)
	{

		unsigned int texture;

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
	
		int mwidth, mheight, mnrChannels;
		unsigned char* data = stbi_load(filename, &mwidth, &mheight, &mnrChannels, 0);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mwidth, mheight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	
		glBindTexture(GL_TEXTURE_2D, i);
	
		stbi_image_free(data);
		return texture;
		
	}


