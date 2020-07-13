/*
 *juhye.son
 *11.13.2019
 *juhye.son990902@gmail.com
 *Texture.h
 *header to texture.cpp
 */
#include "glew.h"
#include "filesystem"
#include <map>
class Image;
class Color4ub;

enum class Textures
{
	DIGIPENLOGO, 
	FMODLOGO, 
	STARTCUT1, STARTCUT2, STARTCUT3,SKIP, nextd,
	BAR1, QUITCHECK, YES, NO_P, YES_P, no, background1,playUI, 
	playUI_2, quitUI, quitUI_2, optionUI, optionUI_2, restartUI, restartUI_2, linePuzzle, blackPuzzle,curvePuzzle,
	imageStart, imageEnd, image01, curve2Puzzle, levelButton, levelButton_2,
	character, clear, level, num1,num2, failScreen, next
	,yellow, background2,mini,num5, threePuzzle, vPuzzle, movePuzzle
};

class Texture
{
public:
	Texture();

	void CreateTexture(char const* filename,Textures typeOfTexture);
	void DeleteTexture() noexcept;
	GLuint CreateTexture(char const* filename, int i);
	GLuint GetTexture(Textures typeOfTexture) {
		return TextureStore[typeOfTexture];
	}
	void Load();

	unsigned int GetTextureHandle() const noexcept { return textureHandle; }
	int          GetWidth() const noexcept { return width; }
	int          GetHeight() const noexcept { return height; }

	~Texture() noexcept;
	Texture(Texture&& other) noexcept;
	Texture& operator=(Texture&& other) noexcept;

public:
	Texture(const Texture& other) = delete;
	Texture& operator=(const Texture& other) = delete;

private:
	unsigned int textureHandle = 0;
	int          width = 0;
	int          height = 0;
	std::map<Textures,GLuint> TextureStore;
};
extern Texture* TEXTURE;