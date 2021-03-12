#pragma once

#include <cassert>

namespace algorithms {

template <typename T>
void BubbleSort(T *const beginPtr, T *const endPtr) {
    assert(endPtr > beginPtr);
    if ((beginPtr + 1) >= endPtr) {
        return;
    }

    T *iter;
    bool finished;

    do {
        iter = endPtr - 1;
        finished = true;
        do {
            if (*iter < *(iter - 1)) {
                T temp = *iter;
                *iter = *(iter - 1);
                *(iter - 1) = temp;
                finished = false;
            }
            --iter;
        } while (iter != beginPtr);
    } while (!finished);
}

template <typename T>
void BubbleSort(T *const beginPtr, const size_t sortSize) {
    BubbleSort(beginPtr, beginPtr + sortSize);
}

} // namespace algorithms

