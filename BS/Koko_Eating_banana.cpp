#include <bits/stdc++.h>
using namespace std;

bool check(int N, vector<int> &piles, int H, int R)
{
    long long hr = 0;
    for (int i = 0; i < N; i++)
    {
        if (piles[i] % R == 0)
        {
            hr += (piles[i] / R);
        }
        else
        {
            hr += (piles[i] / R) + 1;
        }
        if (hr > H)
        {
            return false;
        }
    }
    if (hr > H)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int Solve(int N, vector<int> &piles, int H)
{
    int start = 1;
    int end = 1e9;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (check(N, piles, H, mid))
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return mid;
}