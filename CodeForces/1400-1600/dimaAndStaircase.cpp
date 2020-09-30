#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007], w, h, m, pr;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> a[i];
    
    cin >> m;
    ll pw = 0, ph = 0;
    for(ll i = 0; i < m; ++i) {
        cin >> w >> h;
        cout << max(a[w], pr + ph) << '\n';

        pr = max(a[w], pr + ph);
        ph = h, pw = w;
    }

    return 0;
}