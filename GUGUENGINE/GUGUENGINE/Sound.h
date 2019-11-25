#pragma once

#include "fmod.hpp"

class Sound
{
public:
	Sound();
	~Sound();

	void Free();
	void LoadMusic(const char* filePath);
	bool IsPlaying();
	bool IsPaused();
	void Play(int loop = -1);
	void Pause();
	void Resunme();
	void Stop();
	void Rewind();

	void SetVolume();
	int GetVolume();

private:
	FMOD::System* system = 0;
	FMOD::Sound* sound = 0;
	FMOD::Channel* channel = 0;
	
};