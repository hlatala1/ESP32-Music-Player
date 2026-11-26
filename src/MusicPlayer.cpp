#include "MusicPlayer.h"

void MusicPlayer::addTrack(const std::string& name) {
    trackLibrary.addTrack(name);
}

size_t MusicPlayer::getTrackCount() const{
    return trackLibrary.getTrackCount();
}

std::string MusicPlayer::getTrack(size_t index) const {
    return trackLibrary.getTrack(index);
}
void MusicPlayer::setVolume(int value) {
    volumeController.setVolume(value);
}

int MusicPlayer::getVolume() const {
    return volumeController.getVolume();
}
