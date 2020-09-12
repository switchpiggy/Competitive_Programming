#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
map<ll, ll> occ;
ll n, a[107], ans[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        occ[a[i]]++;
    }

    ll cnt = 0, maxn = -1;
    for(auto i = occ.begin(); i != occ.end(); ++i) {
        if(i->second == 1) cnt++;
        if(i->second >= 3) maxn = i->first;
    }

    if(cnt%2 == 1 && maxn == -1) {
        cout << "NO\n";
        return 0;
    }

    ll cur = 1;
    for(ll i = 0; i < n; ++i) {
        if(occ[a[i]] == 1) {
            ans[i] = cur;
            cur = 3 - cur;
        }
    }

    if(cnt%2 == 1) {
        bool ok = 0;
        for(ll i = 0; i < n; ++i) {
            if(a[i] == maxn) {
                if(!ok) {
                    ok = 1;
                    ans[i] = 2;
                } else {
                    ans[i] = 1;
                }
            }
        }
    }

    cout << "YES\n";
    for(ll i = 0; i < n; ++i) {
        if(ans[i] == 1) cout << 'A';
        else cout << 'B';
    }

    return 0;
}