#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void printVector(vector<pair<int,int>> &v){
    cout<<"[ ";
    for(auto el : v){
        cout << "( " << el.first << "," << el.second << " ) ";
    }
    cout<<"]";
    cout<<endl;
}

void printVector(vector<int> &v){
    cout<<"[ ";
    for(auto el : v){
        cout << el << " ";
    }
    cout<<"]";
    cout<<endl;
}

vector<pair<int, int>> bruteForceApproach(vector<int> &v){
    vector<pair<int,int>> subarrays;

    for(int i = 0; i < v.size(); i++){
        int sum = 0;
        int k = i;
        for(int j = i; j < v.size(); j++){
            sum += v[j];
            if(sum == 0){
                subarrays.emplace_back(k, j);
            }
        }
    }

    return subarrays;
}


vector<pair<int, int>> optimalApproach(vector<int> &v){
    vector<pair<int,int>> subarrays;
    unordered_map<int, vector<int>> map;
    int prefixSum = 0;

    for(int i = 0; i < v.size(); i++){
        prefixSum += v[i];

        if(prefixSum == 0){
            subarrays.emplace_back(0, i);
        }

        if(map.find(prefixSum) != map.end()){
            for(auto startIndex : map[prefixSum]){
                subarrays.emplace_back(startIndex + 1, i);
            }
        }

        if(map.find(prefixSum) == map.end()){
            map[prefixSum] = vector<int>();
        }

        map[prefixSum].push_back(i);
    }

    return subarrays;
}


int main(){

    vector<vector<int>> v = {
        vector<int>({1, 2, -3, 3, -1, 2}),
        vector<int>( {4, -1, -3, 1, 2, -1}),
        vector<int>({1, 2, 3, 4}),
        vector<int>({0, 0, 0}),
        vector<int>({-3, 1, 2, -3, 4, 0}),
        vector<int>({1, -1, 2, -2, 3, -3})
    };

    int testcaseNo = 1;
    cout << "BruteForce Approach \n";

    for(auto vec: v){

        cout << "testcase : " << testcaseNo << endl;
        printVector(vec);
        vector<pair<int,int>> ans = bruteForceApproach(vec);
        printVector(ans);

        cout<<"\n\n"<<endl;
        testcaseNo++;
    }

    cout<<"\n\n";
    testcaseNo = 1;

     cout << "Optimal Approach \n";

    for(auto vec: v){

        cout << "testcase : " << testcaseNo << endl;
        printVector(vec);
        vector<pair<int,int>> ans = optimalApproach(vec);
        printVector(ans);

        cout<<"\n\n"<<endl;
        testcaseNo++;
    }

    return 0;
}