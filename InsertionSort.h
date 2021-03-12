#pragma once

#include <cassert>

namespace algorithms {

template <typename T>
void InsertionSort(T *const beginPtr, T *const endPtr) {
    assert(endPtr > beginPtr);
    if ((beginPtr + 1) >= endPtr) {
        return;
    }

    T *iter = beginPtr + 1;

    do {
        T *sortedIter = iter - 1;
        do {
            if (*iter >= *sortedIter || sortedIter < beginPtr) {
                ++sortedIter;
                if (iter != sortedIter) {
                    T temp = *iter;
                    std::memmove(sortedIter + 1, sortedIter, sizeof(T) * (iter - sortedIter));
                    *sortedIter = temp;
                }
                break;
            }
            --sortedIter;
        } while (true);
        ++iter;
    } while (iter != endPtr);
}

template <typename T>
void InsertionSort(T *const beginPtr, const size_t sortSize) {
    InsertionSort(beginPtr, beginPtr + sortSize);
}


} // namespace algorithms

