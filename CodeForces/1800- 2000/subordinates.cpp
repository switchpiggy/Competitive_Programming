#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define benq queue
#define pbenq priority_queue
#define all(x) (x.begin(), x.end())
ll n, s, a[200007], occ[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        occ[a[i]]++;
    }

    ll ans = 0;
    if(a[s - 1] != 0) {
        occ[a[s - 1]]--;
        occ[0]++;
        a[s - 1] = 0;
        ans++;
    }

    ll maxn = 0, store = 0;
    for(ll i = 0; i < n; ++i) {
        maxn = max(maxn, a[i]);
        if(s - 1 != i && a[i] == 0) {
            store++;
            ans++;
        }
    }

    for(ll i = 1; i < n; ++i) {
        if(i >= maxn) break;
        //cout << i << ' ' << occ[i] << '\n';
        if(!occ[i]) {
            if(store) {
                store--;
                continue;
            }
            ans++;
            occ[maxn]--;
            occ[i]++;
            if(occ[maxn] == 0) {
                while(maxn > 0 && !occ[maxn]) maxn--;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}