#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
ll n, k, a[100007], occ[100007], d;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll l = 0, r = 0;
    for(ll i = 0; i < n; ++i) {
        if(occ[a[i]] == 0) {
            d++;
        }
        r = i;
        occ[a[i]]++;
        //if(d == k) break;
    }
    
    if(d < k) {
        cout << "-1 -1\n";
        return 0;
    }

    while(d >= k && r >= 0) {
        occ[a[r]]--;
        if(!occ[a[r]]) {
            d--;
        }

        r--;
    }

    if(d >= k) {
        cout << "-1 -1\n";
        return 0;
    }

    r++;
    occ[a[r]]++;
    d++;

    while(d >= k && l <= r) {
        occ[a[l]]--;
        if(!occ[a[l]]) d--;
        l++;
    }

    l--;

    if(l > r || d >= k) cout << "-1 -1\n";
    else cout << l + 1 << ' ' << r + 1 << '\n';
    return 0;
}