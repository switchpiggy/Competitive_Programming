#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, k, temp;
map<ll, ll> occ;

int main() {
    scanf("%lld", &t);

    while(t--) {
        occ.clear();

        ll maxn = 0, ans = 0;
        scanf("%lld %lld", &n, &k);
        for(ll i = 0; i < n; ++i) {
            scanf("%lld", &temp);
            if(temp%k == 0) continue;
            occ[k - (temp%k)]++;
            maxn = max(maxn, occ[k - (temp%k)]);
        }

        for(auto itr = occ.begin(); itr != occ.end(); ++itr) {
            if(itr->second == maxn) {
                ans = ((itr->second - 1) * k + itr->first + 1);
            }
        }

        //cout << maxn << endl << i << endl;
        printf("%lld\n", ans);
    }
    return 0;
}