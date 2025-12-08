//
// Created by Maksim Kuzin on 12/8/25.
//

#include "HeapSorter.h"

void HeapSorter::Heapify(unsigned* arr, unsigned n, unsigned i) {
    unsigned largest = i;          // корень поддерева
    unsigned left = 2 * i + 1;     // левый ребёнок
    unsigned right = 2 * i + 2;    // правый ребёнок

    // если левый ребёнок больше корня
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // если правый ребёнок больше текущего максимума
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // если максимум не в корне — меняем и продолжаем просеивание
    if (largest != i) {
        unsigned t = arr[i];
        arr[i] = arr[largest];
        arr[largest] = t;

        // рекурсивно восстанавливаем свойство кучи
        Heapify(arr, n, largest);
    }
}

void HeapSorter::Sort(unsigned* arr, unsigned n) {
    if (n <= 1) return;

    // Шаг 1: строим max-heap
    // начинаем с последнего родителя: (n/2 - 1)
    for (int i = int(n / 2) - 1; i >= 0; i--) {
        Heapify(arr, n, unsigned(i));
    }

    // Шаг 2: по одному извлекаем максимум
    for (int i = int(n - 1); i > 0; i--) {
        // перемещаем корень (максимум) в конец
        unsigned t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;

        // восстанавливаем кучу на сокращённом массиве
        Heapify(arr, unsigned(i), 0);
    }
}
