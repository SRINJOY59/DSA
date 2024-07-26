#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll q;
    cin >> q;

    vector<string> queries(q);
    cin.ignore(); 

    for(int i = 0; i < q; i++) {
        getline(cin, queries[i]);
    }
    
    ll time_to_live;
    cin >> time_to_live;

    map<string, ll> tokenExp;
    vector<ll> final;
    

    for (const string& query : queries) {
        istringstream iss(query);
        string action, token_id;
        ll current_time;

        iss >> action;

        if (action == "generate") {
            iss >> token_id >> current_time;
            tokenExp[token_id] = current_time + time_to_live;
        } else if (action == "renew") {
            iss >> token_id >> current_time;
            if (tokenExp.count(token_id) && tokenExp[token_id] > current_time) {
                tokenExp[token_id] = current_time + time_to_live;
            }
        } else if (action == "count") {
            iss >> current_time;
            ll count = 0;
            for (const auto& it : tokenExp) {
                ll expiry = it.second;
                if (expiry > current_time) {
                    count++;
                }
            }
            final.push_back(count);
        }
    }

    for (ll count : final) {
        cout << count << endl;
    }

    return 0;
}
