#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    if(m < n - 1 || m > (n * (n + 1))/2) {
        cout << "Impossible\n";
        return 0;
    }

    for(ll i = 1; i <= n; ++i) {
        for(ll j = i + 1; j <= n; ++j) {
            if(__gcd(i, j) == 1) {
                v.push_back({i, j});
            }

            if((ll)v.size() == m) {
                cout << "Possible\n";
                for(auto i : v) cout << i.first << ' ' << i.second << '\n';
                return 0;
            }
        }
    }

    cout << "Impossible\n";
    return 0;
}