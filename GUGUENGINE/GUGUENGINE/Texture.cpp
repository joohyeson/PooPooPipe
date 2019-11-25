#include <cassert>
#include <filesystem>
#include "Image.h"
#include "Texture.h"
#include "glew.h"
#include "glCheck.h"
#include <iostream>
#include "FreeImage.h"
#include "Mesh.h"
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
		FREE_IMAGE_FORMAT format = FreeImage_GetFileType(filename, 0);

		if (format == -1)
		{
			std::cout << "Could not find image: " << filename << " - Aborting." << std::endl;
			exit(-1);
		}

		if (format == FIF_UNKNOWN)
		{
			std::cout << "Couldn't determine file format - attempting to get from file extension..." << std::endl;
			format = FreeImage_GetFIFFromFilename(filename);
			if (!FreeImage_FIFSupportsReading(format))
			{
				std::cout << "Detected image format cannot be read!" << std::endl;
				exit(-1);
			}
		}
		FIBITMAP* bitmap = FreeImage_Load(format, filename);
		int bitsPerPixel = FreeImage_GetBPP(bitmap);

		FIBITMAP* bitmap32;
		if (bitsPerPixel == 32)
		{
			bitmap32 = bitmap;
		}
		else
		{
			std::cout << "Source image has " << bitsPerPixel << " bits per pixel. Converting to 32-bit colour." << std::endl;
			bitmap32 = FreeImage_ConvertTo32Bits(bitmap);
		}

		int imageWidth = FreeImage_GetWidth(bitmap32);
		int imageHeight = FreeImage_GetHeight(bitmap32);

		GLubyte* textureData = FreeImage_GetBits(bitmap32);

		GLuint tempTextureID;
		glGenTextures(1, &tempTextureID);
		glBindTexture(GL_TEXTURE_2D, tempTextureID);

		glTexImage2D(GL_TEXTURE_2D,
			0,
			GL_RGBA,
			imageWidth,
			imageHeight,
			0,
			GL_BGRA,
			GL_UNSIGNED_BYTE,
			textureData);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);


		glBindTexture(GL_TEXTURE_2D, i);

		GLenum glError = glGetError();
		if (glError)
		{
			std::cout << "There was an error loading the texture: " << filename << std::endl;

			switch (glError)
			{
			case GL_INVALID_ENUM:
				std::cout << "Invalid enum." << std::endl;
				break;

			case GL_INVALID_VALUE:
				std::cout << "Invalid value." << std::endl;
				break;

			case GL_INVALID_OPERATION:
				std::cout << "Invalid operation." << std::endl;

			default:
				std::cout << "Unrecognised GLenum." << std::endl;
				break;
			}

			std::cout << "See https://www.opengl.org/sdk/docs/man/html/glTexImage2D.xhtml for further details." << std::endl;
		}

		FreeImage_Unload(bitmap32);
		if (bitsPerPixel != 32)
		{
			FreeImage_Unload(bitmap);
		}

		return tempTextureID;
		
	}


