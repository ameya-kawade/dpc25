#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;


vector<int> bruteForceApproach(vector<int> &v){
    vector<int> leaders;
    unordered_set<int> set;

    for(int i = 0; i < v.size(); i++){
        bool isLeader = true;
        for(int j = i + 1; j < v.size(); j++){
            if(v[j] > v[i]){
                isLeader = false;
                break;
            }
        }

        if(isLeader && set.find(v[i]) == set.end()){
            leaders.push_back(v[i]);
            set.insert(v[i]);
        }
    }

    return leaders;
}

vector<int> optimalApproach(vector<int> &v){
    vector<int> leaders;
    unordered_set<int> set;
    int maxElement = 0;

    for(int i = v.size() - 1; i >= 0; i--){

        if(v[i] >= maxElement){
            
            maxElement = v[i];

            if(set.find(v[i]) == set.end()){
                leaders.push_back(v[i]);
                set.insert(v[i]);
            }

        }   
        
    }

    reverse(leaders.begin(), leaders.end());    

    return leaders; 
}

void printVector(vector<int> &v){
    cout<<"[ ";
    for(auto el : v){
        cout << el << " ";
    }
    cout<<"]";
    cout<<endl;
}

int main(){

    vector<vector<int>> v = {
        vector<int>({16, 17, 4, 3, 5, 2}),
        vector<int>( {1, 2, 3, 4, 0}),
        vector<int>({7, 10, 4, 10, 6, 5, 2}),
        vector<int>({5}),
        vector<int>({100, 50, 20, 10})
    };



    int testcaseNo = 1;
    cout << "BruteForce Approach \n";

    for(auto vec: v){

        cout << "testcase : " << testcaseNo << endl;
        printVector(vec);
        vector<int> leaders = bruteForceApproach(vec);
        printVector(leaders);

        cout<<"\n\n"<<endl;
        testcaseNo++;
    }

    cout<<"\n\n";

    testcaseNo = 1;

    cout << "Optimal Approach \n";

    for(auto vec: v){

        cout << "testcase : " << testcaseNo << endl;
        printVector(vec);
        vector<int> leaders = optimalApproach(vec);
        printVector(leaders);

        cout<<"\n"<<endl;
        testcaseNo++;
    }

    return 0;
}