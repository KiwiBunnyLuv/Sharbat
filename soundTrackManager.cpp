#include "SoundTrackManager.hpp"
#include <iostream>

namespace sharbat {

    SoundManager::SoundManager() : currentMusic(nullptr) {}

    SoundManager::~SoundManager() {}

    bool SoundManager::loadSound(const std::string& name, const std::string& filepath) {
        sf::SoundBuffer buffer;
        if (!buffer.loadFromFile(filepath)) {
            std::cerr << "Failed to load sound: " << filepath << std::endl;
            return false;
        }
        soundBuffers[name] = buffer;
        sounds[name].setBuffer(soundBuffers[name]);
        return true;
    }

    bool SoundManager::loadMusic(const std::string& name, const std::string& filepath) {
        auto& music = musicTracks[name];
        if (!music.openFromFile(filepath)) {
            std::cerr << "Failed to load music: " << filepath << std::endl;
            return false;
        }
        return true;
    }

    void SoundManager::playSound(const std::string& name) {
        if (sounds.find(name) != sounds.end()) {
            sounds[name].play();
        }
        else {
            std::cerr << "Sound not found: " << name << std::endl;
        }
    }

    void SoundManager::playMusic(const std::string& name, bool loop) {
        if (musicTracks.find(name) != musicTracks.end()) {
            if (currentMusic != nullptr) {
                currentMusic->stop();
            }
            currentMusic = &musicTracks[name];
            currentMusic->setLoop(loop);
            currentMusic->play();
        }
        else {
            std::cerr << "Music not found: " << name << std::endl;
        }
    }

    void SoundManager::stopMusic() {
        if (currentMusic != nullptr) {
            currentMusic->stop();
            currentMusic = nullptr;
        }
    }
}

