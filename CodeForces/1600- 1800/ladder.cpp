#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[100007], rn[100007], ln[100007];
ll l, r;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 1; i <= n; ++i) cin >> a[i];
    ln[1] = 1;
    for(ll i = 2; i <= n; ++i) {
        if(a[i] <= a[i - 1]) ln[i] = ln[i - 1];
        else ln[i] = i;
    }

    rn[n] = n;
    for(ll i = n - 1; i >= 1; --i) {
        if(a[i] <= a[i + 1]) rn[i] = rn[i + 1];
        else rn[i] = i;
    }

    while(m--) {
        cin >> l >> r;
        if(ln[r] <= rn[l]) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}