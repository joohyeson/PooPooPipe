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
    Load();
}

Texture::Texture(Texture&& other) noexcept
    : textureHandle{ other.textureHandle }, width{ other.width }, height{ other.height }
{
    other.textureHandle = 0;
    other.width = 0;
    other.height = 0;
}

void Texture::CreateTexture(char const* filename, Textures typeOfTexture)
{
    GLuint texture;

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


    glBindTexture(GL_TEXTURE_2D, TextureStore.size());

    stbi_image_free(data);

    TextureStore[typeOfTexture] = texture;
}

GLuint Texture::CreateTexture(char const* filename, int i)
{
    GLuint texture;

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
    //TextureStore.push_back(texture);
}

void Texture::Load()
{
    TextureStore.clear();
    CreateTexture("assets\\DigiPen_WHITE_1024px.png",Textures::DIGIPENLOGO);
    CreateTexture("assets\\images2.png", Textures::FMODLOGO);
   CreateTexture("assets\\imagest1.png", Textures::STARTCUT1);
   CreateTexture("assets\\imagest2.png", Textures::STARTCUT2);
   CreateTexture("assets\\imagest3.png", Textures::STARTCUT3);
   CreateTexture("assets\\skip.png", Textures::SKIP);
   CreateTexture("assets\\nextd.png", Textures::nextd);
   CreateTexture("assets\\bar1.png", Textures::BAR1);
   CreateTexture("assets\\quitcheck.png", Textures::QUITCHECK);
   CreateTexture("assets\\yes.png", Textures::YES);
   CreateTexture("assets\\no_p.png", Textures::NO_P);
   CreateTexture("assets\\yes_p.png", Textures::YES_P);
   CreateTexture("assets\\no.png", Textures::no);
   CreateTexture("assets\\background1.png", Textures::background1);
   CreateTexture("assets\\playUI.png", Textures::playUI);
   CreateTexture("assets\\playUI_2.png", Textures::playUI_2);
   CreateTexture("assets\\quitUI.png", Textures::quitUI);
   CreateTexture("assets\\quitUI_2.png", Textures::quitUI_2);
   CreateTexture("assets\\optionUI.png", Textures::optionUI);
   CreateTexture("assets\\optionUI_2.png", Textures::optionUI_2);
   CreateTexture("assets\\restartUI.png", Textures::restartUI);
   CreateTexture("assets\\restartUI_2.png", Textures::restartUI_2);
   CreateTexture("assets\\image0.png", Textures::image0);
   CreateTexture("assets\\image1.png", Textures::image1);
   CreateTexture("assets\\image2.png", Textures::image2);
   CreateTexture("assets\\imageStart.png", Textures::imageStart);
   CreateTexture("assets\\imageEnd.png", Textures::imageEnd);
   CreateTexture("assets\\image0-1.png", Textures::image01);
   CreateTexture("assets\\image2-1.png", Textures::image21);
   CreateTexture("assets\\levelButton.png", Textures::levelButton);
   CreateTexture("assets\\levelButton_2.png", Textures::levelButton_2);
   CreateTexture("assets\\character.png", Textures::character);
   CreateTexture("assets\\clear.png", Textures::clear);
   CreateTexture("assets\\level.png", Textures::level);
  CreateTexture("assets\\01.png", Textures::num1);
  CreateTexture("assets\\02.png", Textures::num2);
   CreateTexture("assets\\failScreen.png", Textures::failScreen);
   CreateTexture("assets\\next.png", Textures::next);

}
void Texture::DeleteTexture() noexcept
{
    glCheck(glDeleteTextures(1, &textureHandle));
}



Texture::~Texture() noexcept
{
    DeleteTexture();

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

