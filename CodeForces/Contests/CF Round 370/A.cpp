#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[1000007], res[1000007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> a[i];
    res[n] = a[n];
    for(ll i = n - 1; i >= 1; --i) res[i] = (a[i + 1]) + a[i];
    for(ll i = 1; i <= n; ++i) cout << res[i] << ' ';
}