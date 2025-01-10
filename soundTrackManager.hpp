#ifndef SOUNDMANAGER_HPP
#define SOUNDMANAGER_HPP

#include <SFML/Audio.hpp>
#include <unordered_map>
#include <string>

namespace sharbat {
	class SoundManager {
    private:
        // SFX storage
        std::unordered_map<std::string, sf::SoundBuffer> soundBuffers;
        std::unordered_map<std::string, sf::Sound> sounds;

        // Music storage
        std::unordered_map<std::string, sf::Music> musicTracks;

        // Currently playing music
        sf::Music* currentMusic;
    public:
        SoundManager();
        ~SoundManager();

        // Load sounds
        bool loadSound(const std::string& name, const std::string& filepath);
        bool loadMusic(const std::string& name, const std::string& filepath);

        // Play sounds
        void playSound(const std::string& name);
        void playMusic(const std::string& name, bool loop = true);

        // Stop music
        void stopMusic();
	};
}
