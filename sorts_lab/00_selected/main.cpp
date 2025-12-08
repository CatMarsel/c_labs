//
// Created by Maksim Kuzin on 12/8/25.
//

//
// Created by Maksim Kuzin on 12/8/25.
//

#include <fstream>
#include <iostream>
#include "RandomArray.h"
#include "SelectionSorter.h"
#include  "Timer.h"
#define SIZEMAX 1000000

using namespace std;
ofstream file("/Users/maksimkuzin/Documents/МФТИ/1_семестр/информатика/mipt-c-labs/00_selected_2.csv");

int main() {
    if (!file.is_open()) {
        cout << "file NOT opened!\n";
    }

    Timer t;
    RandomArray ar;
    SelectionSorter sorter;

    unsigned array[SIZEMAX];
    for (unsigned n = 100; n < SIZEMAX; n=n+100)
    {
        cout<<n<<'\n'<<flush;
        ar.Fill(array, n);
        t.GetTime();
        sorter.Sort(array, n);
        file << n << '\t' << t.GetTime() << '\n' << flush;


    }

    return 0;

}