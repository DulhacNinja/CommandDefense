#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <stdlib.h>
#include <cstdarg>

void Sort::InsertSort(bool ascendent)
{
    for (int i = 1; i < nrValues; i++)
    {
        int temp = vector[i], j = i - 1;
        if (ascendent)
        {
            while (j >= 0 && temp < vector[j])
                vector[j + 1] = vector[j], j--;
            vector[j + 1] = temp;
        }
        else
        {
            while (j >= 0 && temp > vector[j])
                vector[j + 1] = vector[j], j--;
            vector[j + 1] = temp;
        }
    }
}

int Pivot(int* vector, int st, int dr, bool ascendent)
{
    int i, j, di, dj;
    i  = st;
    j  = dr;
    di = 0;
    dj = 1;
    while (i < j)
    {
        if (ascendent)
        {
            if (vector[i] > vector[j])
            {
                vector[i] += vector[j];
                vector[j] = vector[i] - vector[j];
                vector[i] -= vector[j];
                di += dj;
                dj = di - dj;
                di -= dj;
            }
            i += di;
            j -= dj;
        }
        else
        {
            if (vector[i] < vector[j])
            {
                vector[i] += vector[j];
                vector[j] = vector[i] - vector[j];
                vector[i] -= vector[j];
                di += dj;
                dj = di - dj;
                di -= dj;
            }
            i += di;
            j -= dj;
        }
    }
    return i;
}

void Sort::QuickSort(int st, int dr, bool ascendent)
{
    int p;
    if (st <= dr)
    {
        p = Pivot(this->vector, st, dr, ascendent);
        QuickSort(st, p - 1, ascendent);
        QuickSort(p + 1, dr, ascendent);
    }
}

void Sort::BubbleSort(bool ascendent)
{
    bool sortat;
    do {
        sortat = true;
        for (int i = 0; i < nrValues - 1; i++)
            if (vector[i] > vector[i + 1])
            {
                vector[i] += vector[i + 1];
                vector[i + 1] = vector[i] - vector[i + 1];
                vector[i] -= vector[i + 1];
                sortat = false;
            }
    } while (!sortat);
}

void Sort::Print()
{
    for (int i = 0; i < nrValues; i++)
        cout << vector[i] << ' ';
    cout << '\n';
}

int Sort::GetElementFromIndex(int index)
{
    if (index > -1 && index < nrValues)
        return vector[index];
    return -1;
}

int Sort::GetElementsCount()
{
    return nrValues;
}

Sort::Sort(int nrValues, int min, int max)
{
    this->nrValues = nrValues;
    this->vector        = new int[this->nrValues];
    for (int i = 0; i < this->nrValues; i++)
        vector[i] = rand() % (max - min) + min;
}

Sort::Sort(const Sort& other) : Sort(other.nrValues, other.vector) { }

Sort::Sort(int nrValues, int* vectorect)
{
    this->nrValues = nrValues;
    this->vector        = new int[this->nrValues];
    for (int i = 0; i < this->nrValues; i++)
        this->vector[i] = vectorect[i];
}

 Sort::Sort(int count, ...)
{
    this->nrValues = count;
    this->vector        = new int[this->nrValues];
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i)
        this->vector[i] = va_arg(args, int);
    va_end(args);
}

Sort::Sort(const char* sir)
{
    char* s = new char[strlen(sir) + 1];
    strcpy(s, sir);
    int number = 0;
    for (int i = 0; s[i]; i++)
        if (s[i] == ',')
            number++;
    this->nrValues = number + 1;
    this->vector        = new int[this->nrValues];
    char* p        = strtok(s, ",");
    number         = 0;
    while (p)
    {
        int id = 0;
        for (int i = 0; p[i]; i++)
            id = id * 10 + p[i] - '0';
        this->vector[number++] = id;
        p = strtok(NULL, ",");
    }
}
