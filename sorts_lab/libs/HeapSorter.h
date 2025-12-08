//
// Created by Maksim Kuzin on 12/8/25.
//

#ifndef MIPT_C_LABS_HEAPSORTER_H
#define MIPT_C_LABS_HEAPSORTER_H


class HeapSorter {
public:
    HeapSorter() = default;

    void Sort(unsigned* arr, unsigned n);

private:
    void Heapify(unsigned* arr, unsigned n, unsigned i);  // просеивание вниз
};



#endif //MIPT_C_LABS_HEAPSORTER_H