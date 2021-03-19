#pragma once

#include <algorithm>

namespace algorithms {

template <typename T>
T *partition(T *beginPtr, T *endPtr) {
    T *pivotPtr = endPtr - 1;
    endPtr -= 2;

    while (beginPtr <= endPtr) {
        while (*beginPtr < *pivotPtr) {
            ++beginPtr;
        }
        if (beginPtr <= endPtr) {
            while (*endPtr >= *pivotPtr) {
                --endPtr;
            }
            if (beginPtr < endPtr) {
                std::swap(*beginPtr, *endPtr);
                ++beginPtr;
                --endPtr;
            }
        }
    }

    std::swap(*pivotPtr, *beginPtr);
    return beginPtr;
}

template <typename T>
void QuickSort(T * beginPtr, T * endPtr) {
    while ((beginPtr + 1) < endPtr) {
        T *partitionPtr = partition(beginPtr, endPtr);
        if ((partitionPtr - beginPtr) < (endPtr - partitionPtr)) {
            QuickSort<T>(beginPtr, partitionPtr);
            beginPtr = partitionPtr + 1;
        } else {
            QuickSort<T>(partitionPtr + 1, endPtr);
            endPtr = partitionPtr;
        }
    }
}

template <typename T>
void QuickSort(T *const beginPtr, const size_t sortSize) {
    QuickSort(beginPtr, beginPtr + sortSize);
}

} // namespace algorithms

