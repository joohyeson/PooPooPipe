#pragma once
/*
 *eunjin.hong
 *9.23.2019
 *chocob0217@gmail.com
 *Sound.h
 *this is a header for sound
 */
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
	

	void SetVolume(float volume = 0.5f);
	float GetVolume();

	void SetLoopCount(int loopCount);

private:
	FMOD::System* system;
	FMOD::Sound* sound;
	FMOD::Channel* channel;

	float m_volume;

	FMOD_RESULT result;
	
};
