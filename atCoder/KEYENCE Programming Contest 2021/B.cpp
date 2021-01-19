#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[300007], occ[300007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);   
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        occ[a[i]]++;
    } 

    ll pile = min(occ[0], k), ans = 0;
    for(ll i = 1; i < n; ++i) {
        if(occ[i] < pile) {
            ans += i * (pile - occ[i]);
            pile = occ[i];
            if(!pile) break;
        }
    }

    cout << ans << '\n';
    return 0;
}