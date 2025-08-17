#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

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

int bruteForceApproach(vector<int> v)
{
    sort(v.begin(), v.end());
    int duplicateElement = -1;

    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] == v[i + 1])
        {
            duplicateElement = v[i];
            break;
        }
    }
    return duplicateElement;
}

int betterApproach(vector<int> &v)
{
    unordered_set<int> s;
    int duplicateElement = -1;

    for (auto el : v)
    {
        if (s.find(el) != s.end())
        {
            duplicateElement = el;
            break;
        }
        s.insert(el);
    }

    return duplicateElement;
}

int optimizedApproach(vector<int> &v)
{

    // Using Floyd's Cycle dectection algorithm
    // Finding the begining of the cycle which helps us in finding duplicate element as duplicate element point to a same index thus forming a cycle

    int slow = 0;
    int fast = 0;

    while (true)
    {
        slow = v[slow];
        fast = v[v[fast]];

        if (slow == fast)
        {
            break;
        }
    }

    int secondSlow = 0;

    while (true)
    {
        secondSlow = v[secondSlow];
        slow = v[slow];
        if (secondSlow == slow)
        {
            break;
        }
    }

    return slow;
}

int main()
{
    vector<vector<int>> v = {
        vector<int>({1, 3, 4, 2, 2}),
        vector<int>({3, 1, 3, 4, 2}),
        vector<int>({1, 1}),
        vector<int>({1, 4, 4, 2, 3})};

    int testcaseNo = 1;

    cout << "Brute Force approach : \n";

    for (auto vec : v)
    {

        cout << "testcase : " << testcaseNo << endl;
        printVector(vec);
        cout << bruteForceApproach(vec);

        cout << "\n\n"
             << endl;
        testcaseNo++;
    }

    cout << "\n\n";

    testcaseNo = 1;

    cout << "Better approach : \n";

    for (auto vec : v)
    {

        cout << "testcase : " << testcaseNo << endl;
        printVector(vec);
        cout << betterApproach(vec);

        cout << "\n\n"
             << endl;
        testcaseNo++;
    }

    cout << "\n\n";

    testcaseNo = 1;

    cout << "Optimized approach : \n";

    for (auto vec : v)
    {

        cout << "testcase : " << testcaseNo << endl;
        printVector(vec);
        cout << optimizedApproach(vec);

        cout << "\n\n"
             << endl;
        testcaseNo++;
    }
    return 0;
}