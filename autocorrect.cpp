#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int editDistance(const string& a, const string& b) {
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = (a[i - 1] == b[j - 1]) ? dp[i - 1][j - 1] : 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }
    }

    return dp[n][m];
}

int main() {
    ifstream dict("words.txt");
    ifstream input("input.txt");
    ofstream out("suggestions.txt");

    string query;
    getline(input, query);
    input.close();

    string word;
    vector<pair<string, int>> candidates;

    while (getline(dict, word)) {
        int dist = editDistance(query, word);
        candidates.push_back({word, dist});
    }

    sort(candidates.begin(), candidates.end(), [](auto& a, auto& b) {
        return a.second < b.second;
    });

    for (int i = 0; i < min(10, (int)candidates.size()); i++) {
        out << candidates[i].first << '\n';
    }

    dict.close();
    out.close();
    return 0;
}