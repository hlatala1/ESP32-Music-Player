
#pragma once

#include "VolumeController.h"
#include "TrackLibrary.h"

class MusicPlayer {
private:
    VolumeController volumeController;
    TrackLibrary trackLibrary;

public:
    void addTrack(const std::string& name);
    size_t getTrackCount() const;
    std::string getTrack(size_t index) const;
    
    void setVolume(int value);
    int getVolume() const;
};

