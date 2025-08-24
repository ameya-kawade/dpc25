#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <array>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{

    unordered_map<string, vector<string>> map;

    for (auto s : strs)
    {
        array<int, 26> count = {0};

        for (auto ch : s)
        {
            count[ch - 'a']++;
        }

        string key;

        for (auto c : count)
        {
            key += to_string(c) + "#";
        }

        map[key].push_back(s);
    }

    vector<vector<string>> ans;

    for (auto key : map)
    {
        ans.push_back(key.second);
    }

    return ans;
}

void printVector(vector<string> &v)
{
    cout << "[ ";
    for (auto el : v)
    {
        cout << el << " ";
    }
    cout << "]";
    cout << endl;
}

void printVector(vector<vector<string>> &v)
{
    cout << "[ ";
    for (auto vec : v)
    {
        cout << "[ ";
        for (auto el : vec)
        {
            cout << el << " ";
        }
        cout << "] ";
    }
    cout << "]" << endl;
}

int main()
{
    vector<vector<string>> v = {
        vector<string>({"eat", "tea", "tan", "ate", "nat", "bat"}),
        vector<string>({""}),
        vector<string>({"a"}),
        vector<string>({"abc", "bca", "cab", "xyz", "zyx", "yxz"}),
        vector<string>({"abc", "def", "ghi"})};


    int testcaseNo = 1;
  
    for(auto vec: v){

        cout << "testcase : " << testcaseNo << endl;
        printVector(vec);
        vector<vector<string>> ans = groupAnagrams(vec);
        printVector(ans);

        cout<<"\n\n"<<endl;
        testcaseNo++;
    }
    return 0;
}