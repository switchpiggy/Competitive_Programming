#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s >> t;
    ll cur = 0, cur2 = 0;
    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        if(cur2 == 1 && s[i] == t[1]) {
            ans += (cur * (cur + 1))/2;
            cur = 1;
            cur2 = (s[i] == t[0]);
        } else {
            cur++;
            if(s[i] == t[0] && cur2 == 0) cur2++;
        }
    }

    if(cur) ans += (cur * (cur + 1))/2;

    cout << (n * (n + 1))/2 - ans << '\n';
    return 0;
}