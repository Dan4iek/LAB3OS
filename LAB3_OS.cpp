
#include <iostream>
#include <vector>
#include <memory>
#include <windows.h>
#include "SharedArray.h"
#include "MarkerThread.h"

int main() {
    size_t arraySize;
    int markerCount;

    std::cout << "Array size: ";
    std::cin >> arraySize;
    std::cout << "Marker count: ";
    std::cin >> markerCount;

    SharedArray array(arraySize);

    HANDLE startEvent = CreateEvent(nullptr, TRUE, FALSE, nullptr);
    HANDLE controlEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);

    std::vector<std::unique_ptr<MarkerThread>> markers;
    for (int i = 1; i <= markerCount; ++i) {
        markers.push_back(std::make_unique<MarkerThread>(i, array, startEvent, controlEvent));
        markers.back()->start();
    }

    SetEvent(startEvent);

    for (auto& m : markers) {
        SetEvent(controlEvent);
        m->join();
        array.print();
    }

    CloseHandle(startEvent);
    CloseHandle(controlEvent);
    return 0;
}
