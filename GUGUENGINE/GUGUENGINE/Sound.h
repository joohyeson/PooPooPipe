#pragma once
/*
 *eunjin.hong
 *9.23.2019
 *chocob0217@gmail.com
 *Sound.h
 *this is a header for sound
 */
#include <string>
#include <vector>
#include "fmod.hpp"
#include "System.h"

class Sound : public System
{
public:
	void Init() override;
	void Update() override;

	Sound();
	~Sound();

	//void Free();
	void LoadMusic(const char* filePath);
	
	void Load();

	bool IsPlaying();
	bool IsPaused();
	void Play(std::string source, int loop = 1);
	void Pause();
	void Resume();
	void Stop();
	void Rewind();


	

	void SetVolume(float volume = 0.3f);
	float GetVolume();

	void SetLoopCount(int loopCount);

private:

	struct SOUNDMANAGER
	{
		FMOD::Channel* channel = nullptr;
		FMOD::Sound* sound = nullptr;
		unsigned int IsPlaying = 0;

		std::string source = "";
	};

	std::vector<SOUNDMANAGER*> m_sounds;

	FMOD::System* system;

	FMOD::ChannelGroup* soundEffects = nullptr;
	FMOD::ChannelGroup* backgroundSounds = nullptr;
	FMOD::ChannelGroup* masterChannel = nullptr;

	bool isPlaying = false;
	float m_volume;

	FMOD_RESULT result;
};
extern Sound* SOUND;