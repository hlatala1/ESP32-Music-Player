#include "VolumeController.h"

VolumeController::VolumeController() : volume(50) {} // Initialize volume to a default value of 50
void VolumeController::setVolume(int value){
    if (value < 0){
        volume = 0;
    }
    else if (value>100)
    {
        volume = 100;
    }
    else
        volume = value;
} 

int VolumeController::getVolume() const{
    return volume;
}