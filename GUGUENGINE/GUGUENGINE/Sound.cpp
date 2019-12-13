/*
 *eunjin.hong
 *9.23.2019
 *chocob0217@gmail.com
 *Sound.cpp
 */
#include "Sound.h"
#include <iostream>

Sound* soundPtr = nullptr;

void Sound::Init()
{
	std::cout << "Initialized sound" << std::endl;
	result = system->init(32, FMOD_INIT_NORMAL, nullptr);
}

void Sound::Update()
{
	result = system->update();
	if (result != FMOD_OK)
	{
	}

	if (channel)
	{
		bool playing = false;
		result = channel->isPlaying(&playing);
		if (!playing)
		{
			playing = true;
		}
	}
}

Sound::Sound() 
{
	result = System_Create(&system);
	std::cout << "Sound constructor called" << std::endl;
	soundPtr = this;
}

Sound::~Sound()
{
	delete soundPtr;
}


void Sound::Free()
{
	result = system->release();
}

void Sound::LoadMusic(const char* filePath)
{
	result = system->createSound(filePath, FMOD_LOOP_OFF, 0, &sound);
}

bool Sound::IsPlaying()
{
	return false;
}

bool Sound::IsPaused()
{
	return false;
}

void Sound::Play(int loop)
{
	result = channel->setLoopCount(loop);
	result = system->playSound(sound, 0, false, &channel);
}

void Sound::Pause()
{
	
}

void Sound::Resume()
{
}

void Sound::Stop()
{
	result = channel->stop();
}

void Sound::Rewind()
{
	
}


void Sound::SetVolume(float volume)
{
	m_volume = volume;
	channel->setVolume(volume);
}

float Sound::GetVolume()
{
	return m_volume;
}

void Sound::SetLoopCount(int loopCount)
{
	channel->setLoopCount(loopCount);
}



