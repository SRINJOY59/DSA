#include <bits/stdc++.h>
using namespace std;

int majorityElement(int a[], int size)
{

    // your code here
    int count = 0;
    int el;
    for (int i = 0; i < size; i++)
    {
        if (count == 0)
        {
            count = 1;
            el = a[i];
        }
        else if (a[i] == el)
        {
            count += 1;
        }
        else
        {
            count -= 1;
        }
    }
    count = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] == el)
            count += 1;
    }
    if (count > (size / 2))
    {
        return el;
    }
    return -1;
}

