#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    if (s.length() == 1) 
        return false;

    stack<char> st;

    for (char c : s) {
        // if opening bracket → push
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } 
        // if closing bracket → check match
        else {
            if (!st.empty()) {
                char top = st.top();
                if ((c == ')' && top == '(') ||
                    (c == ']' && top == '[') ||
                    (c == '}' && top == '{')) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {
    cout << boolalpha;  
    cout << isValid("()[]{}") << endl;   
    cout << isValid("(]") << endl;       
    cout << isValid("([)]") << endl;     
    cout << isValid("{[]}") << endl;     
    cout << isValid("(") << endl;        
}
