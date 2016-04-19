//
//  main.cpp
//  Array
//
//  Created by Evgeny on 14.04.16.
//  Copyright © 2016 Evgeny. All rights reserved.
//

#include<iostream>
#include "Array.hpp"

using namespace std;

int main()
{
    Array arr(10);
    arr.RandomArray();
    arr.DisplayArray();
    cout << arr.FindMax()<< endl;
    cout << arr.FindMin()<< endl;
    cout << arr.BinSearch(49);
    return 0;
}