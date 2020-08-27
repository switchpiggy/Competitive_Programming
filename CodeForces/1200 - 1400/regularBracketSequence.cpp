#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
stack<char> st;
ll cnt = 0, ans = 0;

int main() {
    cin >> s;
    for(ll i = 0; i < s.length(); ++i) {
        if(s[i] == '(') st.push('(');
        else {
            if(!st.empty()) {   
                st.pop();
                ans++;
            } 
        }
    }

    printf("%lld\n", ans * 2);
    return 0;
}