#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, y, a[100007];
bool pre[100007], suf[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x >> y;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    //ll cur = INT_MAX;

    for(ll i = 0; i < n; ++i) {
        ll cur = INT_MAX;
        for(ll j = max(0ll, i - x); j < i; ++j) cur = min(cur, a[j]);
        if(cur > a[i]) pre[i] = 1;
    }

    for(ll i = n - 1; i >= 0; --i) {
        ll cur = INT_MAX;
        for(ll j = min(n - 1, i + y); j > i; --j) cur = min(cur, a[j]);

        if(cur > a[i]) suf[i] = 1;
    }

    for(ll i = 0; i < n; ++i) {
        if(pre[i] && suf[i]) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
}