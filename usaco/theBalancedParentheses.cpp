#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
stack<char> st;

void no() {
    printf("NO\n");
    exit(0);
}

int main() {
    cin >> s;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        } else if(s[i] == '}') {
            if(st.top() != '{') no();
            else st.pop();
        } else if(s[i] == ']') {
            if(st.top() != '[') no();
            else st.pop(); 
        } else if(s[i] == ')') {
            if(st.top() != '(') no();
            else st.pop();
        }
    }

    if(st.empty()) printf("YES\n");
    else no();

    return 0;
}