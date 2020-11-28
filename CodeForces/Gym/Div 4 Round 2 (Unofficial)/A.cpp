#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, x;
map<ll, bool> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(ll i = 0; i < k; ++i) {
        cin >> x;
        m[x] = 1;
    }

    ll cnt = 0;
    for(ll i = 1; i <= n; ++i) {
        if(!m[i]) cnt++;
    }
    
    if(cnt != 1) cout << "NO\n";
    else cout << "YES\n";

    return 0;
}