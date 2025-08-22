#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;



string reverseWords(string s) {
    
    reverse(s.begin(), s.end());

    string ans = "";
    int n = s.size();
    int i = 0;

    while (i < n) {
        string word = "";

        
        while (i < n && s[i] != ' ') {
            word += s[i];
            i++;
        }

       
        reverse(word.begin(), word.end());

        
        if (!word.empty()) {
            ans += " " + word;
        }

        i++;
    }

    if(ans.empty()){
        return "";
    }

    return ans.substr(1);
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
     vector<string> v = {
        "the sky is blue",
        " hello world ",
        "a good example",
        "word",
        ""
    };

    int testcaseNo = 1;
    
    for(auto s: v){

        cout << "testcase : " << testcaseNo << endl;
        cout <<"\"" << s << "\"" << endl;
        cout << reverseWords(s);

        cout<<"\n\n"<<endl;
        testcaseNo++;
    }
    return 0;
}