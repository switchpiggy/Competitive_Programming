#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;
set<char> st;

bool up() {
    if(st.count('1') || st.count('2') || st.count('3')) return 1;
    return 0;
}

bool down() {
    if(st.count('0') || st.count('9') || st.count('7')) return 1;
    return 0;
}

bool left() {
    if(st.count('1') || st.count('4') || st.count('7') || st.count('0')) return 1;
    return 0;
}

bool right() {
    if(st.count('3') || st.count('6') || st.count('9') || st.count('0')) return 1;
    return 0;
}

int main() {
    cin >> n >> s;
    for(ll i = 0; i < n; ++i) st.insert(s[i]);
     
    if(up() && down() && left() && right()) cout << "YES" << endl;
    else cout << "NO" << endl;
}