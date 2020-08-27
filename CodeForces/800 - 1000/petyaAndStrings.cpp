#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s, t;

int main() {
    cin >> s >> t;
    for(ll i = 0; i < s.length(); ++i) s[i] = tolower(s[i]);
    for(ll i = 0; i < t.length(); ++i) t[i] = tolower(t[i]);

    if(s < t) cout << -1 << endl;
    else if(s == t) cout << 0 << endl;
    else cout << 1 << endl;
}