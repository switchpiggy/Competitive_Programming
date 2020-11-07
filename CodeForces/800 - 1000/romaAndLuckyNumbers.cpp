#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;
vector<string> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
    } 

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        ll cur = 0;
        for(ll j = 0; j < (ll)v[i].length(); ++j) {
            if(v[i][j] == '4' || v[i][j] == '7') cur++;
        }

        if(cur <= k) ans++;
    }

    cout << ans << '\n';
    return 0;
}