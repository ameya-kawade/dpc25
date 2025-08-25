#include <bits/stdc++.h>
using namespace std;

vector<string> permuteUnique(string s) {
    vector<string> result;
    sort(s.begin(), s.end());
    do {
        result.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    return result;
}

int main() {
    vector<string> result1 = permuteUnique("abc");
    for (auto &str : result1) cout << str << " ";
    cout << "\n";

    vector<string> result2 = permuteUnique("aab");
    for (auto &str : result2) cout << str << " ";
    cout << "\n";

    vector<string> result3 = permuteUnique("aaa");
    for (auto &str : result3) cout << str << " ";
    cout << "\n";

    return 0;
}
