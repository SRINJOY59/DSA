#include <bits/stdc++.h>
using namespace std;

long long lcm(long long a, long long b)
{
    return (a / __gcd(a, b)) * b;
}

long long lcm_of_three(long long a, long long b, long long c)
{
    return lcm(lcm(a, b), c);
}
int nthUglyNumber(int n, int a, int b, int c)
{
    long long mini = 1;
    long long maxi = n * min({a, b, c});
    long long ans = -1;

    while (mini <= maxi)
    {
        long long mid = mini + (maxi - mini) / 2;

        long long count = mid / a + mid / b + mid / c - mid / lcm(a, b) - mid / lcm(b, c) - mid / lcm(a, c) + mid / lcm_of_three(a, b, c);

        if (count < n)
        {
            mini = mid + 1;
        }
        else
        {
            ans = mid;
            maxi = mid - 1;
        }
    }

    return (int)ans;
}