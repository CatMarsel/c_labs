//
// Created by Maksim Kuzin on 12/8/25.
//

#include "HoareSorter.h"

void HoareSorter::Sort(unsigned* arr, unsigned n) {
    if (n > 1)
        QuickSort(arr, 0, int(n - 1));
}

// Основной рекурсивный алгоритм
void HoareSorter::QuickSort(unsigned* arr, int left, int right) {
    if (left >= right)
        return;

    int pivotIndex = Partition(arr, left, right);

    QuickSort(arr, left, pivotIndex);
    QuickSort(arr, pivotIndex + 1, right);
}

// Разбиение Хоара
int HoareSorter::Partition(unsigned* arr, int left, int right) {
    unsigned pivot = arr[(left + right) / 2]; // опорный элемент — середина

    int i = left - 1;
    int j = right + 1;

    while (true) {
        // двигаем левый индекс вправо, пока элементы меньше опорного
        do {
            i++;
        } while (arr[i] < pivot);

        // двигаем правый индекс влево, пока элементы больше опорного
        do {
            j--;
        } while (arr[j] > pivot);

        // если указатели встретились — возвращаем точку разделения
        if (i >= j)
            return j;

        // иначе — меняем местами
        unsigned t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}
