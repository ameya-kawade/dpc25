#include<iostream>
#include<vector>

using namespace std;

void sortArray(vector<int> &arr){
    int length = arr.size();

    if(length == 0){
        return;
    }

    int low = 0;
    int mid = 0;
    int high = length - 1;

    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    
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
        vector<int>({0, 1, 2, 1, 0, 2, 1, 0}),
        vector<int>( {2, 2, 2, 2}),
        vector<int>({0, 0, 0, 0}),
        vector<int>({1, 1, 1, 1}),
        vector<int>({2, 0, 1}),
        vector<int>()
    };

    int testcaseNo = 1;

    for(auto vec: v){
        cout << "testcase : " << testcaseNo << endl;
        printVector(vec);
        sortArray(vec);
        printVector(vec);
        cout<<"\n\n"<<endl;

        testcaseNo++;
    }
    return 0;
}