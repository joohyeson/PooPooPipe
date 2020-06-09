/*
 *eunjin.hong
 *9.23.2019
 *chocob0217@gmail.com
 *Sound.cpp
 *for add sound
 */
#include "Sound.h"
#include <iostream>

Sound* soundPtr = nullptr;

void Sound::Init()
{
	//std::cout << "Initialized sound" << std::endl;
	//result = system->init(32, FMOD_INIT_NORMAL, nullptr);
}

void Sound::Update()
{
	
	result = system->update();

	/*
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
	*/
}

Sound::Sound() 
{
	result = System_Create(&system);
	std::cout << "Initialized sound" << std::endl;
	result = system->init(32, FMOD_INIT_NORMAL, nullptr);

	std::cout << "Sound constructor called" << std::endl;
	soundPtr = this;

	system->createChannelGroup("soundEffects", &soundEffects);
	system->createChannelGroup("backgroundSounds", &backgroundSounds);
	masterChannel->addGroup(soundEffects);
	masterChannel->addGroup(backgroundSounds);
	system->getMasterChannelGroup(&masterChannel);

	Load();
}

Sound::~Sound()
{
	for (auto s : m_sounds)
	{
		s->sound->release();

	}

	system->release();
	system->close();
}

//
//void Sound::Free()
//{
//	result = system->release();
//}

void Sound::LoadMusic(const char* filePath)
{
	SOUNDMANAGER* soundmanager = new SOUNDMANAGER;
	auto location = m_sounds.size();
	m_sounds.push_back(soundmanager);

	result = system->createSound(filePath, FMOD_LOOP_NORMAL, 0, &m_sounds[location]->sound);
	m_sounds[location]->source = filePath;
}

void Sound::Load()
{
	LoadMusic("assets\\BGM_airplane.mp3");
	LoadMusic("assets\\coin.mp3");
	LoadMusic("assets\\flushing.wav");
}

bool Sound::IsPlaying()
{
	return false;
}

bool Sound::IsPaused()
{
	return false;
}

void Sound::Play(std::string source, int loop)
{
	//result = channel->setLoopCount(loop);
	//result = system->playSound(sound, 0, false, &channel);

	auto id = 0;

	for (int i = 0; i < m_sounds.size(); i++)
	{
		if (m_sounds[i]->source == source)
		{
			id = i;
			break;
		}
	}

	FMOD::Sound*& r_sound = m_sounds[id]->sound;

	if (loop == 1)
	{
		result = r_sound->setMode(FMOD_LOOP_OFF);
		result = r_sound->setLoopCount(loop);
	}
	else
	{
		result = r_sound->setMode(FMOD_LOOP_NORMAL);
		result = r_sound->setLoopCount(-1);
	}
	

	if (m_sounds[id]->source.find("BGM") == m_sounds[id]->IsPlaying == false)
	{
		m_sounds[id]->IsPlaying = true;
		result = system->playSound(r_sound, nullptr, false, &m_sounds[id]->channel);
		result = m_sounds[id]->channel->setChannelGroup(backgroundSounds);

	}
	else if (!m_sounds[id]->IsPlaying)
	{
		m_sounds[id]->IsPlaying = true;
		result = system->playSound(r_sound, nullptr, false, &m_sounds[id]->channel);
		result = m_sounds[id]->channel->setChannelGroup(soundEffects);

	}

}

void Sound::Pause()
{
	
}

void Sound::Resume()
{
}

void Sound::Stop()
{
	//result = channel->stop();
}

void Sound::Rewind()
{
	
}


void Sound::SetVolume(float volume)
{
	m_volume = volume;
	//channel->setVolume(volume);
}

float Sound::GetVolume()
{
	return m_volume;
}

void Sound::SetLoopCount(int loopCount)
{
	//channel->setLoopCount(loopCount);
}



