//
//  Array.hpp
//  Array
//
//  Created by Evgeny on 14.04.16.
//  Copyright © 2016 Evgeny. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp

#include <stdio.h>

const int N = 100;
typedef int(*Comparer)(int, int);

class Array
{
public:
    Array(int = N);
    Array(int*, int);
    void RandomArray();
    void EnterArray(int* );
    void DisplayArray();
    int GetByIndex(int) const;
    void SetByIndex(int, int);
    int CompareTo(Array);
    bool Equals(Array);
    int GetSize() const;
    void QuickSort(int , int, Comparer);
    void BubbleSort(Comparer);
    void ChoiceSort(Comparer);
    void ShakerSort(Comparer);
    void QuickSort(Comparer);
    int BinSearch(int x);
    int FindMin();
    int FindMax();
    ~Array();
private:
    int* a;
    int size;
    void SetSize(int);
    int* AllocMemory(int);
    void Swap(int&, int&);
};
int AbsComparerIncrease(int , int );
int AbsComparerDecrease(int , int );
int ComparerIncrease(int , int );
int ComparerDecrease(int , int );
#endif /* Array_hpp */
