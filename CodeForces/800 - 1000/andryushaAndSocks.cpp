#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define benq queue
#define pbenq priority_queue
#define all(x) (x.begin(), x.end())
map<ll, ll> occ;
ll n, x[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < 2 * n; ++i) cin >> x[i];

    ll ans = 0, cur = 0;
    for(ll i = 0; i < 2 * n; ++i) {
        //ans = max(ans, cur);
        if(occ[x[i]]) cur--;
        else {
            cur++;
            occ[x[i]]++;
            //ans = max(ans, cur);
        }

        ans = max(ans, cur);
    }

    ans = max(ans, cur);

    cout << ans << '\n';
    return 0;
}