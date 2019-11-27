#pragma once

#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Sound.h"

class Sound;

class Level1 : public LevelManager
{
public:
<<<<<<< HEAD
	
	Level1()
	{
		puzzle1 = nullptr;
		key=0;
	}
=======
>>>>>>> 346ed081468116eafdfc1899d48f309d5a45d0c9
	void Init() override;
	void Update() override;
	void Close() override;
	
private:
	Object* puzzle1, *puzzle2, *puzzle3, *puzzle4;
	int key;
	Mesh mMesh;
	Shader mShader, mShader2;
<<<<<<< HEAD
	Sound bgm;

=======
	glm::vec3 getOrigin = { 0, 0, 0 };
	glm::vec3 getOrigin2 = { 0, 0, 0 };
>>>>>>> 346ed081468116eafdfc1899d48f309d5a45d0c9
};