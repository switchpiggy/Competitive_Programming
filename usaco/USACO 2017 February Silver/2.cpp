#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, b;
bool broken[100007];

int main() {
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> b;
    for(ll i = 0; i < b; ++i) {
        ll temp;
        cin >> temp;
        broken[temp] = 1;
    }

    ll cur = 0;
    for(ll i = 1; i <= k; ++i) cur += broken[i];

    ll maxn = cur;
    for(ll i = 2; i <= n - k + 1; ++i) {
        cur -= broken[i - 1];
        cur += broken[i + k - 1];
        maxn = min(maxn, cur);
    } 

    cout << maxn << '\n';
    return 0;
}