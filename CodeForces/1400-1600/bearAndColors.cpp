#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, ans[5007], a[5007], cnt[5007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for(ll i = 0; i < n; ++i) {
        memset(cnt, 0, sizeof(cnt[0]) * 5007);
        ll best = a[i];
        for(ll j = i; j < n; ++j) {
            cnt[a[j]]++;
            if(cnt[a[j]] > cnt[best] || (cnt[a[j]] == cnt[best] && a[j] < best)) {
                best = a[j];
            }

            ans[best]++;
        }
    }

    for(ll i = 1; i <= n; ++i) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}