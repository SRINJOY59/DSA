#include <bits/stdc++.h>
using namespace std;
//the basic idea is to find the elements order from the strings and just then toposort
string findOrder(string dict[], int N, int K)
{
    // code here
    vector<int> adj[K];
    for (int i = 0; i < N - 1; i++)
    {
        string str1 = dict[i];
        string str2 = dict[i + 1];
        int minLength = min(str1.length(), str2.length());
        for (int i = 0; i < minLength; i++)
        {
            if (str1[i] != str2[i])
            {
                //str1[i] occurs before str2[i] in the dictionary so accordingly construct the graph
                adj[str1[i] - 'a'].push_back(str2[i] - 'a');
                break;
            }
        }
    }
    int V = K;
    vector<int> Indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            Indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < Indegree.size(); i++)
    {
        if (Indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<char> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node + 'a');
        for (auto it : adj[node])
        {
            Indegree[it]--;
            if (Indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    string ans = "";
    for (int i = 0; i < topo.size(); i++)
    {
        ans += topo[i];
    }
    return ans;
}