#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    vector<int>val(26, 0);
    vector<int>count(3, 0);
    int ans = 0;
    for(int i=0; i<str.size(); i++){
        if(val[str[i] - 'a'] == 0){
            if(count[0] < 9){
                val[str[i] - 'a'] = 1;
                ans += 1;
                count[0] += 1;
            }
            else if(count[1] < 9){
                val[str[i] - 'a'] = 2;
                count[1] += 1;
                ans += 2;
            }
            else if(count[2] < 9){
                val[str[i] - 'a'] = 3;
                count[2] += 1;
                ans += 3;
            }
        }
        else{
            ans += val[str[i] - 'a'];
        }
    }
    cout<<ans<<endl;
    return 0;
}