#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, occ[207];
string s, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s >> t;

    for(ll i = 0; i < 207; ++i) occ[i] = -1;

    ll cnt = 0;
    for(ll i = 0; i < n; ++i) {
        if(s[i] != t[i]) {
            cnt++;
            occ[t[i]] = i;
        }
    }

    ll a = -1, b = -1;
    bool flag = 0;
    for(ll i = 0; i < n; ++i) {
        if(s[i] != t[i]) {
            if(occ[s[i]] >= 0) {
                a = i, b = occ[s[i]];
                flag = 1;
            }

            if(t[i] == s[occ[s[i]]]) {
                cnt--;
                break;
            }
        }
    }

    if(flag) {
        cout << cnt - 1 << '\n';
        cout << a + 1 << ' ' << b + 1 << '\n';
    } else {
        cout << cnt << '\n' << "-1 -1\n";
    }

    return 0;
}