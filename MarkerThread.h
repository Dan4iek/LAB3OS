
#pragma once
#include <windows.h>
#include <thread>
#include "SharedArray.h"

class MarkerThread {
public:
    MarkerThread(int id, SharedArray& array, HANDLE startEvent, HANDLE controlEvent);
    void start();
    void join();
    int id() const;

private:
    void run();

    int id_;
    SharedArray& array_;
    HANDLE startEvent_;
    HANDLE controlEvent_;
    std::thread thread_;
};
