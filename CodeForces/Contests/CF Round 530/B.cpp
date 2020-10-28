#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ll maxn = INT_MAX;
    for(ll i = 1; i * i <= n; ++i) {
        maxn = min(maxn, i + ((n + i - 1)/i));
    }

    cout << maxn << '\n';
    return 0;
}