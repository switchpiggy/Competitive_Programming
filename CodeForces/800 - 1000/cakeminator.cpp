#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
bool r[17], c[17];
ll n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= m; ++j) {
            char a;
            cin >> a;
            if(a == 'S') {
                r[i] = c[j] = 1;
            }
        }
    }

    ll ans = 0;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= m; ++j) if(!r[i] || !c[j]) ans++; 
    }

    cout << ans << '\n';
    return 0;
}