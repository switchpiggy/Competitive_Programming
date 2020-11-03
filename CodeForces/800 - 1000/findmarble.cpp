#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, s, t, p[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s >> t;
    for(ll i = 1; i <= n; ++i) cin >> p[i];

    ll cur = s, ans = 0;
    while(1) {
        if(cur == t) {
            cout << ans << '\n';
            return 0;
        }    
        ans++;
        cur = p[cur];
        if(cur == s) break;
    }

    cout << "-1\n";
    return 0;
}