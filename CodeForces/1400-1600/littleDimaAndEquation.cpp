#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, c;
vector<ll> ans;

ll powq(ll x, ll y) {
    ll ans = 1;
    while(y--) {
        ans *= x;
    }

    return ans;
}

int main() {
    cin >> a >> b >> c;
    for(ll i = 1; i <= 81; ++i) {
        ll x = powq(i, a) * b + c;
        if(x >= 1000000000 || x <= 0) continue;

        string s = to_string(x);
        ll res = 0;
        for(ll j = 0; j < s.length(); ++j) {
            res += s[j] - '0';
        }

        if(res == i) ans.push_back(x);
    }

    cout << (ll)ans.size() << endl;
    for(ll i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
    cout << endl;

    
    return 0;
}