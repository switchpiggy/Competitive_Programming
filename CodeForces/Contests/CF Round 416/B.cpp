#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, p[10007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 1; i <= n; ++i) cin >> p[i];
    while(m--) {
        ll l, r, x;
        cin >> l >> r >> x;
        ll cnt = 0, cnt2 = 0;
        for(ll i = l; i <= r; ++i) {
            if(i < x && p[i] > p[x]) cnt++;
            if(i > x && p[i] < p[x]) cnt2++;
        }

        if(cnt == cnt2) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}