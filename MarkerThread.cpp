
#include "MarkerThread.h"
#include <iostream>
#include <cstdlib>

constexpr DWORD SLEEP_MS = 5;

MarkerThread::MarkerThread(int id, SharedArray& array, HANDLE startEvent, HANDLE controlEvent)
    : id_(id), array_(array), startEvent_(startEvent), controlEvent_(controlEvent) {}

void MarkerThread::start() {
    thread_ = std::thread(&MarkerThread::run, this);
}

void MarkerThread::join() {
    if (thread_.joinable())
        thread_.join();
}

int MarkerThread::id() const { return id_; }

void MarkerThread::run() {
    WaitForSingleObject(startEvent_, INFINITE);
    srand(id_);

    while (true) {
        size_t idx = rand() % array_.size();
        if (!array_.tryMark(idx, id_)) {
            std::cout << "Marker " << id_ << " blocked at index " << idx << std::endl;
            WaitForSingleObject(controlEvent_, INFINITE);
            array_.clearByMarker(id_);
            return;
        }
        Sleep(SLEEP_MS);
    }
}
