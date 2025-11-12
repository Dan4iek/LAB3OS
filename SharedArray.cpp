
#include "SharedArray.h"
#include <iostream>

constexpr int EMPTY = 0;

SharedArray::SharedArray(size_t size) : data_(size, EMPTY) {
    InitializeCriticalSection(&cs_);
}

bool SharedArray::tryMark(size_t index, int markerId) {
    EnterCriticalSection(&cs_);
    if (data_[index] == EMPTY) {
        data_[index] = markerId;
        LeaveCriticalSection(&cs_);
        return true;
    }
    LeaveCriticalSection(&cs_);
    return false;
}

void SharedArray::clearByMarker(int markerId) {
    EnterCriticalSection(&cs_);
    for (auto &v : data_)
        if (v == markerId) v = EMPTY;
    LeaveCriticalSection(&cs_);
}

void SharedArray::print() const {
    for (int v : data_) std::cout << v << " ";
    std::cout << std::endl;
}

size_t SharedArray::size() const {
    return data_.size();
}
