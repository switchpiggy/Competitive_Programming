#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll h, n, a[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> n;
    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        ans += a[i];
    }

    if(ans >= h) cout << "Yes\n";
    else cout << "No\n";
}