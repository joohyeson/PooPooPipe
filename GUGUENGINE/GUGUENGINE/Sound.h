#pragma once

#include "fmod.hpp"
#include "System.h"

class Sound : public System
{
public:
	void Init() override;
	void Update() override;

	Sound();
	~Sound();

	void Free();
	void LoadMusic(const char* filePath);
	bool IsPlaying();
	bool IsPaused();
	void Play(int loop = -1);
	void Pause();
	void Resume();
	void Stop();
	void Rewind();

	void SetVolume(int volume);
	int GetVolume();

private:
	FMOD::System* system;
	FMOD::Sound* sound;
	FMOD::Channel* channel;
	int m_volume;

	FMOD_RESULT result;
	
};
