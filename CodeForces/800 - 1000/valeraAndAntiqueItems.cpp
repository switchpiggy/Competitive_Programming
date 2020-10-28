#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, v, k, s;
vector<ll> res;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> v;
    for(ll i = 0; i < n; ++i) {
        cin >> k;
        bool ok = 0;
        for(ll j = 0; j < k; ++j) {
            cin >> s;
            if(v > s) ok = 1;
        }

        if(ok) res.push_back(i + 1);
    }

    cout << (ll)res.size() << '\n';
    for(auto i : res) cout << i << ' ';
    cout << '\n';

    return 0;
}