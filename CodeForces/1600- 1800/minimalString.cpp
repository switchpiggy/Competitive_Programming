#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string res, s;
char mins[100007];

int main() {
    cin >> s;
    
    mins[(ll)s.length()] = 'z' + 1;
    mins[(ll)s.length() - 1] = s[(ll)s.length() - 1];

    for(ll i = (ll)s.length() - 2; i >= 0; --i) {
        if(s[i] <= mins[i + 1]) mins[i] = s[i];
        else mins[i] = mins[i + 1];
    }

    stack<char> st;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        st.push(s[i]);
        while(!st.empty() && st.top() <= mins[i + 1]) {
            cout << st.top();
            st.pop();
        }
    }    

    //cout << res << '\n';
    return 0;
}