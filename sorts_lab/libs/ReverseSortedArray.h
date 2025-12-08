//
// Created by Maksim Kuzin on 12/8/25.
//

#ifndef MIPT_C_LABS_REVERSESORTEDARRAY_H
#define MIPT_C_LABS_REVERSESORTEDARRAY_H


class ReverseSortedArray {
public:
    ReverseSortedArray() = default;

    // Заполняет массив длиной n числами n-1, n-2, ..., 0
    void Fill(unsigned* arr, unsigned n);
};


#endif //MIPT_C_LABS_REVERSESORTEDARRAY_H