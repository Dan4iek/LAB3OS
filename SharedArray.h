
#pragma once
#include <vector>
#include <windows.h>

class SharedArray {
public:
    explicit SharedArray(size_t size);
    bool tryMark(size_t index, int markerId);
    void clearByMarker(int markerId);
    void print() const;
    size_t size() const;

private:
    std::vector<int> data_;
    CRITICAL_SECTION cs_;
};
