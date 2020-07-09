/*
 *eunjin.hong
 *9.23.2019
 *chocob0217@gmail.com
 *Sound.cpp
 *for add sound
 */
#include "Sound.h"
#include <iostream>

Sound* SOUND = nullptr;

void Sound::Init()
{
	//std::cout << "Initialized sound" << std::endl;
	//result = system->init(32, FMOD_INIT_NORMAL, nullptr);
}

void Sound::Update()
{

	result = system->update();

	masterChannel->setVolume(m_volume);

	//for (int i = 0; i < m_sounds.size(); i++)
	//{
	//	m_sounds[i]->channel->setVolume(m_volume);
	//}

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
	SOUND = this;

	system->createChannelGroup("soundEffects", &soundEffects);
	system->createChannelGroup("backgroundSounds", &backgroundSounds);
	masterChannel->addGroup(soundEffects);
	masterChannel->addGroup(backgroundSounds);
	system->getMasterChannelGroup(&masterChannel);

	m_volume = 0.5f;

	soundBarSize = { 150.f, 30.f };
	soundBarPosition = { 15.f, 240.f };

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
	LoadMusic("assets\\yeah.wav");
	LoadMusic("assets\\UI.wav");
	LoadMusic("assets\\fart.mp3");
	LoadMusic("assets\\logo.wav");
	LoadMusic("assets\\footprint.wav");
	LoadMusic("assets\\siren.wav");
}

bool Sound::IsPlaying()
{
	return false;
}

bool Sound::IsPaused()
{
	return isPlaying;
}

void Sound::Play(std::string source, int loop)
{
	//result = channel->setLoopCount(loop);
	//result = system->playSound(sound, 0, false, &channel);

	auto id = 0;

	for (unsigned int i = 0; i < m_sounds.size(); i++)
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
		std::cout << "BGM play" << std::endl;
		m_sounds[id]->IsPlaying = true;
		result = system->playSound(r_sound, nullptr, false, &m_sounds[id]->channel);
		result = m_sounds[id]->channel->setChannelGroup(backgroundSounds);
		result = m_sounds[id]->channel->setVolume(0.5f);

	}
	else if (!m_sounds[id]->IsPlaying)
	{
		std::cout << "Play" << std::endl;
		m_sounds[id]->IsPlaying = true;
		result = system->playSound(r_sound, nullptr, false, &m_sounds[id]->channel);
		result = m_sounds[id]->channel->setChannelGroup(soundEffects);
		result = m_sounds[id]->channel->setVolume(0.5f);
	}

}

void Sound::Pause()
{
	isPlaying = false;
	masterChannel->setPaused(true);
}

void Sound::Resume()
{
	isPlaying = true;
	masterChannel->setPaused(false);
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

}

float Sound::GetVolume()
{
	return m_volume;
}

void Sound::SetLoopCount(int /*loopCount*/)
{
	//channel->setLoopCount(loopCount);
}



