//
// Created by Maksim Kuzin on 12/8/25.
//

#ifndef MIPT_C_LABS_HOARESORTER_H
#define MIPT_C_LABS_HOARESORTER_H


class HoareSorter {
public:
    HoareSorter() = default;

    void Sort(unsigned* arr, unsigned n);

private:
    void QuickSort(unsigned* arr, int left, int right);
    int Partition(unsigned* arr, int left, int right);
};


#endif //MIPT_C_LABS_HOARESORTER_H