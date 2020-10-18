#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007], ans[100007], cnt[100007], occ[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        occ[a[i]]++;
    }

    for(ll i = 0; i < n; ++i) {
        if(occ[a[i]]%(n - a[i])) {
            cout << "Impossible\n";
            return 0;
        }
    }

    ll cur = 1;
    for(ll i = 0; i <= n; ++i) {
        if(!occ[i]) continue;
        ans[i] = cur;
        cur += occ[i]/(n - i);
    }

    cout << "Possible\n";
    for(ll i = 0; i < n; ++i) {
        cout << ans[a[i]] << ' ';
        cnt[a[i]]++;
        if(cnt[a[i]]%(n - a[i]) == 0) ans[a[i]]++;
    }

    return 0;
}