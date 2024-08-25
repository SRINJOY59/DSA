#include<bits/stdc++.h>
using namespace std;


int nthUglyNumber(int n) {

    int p2 = 0, p3 = 0, p5 = 0;

    vector<int> ugly(n);

    ugly[0] = 1;

    for(int i = 1; i < n; i++) {

        ugly[i] = min(ugly[p2] * 2, min(ugly[p3] * 3, ugly[p5] * 5));

        if(ugly[i] == ugly[p2] * 2) p2++;

        if(ugly[i] == ugly[p3] * 3) p3++;

        if(ugly[i] == ugly[p5] * 5) p5++;

    }

    return ugly[n - 1];
    
}