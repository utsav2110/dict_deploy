#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

struct TrieNode {
    bool isEnd;
    unordered_map<char, TrieNode*> children;
    TrieNode() : isEnd(false) {}
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            char lower_ch = tolower(ch);
            if (!node->children.count(lower_ch)){
                node->children[lower_ch] = new TrieNode();
            }
            node = node->children[lower_ch];
        }
        node->isEnd = true;
    }

    void dfs(TrieNode* node, const string& prefix, vector<string>& result) {
        if (node->isEnd) {
            result.push_back(prefix);
        }
        for (auto& p : node->children) {
            dfs(p.second, prefix + p.first, result);
        }
    }

    vector<string> getSuggestions(const string& prefix, int limit = 10) {
        TrieNode* node = root;
        string lower_prefix;
        for (char ch : prefix) {
            char lower_ch = tolower(ch);
            if (!node->children.count(lower_ch)){
                return {};
            } 
            node = node->children[lower_ch];
            lower_prefix.push_back(lower_ch);
        }

        vector<string> result;
        dfs(node, lower_prefix, result);
        
        if (result.size() > limit) {
            result.resize(limit);
        }
        return result;
    }
};

// Utility to trim whitespace
string trim(const string& s) {
    size_t start = s.find_first_not_of(" \t\n\r");
    size_t end = s.find_last_not_of(" \t\n\r");
    if (start == string::npos || end == string::npos) return "";
    return s.substr(start, end - start + 1);
}

int main() {
    Trie trie;

    ifstream dict("words.txt");
    string word;
    while (getline(dict, word)) {
        word = trim(word);
        if (word.empty()) continue;
        trie.insert(word);
    }
    dict.close();

    ifstream input("input.txt");
    string prefix;
    getline(input, prefix);
    input.close();

    prefix = trim(prefix);

    vector<string> suggestions = trie.getSuggestions(prefix, 10);

    ofstream out("suggestions.txt");
    for (const auto& s : suggestions)
        out << s << '\n';
    out.close();

    return 0;
}