#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, k;
char s[2000007], res[2000007];
bool vis[2000007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ll maxn = -1;
    for(ll i = 0; i < n; ++i) {
        cin >> s >> k;
        ll len = strlen(s);
        ll cur = INT_MIN;
        for(ll j = 0; j < k; ++j) {
            cin >> a;
            a--;
            maxn = max(maxn, a + len);
            for(ll jj = max(cur, a); jj <= a + len - 1; ++jj) {
                if(!vis[jj]) {
                    vis[jj] = 1;
                    res[jj] = s[jj - a];
                }
            }

            cur = max(cur, a + len - 1);
        }
    }
    

    for(ll i = 0; i < maxn; ++i) if(!res[i]) cout << 'a';
    else cout << res[i];
    return 0;
}