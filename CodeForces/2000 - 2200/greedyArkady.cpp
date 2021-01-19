#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define benq queue
#define pbenq priority_queue
#define all(x) (x.begin(), x.end())
ll n, k, m, D;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> m >> D;
    ll ans = 0;
    for(ll i = 1; i <= D; ++i) {
        ll maxn = m;
        if((i - 1) * k >= 0 && n/((i - 1) * k + 1) < maxn) maxn = n/((i - 1) * k + 1);
        if(!maxn) continue;
        if(i != (n/maxn + k - 1)/k) continue;
        ans = max(ans, i * maxn /*+ min(maxn, n%(i * maxn))*/);
    }

    cout << ans << '\n';
    return 0;
}