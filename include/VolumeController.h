#pragma once

class VolumeController {
private:

    int volume;
public:

    VolumeController(); // Constructor
    
    void setVolume(int value);
    int getVolume() const;
};