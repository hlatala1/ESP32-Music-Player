#pragma once

#include <string>
#include <vector>

class TrackLibrary {
private:
    std::vector<std::string> tracks;

public:
    size_t getTrackCount() const;
    void addTrack(const std::string& name);
    std::string getTrack(size_t index) const;
};