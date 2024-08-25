// C++ linear time solution for stock span problem
#include <bits/stdc++.h>
using namespace std;


void calculateSpan(int price[], int n, int S[])
{

    stack<int> st;
    st.push(0);

    S[0] = 1;

    for (int i = 1; i < n; i++) {

        while (!st.empty() && price[st.top()] <= price[i])
            st.pop();

        S[i] = (st.empty()) ? (i + 1) : (i - st.top());

        st.push(i);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int price[] = {58, 19, 46, 22, 80, 12, 65, 24, 60, 92};
    int n = sizeof(price) / sizeof(price[0]);
    int S[n];

    calculateSpan(price, n, S);

    printArray(S, n);

    return 0;
}
