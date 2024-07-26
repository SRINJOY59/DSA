#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>time(n);

    for(int i=0;i<n;i++){
        cin>>time[i];
    }
    vector<int>direction(n);

    for(int i=0;i<n;i++){
        cin>>direction[i];
    }

    queue<int>entry;
    queue<int>exit;

    for(int i = 0;i<direction.size();i++){
        if(direction[i] == 1){
            exit.push(i);
        }
        else{
            entry.push(i);
        }
    }
    int currentTime = 0;
    int lastUsedDirection = -1;
    vector<int>result;
    while (!entry.empty() || !exit.empty()) {

        while (!entry.empty() && time[entry.front()] > currentTime) {
            entry.pop();
        }
        while (!exit.empty() && time[exit.front()] > currentTime) {
            exit.pop(); 
        }
        

        bool exitHasPriority = false;
        if (lastUsedDirection == -1 || lastUsedDirection == 1) {
            exitHasPriority = true;
        } else {
            exitHasPriority = false;
        }

        if (exitHasPriority) {
            if (!exit.empty() && time[exit.front()] <= currentTime) {
                int personIndex = exit.front();
                exit.pop();
                result[personIndex] = currentTime;
                lastUsedDirection = 1;
            } else if (!entry.empty() && time[entry.front()] <= currentTime) {
                int personIndex = entry.front();
                entry.pop();
                result[personIndex] = currentTime;
                lastUsedDirection = 0;
            }
        } else { 
            if (!entry.empty() && time[entry.front()] <= currentTime) {
                int personIndex = entry.front();
                entry.pop();
                result[personIndex] = currentTime;
                lastUsedDirection = 0;
            } else if (!exit.empty() && time[exit.front()] <= currentTime) {
                int personIndex = exit.front();
                exit.pop();
                result[personIndex] = currentTime;
                lastUsedDirection = 1;
            }
        }
        
        currentTime++;
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout<<endl;
    return 0;

}