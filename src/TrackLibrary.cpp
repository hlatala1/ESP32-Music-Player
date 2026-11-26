#include "TrackLibrary.h"
#include <algorithm>
#include <stdexcept>

void TrackLibrary::addTrack(const std::string& name) {
    if (!name.empty()){
        if (std::find(std::begin(tracks),std::end(tracks),name) == std::end(tracks)){
            tracks.push_back(name);
        }
    }
}
size_t TrackLibrary::getTrackCount() const {
    return tracks.size();
}
std::string TrackLibrary::getTrack(size_t index) const{
    if(index<tracks.size()){
        return tracks[index];
    }
    else{
       throw std::out_of_range("Track index out of range");
    }
}