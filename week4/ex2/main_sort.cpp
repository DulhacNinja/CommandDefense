#include "Sort.h"

int main()
{
    Sort sir1 = { 5, 4, 20 };
    sir1.Print();
    int vect[] = { 11, 235, 78, 56, 22, 17 };
    int nr = 6;
    Sort sir2 = { nr, vect };
    sir2.Print();
    Sort sir3 = sir2;
    sir3.Print();
    Sort sir4 = { 7, 77, 7777, 34, 42, 98, 100, 122 };
    sir4.Print();
    Sort sir5 = { "8,6,45,2,7,888,345,1,80" };
    sir5.Print();
    sir1.BubbleSort(1);
    sir1.Print();
    sir2.InsertSort(1);
    sir2.Print();
    sir4.QuickSort(0, 6, 1);
    sir4.Print();
    cout << "sir1.v[1]=" << sir5.GetElementFromIndex(1) << "\n";
    cout << "sir2.nrValues=" << sir4.GetElementsCount() << "\n";
    return 0;
}