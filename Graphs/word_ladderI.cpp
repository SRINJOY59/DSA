#include <bits/stdc++.h>
using namespace std;
int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
{
    set<string> s(wordList.begin(), wordList.end());
    if (s.find(targetWord) == s.end())
    {
        return 0;
    }

    queue<pair<string, int>> q;
    q.push({startWord, 1});
    s.erase(startWord);

    while (!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (word == targetWord)
        {
            return steps;
        }

        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                if (ch == original)
                    continue;

                word[i] = ch;
                if (s.find(word) != s.end())
                {
                    s.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
}