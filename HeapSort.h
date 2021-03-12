#pragma once

#include <algorithm>

namespace algorithms {

template <typename T>
void siftDown(T *const beginPtr, T *const endPtr, const size_t startIndex = 0) {
    T *emptyPos = beginPtr + startIndex;
    T moveItem = *emptyPos;
    T *maxChild = beginPtr + (startIndex * 2) + 1;

    while ((maxChild + 1) < endPtr) {
        if (*(maxChild + 1) > *maxChild) {
            maxChild += 1;
        }
        if (moveItem > *maxChild) {
            *emptyPos = moveItem;
            return;
        }

        *emptyPos = *maxChild;
        emptyPos = maxChild;
        maxChild = beginPtr + ((emptyPos - beginPtr) * 2) + 1;
    }

    if (maxChild < endPtr && moveItem < *maxChild) {
        *emptyPos = *maxChild;
        emptyPos = maxChild;
    }

    *emptyPos = moveItem;
}

template <typename T>
void makeHeap(T *const beginPtr, T *const endPtr) {
    assert(endPtr >= beginPtr);
    if ((endPtr - beginPtr) < 2) {
        return;
    }

    T *iter = beginPtr + (((endPtr - beginPtr) / 2) - 1);
    do {
        siftDown<T>(beginPtr, endPtr, iter - beginPtr);
        --iter;
    } while (iter >= beginPtr);
}

template <typename T>
void HeapSort(T *const beginPtr, T *endPtr) {
    assert(endPtr >= beginPtr);
    if ((endPtr - beginPtr) < 2) {
        return;
    }

    makeHeap(beginPtr, endPtr);
    do {
        endPtr -= 1;
        std::swap(*beginPtr, *endPtr);
        siftDown<T>(beginPtr, endPtr);
    } while ((endPtr - beginPtr) > 2);
    std::swap(*beginPtr, *(endPtr - 1));
}

template <typename T>
void HeapSort(T *const beginPtr, const size_t sortSize) {
    HeapSort(beginPtr, beginPtr + sortSize);
}

} // namespace algorithms

