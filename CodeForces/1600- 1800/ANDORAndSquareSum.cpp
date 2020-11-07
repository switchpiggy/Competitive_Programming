#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007], ans[200007], cnt[20];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < 20; ++j) {
            if(a[i] & (1 << j)) {
                cnt[j]++;
            }
        }
    }

    for(ll i = 0; i < 20; ++i) {
        for(ll j = 0; j < cnt[i]; ++j) {
            ans[j] += (1 << i);
        }
    }
    
    ll res = 0;
    for(ll i = 0; i < n; ++i) res += ans[i] * ans[i];
    cout << res << '\n';
    return 0;
}