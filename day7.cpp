#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trappedRainWater(vector<int> &v)
{
    int trappedWater = 0;

    int i = 0;
    int j = v.size() - 1;

    int leftMax = v[i];
    int rightMax = v[j];

    while (i < j)
    {

        if (leftMax <= rightMax)
        {
            i++;
            leftMax = max(leftMax, v[i]);
            trappedWater += leftMax - v[i];
        }
        else
        {
            j--;
            rightMax = max(rightMax, v[j]);
            trappedWater += rightMax - v[j];
        }
    }

    return trappedWater;
}

void printVector(vector<int> &v)
{
    cout << "[ ";
    for (auto el : v)
    {
        cout << el << " ";
    }
    cout << "]";
    cout << endl;
}

int main()
{
    vector<vector<int>> v = {
        vector<int>({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}),
        vector<int>( {4, 2, 0, 3, 2, 5}),
        vector<int>({1, 1, 1}),
        vector<int>({5}),
        vector<int>({2, 0, 2})
    };

    int testcaseNo = 1;

    for(auto vec: v){

        cout << "testcase : " << testcaseNo << endl;
        printVector(vec);
        cout << trappedRainWater(vec);
        cout<<"\n\n"<<endl;
        testcaseNo++;
    }

    cout<<"\n\n";

    return 0;
}