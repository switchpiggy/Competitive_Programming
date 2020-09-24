#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[107];
vector<ll> ans[107];

int main() {
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll minn = *min_element(a, a + n);

    if(*max_element(a, a + n) - *min_element(a, a + n) > k) {
        cout << "NO\n";
        return 0;
    }
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < min(a[i], minn + 1); ++j) ans[i].push_back(1);
        a[i] -= min(a[i], minn + 1);
    }

    for(ll i = 2; i <= k; ++i) {
        bool ok = 0;
        for(ll j = 0; j < n; ++j) {
            if(a[j]) {
                ok = 1;
                ans[j].push_back(i);
                a[j]--;
            }
        }

        if(!ok) break;
    }

    cout << "YES\n";
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < ans[i].size(); ++j) cout << ans[i][j] << ' ';
        cout << '\n';
    }    

    return 0;
}