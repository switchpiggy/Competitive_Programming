#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;
vector<string>  v;

int main() {
    cin >> n >> m;
    for(ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    ll ans = 0;
    for(ll i = 0; i < m; ++i) {
        bool ok = 0;
        ll maxn = 0;
        for(ll j = 0; j < n; ++j) {
            for(ll k = j + 1; k < n; ++k) {
                if(v[j] > v[k] && v[j][i] > v[k][i]) {
                    ok = 1;
                    break;
                }
            }

            if(ok) break;
        }
        //cout << '\n';
        if(ok) {
            for(ll j = 0; j < n; ++j) v[j][i] = 'a';
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}