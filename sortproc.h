// header file for sort procs...
//
// Copyright (c) 1995-2020 by 'Bombastic Bob' Frazier
//
// This program and source provided for example purposes.  You may
// redistribute it so long as no modifications are made to any of
// the source files, and the above copyright notice has been
// included.  You may also use portions of the sample code in your
// own programs, as desired.
//

void InsertionSort();
void BubbleSort();
void HeapSort();
void HeapSort2();
void ExchangeSort();
void ShellSort();
void QuickSort();
void ThreadQuickSort();

#define SORT_FAST_SPEED 1000
#define SORT_SLOW_SPEED 10000

extern int iSwaps, iCompares, iSchedWork, iThreadCountMax, iTimeDelay;


