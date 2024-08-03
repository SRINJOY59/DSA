#include<bits/stdc++.h>
using namespace std;

//only positive values
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int left = 0;
    int right = 0;
    long long sum = a[0];
    int maxLen = 0;
    int n = a.size();
    while(right < n){
        while(left <= right && sum > k){
            sum -= a[left];
            left += 1;
        }
        if(sum == k){
            maxLen = max(maxLen, right - left + 1);
        }
        right += 1;
        if(right < n){
            sum += a[right];
        }
    }
    return maxLen;
}

//both positive and negative values

int getLongestSubarray(vector<int>& nums, int k){
    // Write your code here
    map<int, int>prefixSumMap;
    int sum = 0;
    int maxLen = 0;
    prefixSumMap[0] = 1;
    for(int i = 0;i<nums.size();i++){
        sum += nums[i];
        if(sum == k){
            maxLen = max(maxLen, i+1);
        }
        int rem = sum - k;
        if(prefixSumMap.find(rem) != prefixSumMap.end()){
            maxLen = max(maxLen, i - prefixSumMap[rem]);
        }
        if(prefixSumMap.find(sum) == prefixSumMap.end())
            prefixSumMap[sum] = i;
    }
    return maxLen;    
}

