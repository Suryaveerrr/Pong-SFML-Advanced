#pragma once
#include <SFML/Audio.hpp>
#include <string>

namespace Sound
{
    enum SoundType
    {
        BALL_BOUNCE
    };

    class SoundManager
    {
    private:
        static sf::SoundBuffer ballBounce;
        static sf::Sound soundEffect;
        static const std::string ballBouncePath;

        static void LoadSoundFromFile();

    public:
        static void Initialize();
        static void PlaySoundEffect(SoundType soundType);
    };
}