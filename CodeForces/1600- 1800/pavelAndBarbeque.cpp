#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define flout cout << fixed << setprecision(12)
ll n, p[200007], b[200007], nxt[200007];
bool v[200007];

void dfs(ll x) {
    v[x] = 1;
    if(!v[nxt[x]]) dfs(nxt[x]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll x = 0;
    for(ll i = 1; i <= n; ++i) cin >> nxt[i];
    for(ll i = 1; i <= n; ++i) {
        cin >> b[i];
        x += b[i];
    }

    ll cnt = 0;
    for(ll i = 1; i <= n; ++i) {
        if(!v[i]) {
            cnt++;
            dfs(i);
        }
    }

    cout << (cnt == 1 ? 0 : cnt) + (1 - x%2) << '\n';
    return 0;
}