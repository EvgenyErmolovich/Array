//
//  Array.cpp
//  Array
//
//  Created by Evgeny on 14.04.16.
//  Copyright © 2016 Evgeny. All rights reserved.
//

#include "Array.hpp"
#include<iostream>

using namespace std;

Array:: Array(int n)
{
    SetSize(n);
    a = AllocMemory(size);
}
Array:: Array(int* x, int n)
{
    SetSize(n);
    a = new int[n];
    for (int i = 0; i < size; i++)
    {
        a[i] = x[i];
    }
}
void Array:: RandomArray()
{
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % N;
    }
}
void Array::EnterArray(int* x)
{
    cout << "Enter the elements of an array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "[" << (i + 1) << "] = ";
        cin >> x[i];
        a[i] = x[i];
    }
}
void Array:: BubbleSort(Comparer comparer)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = size - 1; j >= i; j--)
        {
            if (comparer(a[j], a[j - 1]) < 0)
            {
                Swap(a[j], a[j - 1]);
            }
        }
    }
}
void Array:: ChoiceSort(Comparer comparer)
{
    for (int i = 1; i <= size - 1; i++)
    {
        int max = i - 1;
        for (int j = i - 1; j <= size - 1 ; j++)
            if (comparer(a[j],a[max]) < 0)
                max = j;
        Swap(a[i - 1], a[max]);
    }
}
void Array:: ShakerSort(Comparer comparer)
{
    int previous = 1;
    int next = size - 1;
    while (previous <= next)
    {
        for (int i = next; i >= previous; i--)
            if (comparer(a[i - 1],a[i]) > 0) Swap(a[i], a[i-1]);
        previous++;
        for (int i = previous; i <= next; i++)
            if (comparer(a[i - 1],a[i]) > 0) Swap(a[i], a[i - 1]);
        next--;
    }
}
void Array:: QuickSort(int left, int right, Comparer comparer)
{
    int i = left, j = right;
    int middle = a[(left + right) / 2];
    while (i <= j)
    {
        while (comparer(a[i], middle) < 0)
            i++;
        while (comparer(a[j], middle) > 0)
            j--;
        if (i <= j)
        {
            Swap (a[i], a[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        QuickSort(left, j, comparer);
    if (i < right)
        QuickSort(i, right, comparer);
}
void Array:: QuickSort(Comparer comparer)
{
    QuickSort (0, size - 1, comparer);
}
int Array:: GetByIndex(int i) const
{
    if (i < 0 || i >= size)
    {
        cout << "out of range!" << endl;
        return 0;
    }
    return a[i];
}
void Array:: SetByIndex(int i, int value)
{
    if (i < 0 || i >= size)
    {
        cout << "out of range!" << endl;
        return;
    }
    a[i] = value;
}
int Array:: CompareTo (Array other)
{
    if (GetSize() > other.GetSize())
        return 1;
    else //if (GetSize() < other.GetSize())
        return -1;
}
int Array:: GetSize() const
{
    return size;
}
int Array:: FindMin()
{
    int min = a[0];
    int j = 0;
    for (int i = 0; i < size; i++)
        if (a[i] < min)
        {
            min = a[i];
            j = i;
        }
    return j;
}
int Array:: FindMax()
{
    int max = a[0];
    int j = 0;
    for (int i = 0; i < size; i++)
        if (a[i] > max)
        {
            max = a[i];
            j = i;
        }
    return j;
}
void Array:: DisplayArray()
{
    for (int i = 0; i < size; i++)
    {
        cout << " " <<  a[i];
    }
    cout << endl;
}
Array:: ~Array()
{
    delete[] a;
}
void Array:: SetSize(int n)
{
    if (n <= 0) size = N;
    else size = n;
}
int* Array:: AllocMemory(int n)
{
    int* a = new int[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
    return a;
}
int Array:: BinSearch(int x)
{
    QuickSort(ComparerIncrease);
    int low, high, mid;
    low = 0;
    high = size;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(x < a[mid])
            high = mid - 1;
        else if(x > a[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
void Array:: Swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
bool Array :: Equals(Array other)
{
    if (GetSize() == other.GetSize())
        return true;
    return false;
}
int AbsComparerIncrease(int a, int b)
{
    return abs(a) - abs(b);
}
int AbsComparerDecrease(int a, int b)
{
    return abs(b) - abs(a);
}
int ComparerIncrease(int a, int b)
{
    return a-b;
}
int ComparerDecrease(int a, int b)
{
    return b-a;
}