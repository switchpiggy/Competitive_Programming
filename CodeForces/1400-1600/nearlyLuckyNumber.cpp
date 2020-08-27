#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

int main() {
    cin >> s;
    ll cnt = 0;
    for(ll i = 0; i < s.length(); ++i) {
        if(s[i] == '4' || s[i] == '7') cnt++;
    }

    string t = to_string(cnt);
    ll res = 0;
    for(ll i = 0; i < t.length(); ++i) {
        if(t[i] == '4' || t[i] == '7') continue;
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    return 0;
}