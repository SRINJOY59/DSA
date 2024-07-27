#include <bits/stdc++.h>
using namespace std;


int check(vector<int> &stations, int k, double dist)
{
    int cnt = 0;
    double start = stations[0];
    for (int i = 1; i < stations.size(); i++)
    {
        int possible = (stations[i] - stations[i - 1]) / dist;
        if ((double)(stations[i] - stations[i - 1]) == (dist * possible))
        {
            possible--;
        }
        cnt += possible;
    }
    return cnt;
}



double findSmallestMaxDist(vector<int> &stations, int k)
{
    // Code here
    double start = 0;
    double end = 0;
    for (int i = 1; i < stations.size(); i++)
    {
        double dist = stations[i] - stations[i - 1];
        end = max(end, dist);
    }
    double ans = end;
    double diff = 1e-6;
    while (end - start > diff)
    {
        double mid = (start + end) / 2.0;
        int num = check(stations, k, mid);
        if (num > k)
        {
            start = mid;
        }
        else
        {
            end = mid;
        }
    }
    return end;
}