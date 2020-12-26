#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, cnt[60];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    ll sum = 0;

    for(ll i = 0; i < 60; ++i) {
        if((n & (1ll << i))) {
            sum += (1ll << i);
            cnt[i]++;
        }
    }

    if(sum > m || n%2 != m%2) {
        cout << "-1\n";
        return 0;
    }

    ll cur = (m - sum)/2;
    for(ll i = 0; i < 60; ++i) {
        if((cur & (1ll << i))) {
            cnt[i] += 2;
        }
    }

    ll maxn = 0;
    for(ll i = 0; i < 60; ++i) maxn = max(maxn, cnt[i]);

    cout << maxn << '\n';
    for(ll i = 0; i < maxn; ++i) {
        ll res = 0;
        for(ll j = 0; j < 60; ++j) {
            if(cnt[j]) {
                cnt[j]--;
                res += (1ll << j);
            }
        }

        cout << res << ' ';
    }

    return 0;
}