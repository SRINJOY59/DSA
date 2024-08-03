#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[26];
    bool flag = false;
    int counts[26];
    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
            counts[i] = 0;
        }
    }
};

class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root = new Node();
        }
        void insert(string word){
            Node* node = root;
            for(int i = 0;i<word.length();i++){
                if(!node->links[word[i]-'a']){
                    node->links[word[i]-'a'] = new Node();
                }
                node = node->links[word[i]-'a'];
                node->counts[word[i]-'a'] += 1;
            }
            node->flag = true;
        }

        bool search(string word){
            Node* node = root;
            for(int i = 0;i<word.length();i++){
                
                if(!node->links[word[i]-'a']){
                    return false;
                }
                node = node->links[word[i]-'a'];
            }
            return node->flag;
        }
        bool startsWith(string word){
            Node* node = root;
            for(int i = 0;i<word.length();i++){
                if(!node->links[word[i]-'a']){
                    return false;
                }
                node = node->links[word[i] - 'a'];
            }
            return true;
        }
        int countWordsEqualTo(string word){
            Node* node = root;
            int ans = INT_MAX;
            for(int i = 0;i<word.size();i++){
                if(!node->links[word[i]-'a']){
                    return 0;
                }
                node = node->links[word[i]-'a'];
                ans = min(ans, node->counts[word[i]-'a']);
            }
            if(node->flag){
                return ans;
            }
            else{
                return 0;
            }
        }

        int countWordsStartingWith(string word){
            Node* node = root;
            int ans = INT_MAX;
            for(int i = 0;i<word.size();i++){
                if(!node->links[word[i]-'a']){
                    return 0;
                }
                node = node->links[word[i]-'a'];
                ans = min(ans,node->counts[word[i]-'a']);
            }
            return ans;
        }
        void Erase(string word){
            Node* node = root;
            for(int i = 0;i<word.size();i++){
                if(!node->links[word[i]-'a']){
                    return;
                }
                node = node->links[word[i]-'a'];
                node->counts[word[i]-'a'] -= 1;
            }
        }
       
};

int main() {
    Trie trie;
    cout << "Inserting words: Striver, Striving, String, Strike" << endl;
    trie.insert("striver");
    trie.insert("striving");
    trie.insert("string");
    trie.insert("strike");
    trie.insert("strike");
    trie.insert("strike");
    
    cout << "Search if Strawberry exists in trie: " <<
    (trie.search("strawberry") ? "True" : "False")<< endl;
    
    cout << "Search if Strike exists in trie: " <<
   ( trie.search("strike") ? "True" : "False" )<< endl;
    
    cout << "If words is Trie start with Stri: " <<
    (trie.startsWith("stri") ? "True" : "False" )<< endl;

    cout << "Count of words strike: " << trie.countWordsEqualTo("strike") << endl;

    cout << "Count of words stri: " << trie.countWordsStartingWith("stri") << endl;

    trie.Erase("strike");

    cout << "Count of words strike: " << trie.countWordsEqualTo("strike") << endl;
   

    return 0;
}