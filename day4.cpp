#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void printVector(vector<int> &v){
    cout<<"[ ";
    for(auto el : v){
        cout << el << " ";
    }
    cout<<"]";
    cout<<endl;
}


void bruteForceApproach(vector<int> &v1, vector<int> &v2){
    if(v1[0] > v2[0]){
        swap(v1, v2);
    }

    while(true){
        bool isDone = true;

        int i = 0;
        int j = 0;

        while(i < v1.size() && j < v2.size()){
            if(v1[i] <= v2[j]){
                i++;
            }
            else{
                swap(v1[i], v2[j]);
                isDone = false;
            }
        }

        if(isDone) break;

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
    }
}

int nextGap(int gap) {
    if (gap <= 1) return 0;
    return (gap / 2) + (gap % 2);
}

void optimalApproach(vector<int> &v1, vector<int> &v2){
    // Using gap method (similar to shell sort)
    int m = v1.size();
    int n = v2.size();
    int gap = nextGap(m + n);

    while (gap > 0) {
        int i, j;

        // Case 1: Compare elements in v1 itself
        for (i = 0; i + gap < m; i++) {
            if (v1[i] > v1[i + gap]) {
                swap(v1[i], v1[i + gap]);
            }
        }

        // Case 2: Compare elements between v1 and v2
        for (j = (gap > m) ? (gap - m) : 0; i < m && j < n; i++, j++) {
            if (v1[i] > v2[j]) {
                swap(v1[i], v2[j]);
            }
        }

        // Case 3: Compare elements in v2 itself
        if (j < n) {
            for (j = 0; j + gap < n; j++) {
                if (v2[j] > v2[j + gap]) {
                    swap(v2[j], v2[j + gap]);
                }
            }
        }

        gap = nextGap(gap);
    }
}

int main(){
    vector<vector<vector<int>>> v = {
        vector<vector<int>>({{1, 3, 5, 7},{2, 4, 6, 8}}),
        vector<vector<int>>({{1, 3, 5},{2, 4, 6}}),
        vector<vector<int>>({{10, 12, 14},{1, 3, 5}}),
        vector<vector<int>>({{2, 3, 8},{4, 6, 10}}),
        vector<vector<int>>({{1},{2}})
    };

    int testcaseNo = 1;

    cout << "Brute Force approach : \n";

    for (auto vec : v)
    {

        cout << "testcase : " << testcaseNo << endl;
        printVector(vec[0]);
        printVector(vec[1]);
        
        bruteForceApproach(vec[0], vec[1]);

        cout<<"after merging\n\n";
        printVector(vec[0]);
        printVector(vec[1]);

        cout << "\n\n"
             << endl;
        testcaseNo++;
    }

    cout << "\n\n";

    testcaseNo=1;

    cout << "Optimal approach : \n";

    for (auto vec : v)
    {

        cout << "testcase : " << testcaseNo << endl;
        printVector(vec[0]);
        printVector(vec[1]);
        
        optimalApproach(vec[0], vec[1]);

        cout<<"after merging\n\n";
        printVector(vec[0]);
        printVector(vec[1]);

        cout << "\n\n"
             << endl;
        testcaseNo++;
    }

    cout << "\n\n";

    return 0;
}