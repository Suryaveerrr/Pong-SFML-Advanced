#include "SoundManager.h"
#include <iostream>

namespace Sound
{
    sf::SoundBuffer SoundManager::ballBounce;
    sf::Sound SoundManager::soundEffect;
    const std::string SoundManager::ballBouncePath = "C:\\Users\\Surya\\OneDrive\\Desktop\\Pong-SFML-main\\Assets\\Sounds\\Ball_Bounce.wav";

    void SoundManager::Initialize()
    {
        LoadSoundFromFile();
    }

    void SoundManager::LoadSoundFromFile()
    {
        if (!ballBounce.loadFromFile(ballBouncePath))
        {
            std::cerr << "Error loading ball bounce sound: " << ballBouncePath << std::endl;
        }
    }

    void SoundManager::PlaySoundEffect(SoundType soundType)
    {
        switch (soundType)
        {
        case BALL_BOUNCE:
            soundEffect.setBuffer(ballBounce);
            break;
        default:
            std::cerr << "Unknown sound type!" << std::endl;
            return;
        }
        soundEffect.play();
    }
}