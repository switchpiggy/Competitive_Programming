#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ll maxn = 0;
    for(ll i = 0; i < n; ++i) {
        cin >> x >> y;
        maxn = max(maxn, x + y);
    }

    cout << maxn << '\n';
    return 0;
}