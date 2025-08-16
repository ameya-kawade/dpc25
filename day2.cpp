#include<iostream>
#include<vector>

using namespace std;

int findMissingNumber(vector<int> &v){
    int n = v.size() + 1;
    int totalSum = ( n * (n + 1) ) / 2;
    int actualSum = 0;

    for(auto el: v){
        actualSum += el;
    }

    int missingElement = totalSum - actualSum;

    return missingElement;
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
        vector<int>({1, 2, 4, 5}),
        vector<int>( {2, 3, 4, 5}),
        vector<int>({1, 2, 3, 4}),
        vector<int>({1}),
        vector<int>({1, 2, 3, 5, 6, 7, 8, 9, 10})
    };



    int testcaseNo = 1;

    for(auto vec: v){

        cout << "testcase : " << testcaseNo << endl;
        printVector(vec);
        cout << findMissingNumber(vec);

        cout<<"\n\n"<<endl;
        testcaseNo++;
    }

    return 0;
}