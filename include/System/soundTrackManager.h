#pragma once

#include <SFML/Audio.hpp>
#include <unordered_map>
#include <string>

namespace sharbat {
	class SoundManager {
    public:
        SoundManager();
        ~SoundManager();

        bool loadSound(const std::string& name, const std::string& filepath);
        bool loadMusic(const std::string& name, const std::string& filepath);

        void playSound(const std::string& name);
        void playMusic(const std::string& name, bool loop = true);

        void stopMusic();
    private:
        std::unordered_map<std::string, sf::SoundBuffer> soundBuffers;
        std::unordered_map<std::string, sf::Sound> sounds;

        std::unordered_map<std::string, sf::Music> musicTracks;

        sf::Music* currentMusic;
	};
}
