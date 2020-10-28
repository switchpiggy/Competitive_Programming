#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[107];
bool used[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll ans = 0;
    while(1) {
        memset(used, 0, sizeof(used));
        bool ok = 0;
        for(ll i = 0; i < n; ++i) {
            if(a[i] != k) {
                ok = 1;
                break;
            }
        }

        if(!ok) break;
        
        for(ll i = 0; i < n; ++i) {
            if(a[i] == k) continue;
            if(!used[a[i]]) {
                used[a[i]] = 1;
                a[i]++;
            }
        }

        ans++;
    }

    cout << ans << '\n';
    return 0;
}