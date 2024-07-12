#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    if (n == 1) {
        int single_house;
        cin >> single_house;
        cout << single_house << endl;
        return 0;
    }

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if (n == 2) {
        cout << max(nums[0], nums[1]) << endl;
        return 0;
    }

    vector<int> dp1(n, 0);  // Case 1: Rob houses 0 to n-2
    vector<int> dp2(n, 0);  // Case 2: Rob houses 1 to n-1

    dp1[0] = nums[0];
    dp1[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n - 1; i++) {
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
    }

    dp2[1] = nums[1];
    dp2[2] = max(nums[1], nums[2]);
    for (int i = 3; i < n; i++) {
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
    }

    int ans = max(dp1[n - 2], dp2[n - 1]);
    cout << ans << endl;

    return 0;
}
