#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll q, n;
string s;

ll zeroCount(string s) {
    ll cnt = 0;
    for(ll i = 0; i < s.length(); ++i) if(s[i] == '0') cnt++;
    return cnt;
}

int main() {
    cin >> q;
    while(q--) {
        cin >> n;
        ll bad = 0, odd = 0;
        for(ll i = 0; i < n; ++i) {
            cin >> s;
            if(s.length()%2 == 1) {
                odd++;
                continue;
            } else if(zeroCount(s)%2 == 1) bad++;
        }

        if(bad%2 == 1 && !odd) cout << n - 1 << endl;
        else cout << n << endl;
    }
}