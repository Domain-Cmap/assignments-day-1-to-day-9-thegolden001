#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> result;
        queue<vector<string>> q;
        q.push({beginWord});
        wordSet.erase(beginWord);
        bool found = false;
        while (!q.empty()) {
            int size = q.size();
            unordered_set<string> visited;
            for (int i = 0; i < size; i++) {
                vector<string> path = q.front();
                q.pop();
                string word = path.back();
                
                for (int j = 0; j < word.size(); j++) {
                    char original = word[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[j] = c;
                        if (word == endWord) {
                            path.push_back(word);
                            result.push_back(path);
                            found = true;
                        }
                        if (wordSet.find(word) != wordSet.end()) {
                            visited.insert(word);
                            vector<string> newPath = path;
                            newPath.push_back(word);
                            q.push(newPath);
                        }
                    }
                    word[j] = original;
                }
            }
            for (const string& w : visited) {
                wordSet.erase(w);
            }
            if (found) break;
        }
        return result;
    }
};
int main() {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> res = sol.findLadders(beginWord, endWord, wordList);
    
    for (auto& path : res) {
        for (const string& word : path) {
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}
