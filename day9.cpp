#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

string bruteForce(vector<string> &strs){
    if (strs.size() == 1) {
        return strs[0];
    }

    int maxCount = 0;
    string longestPrefix = "";

    for (int idx = 0; idx < strs.size(); idx++) {
        string word = strs[idx];
        if (word.empty()) continue;

        if (!longestPrefix.empty() && word.rfind(longestPrefix, 0) == 0) {
            continue;
        }

        for (int i = 0; i < word.size(); i++) {
            string prefix = word.substr(0, i + 1);
            int count = 0;

            for (int j = 0; j < strs.size(); j++) {
                if (j == idx || strs[j].empty()) continue;
                if (strs[j].rfind(prefix, 0) == 0) { 
                    count++;
                }
            }

            if (count != 0 && count >= maxCount) {
                maxCount = count;
                if (longestPrefix.size() < prefix.size()) {
                    longestPrefix = prefix;
                }
            }

            if (count == 0) {
                break;
            }
        }
    }

    if (maxCount != strs.size() - 1) {
        return "";
    }
    return longestPrefix;
}

string optimalApproach(vector<string> &strs){
    if (strs.empty()) return "";

    sort(strs.begin(), strs.end());

    if (strs[0].empty()) return "";

    string first = strs.front();
    string last = strs.back();

    string prefix = "";

    for (int i = 0; i < first.size() && i < last.size(); i++) {
        if (first[i] != last[i]) break;
        prefix.push_back(first[i]);
    }

    return prefix;
}


void printVector(vector<string> &v){
    cout<<"[ ";
    for(auto el : v){
        cout << el << " ";
    }
    cout<<"]";
    cout<<endl;
}

int main(){
     vector<vector<string>> v = {
       {"flower", "flow", "flight"},
        {"dog", "racecar", "car"},
        {"apple", "ape", "april"},
        {""},
        {"alone"}
    };


    int testcaseNo = 1;
    cout << "BruteForce Approach \n";

    for(auto vec: v){

        cout << "testcase : " << testcaseNo << endl;
        printVector(vec);
        cout << bruteForce(vec);
        cout<<"\n\n";
        testcaseNo++;
    }

    cout<<"\n\n";
    testcaseNo = 1;

     cout << "Optimal Approach \n";

    for(auto vec: v){

        cout << "testcase : " << testcaseNo << endl;
        printVector(vec);
        cout << optimalApproach(vec);
        cout<<"\n\n";
        testcaseNo++;
    }

    return 0;
}