#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, used[400007];
vector<ll> b;
set<ll> a, aa;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        a.clear();
        aa.clear();
        b.clear();
        memset(used, 0, sizeof(used));

        for(ll i = 0; i < n; ++i) {
            ll c;
            cin >> c;
            b.push_back(c);
            used[c] = 1;
        }

        for(ll i = 1; i <= 2 * n; ++i) {
            if(!used[i]) {
                a.insert(i);
                aa.insert(i);
            }
        }

        sort(b.begin(), b.end(), greater<ll>());
        ll maxX = 0, minX = 0;
        for(ll i = 0; i < n; ++i) {
            auto k = a.lower_bound(b[i]);
            if(k == a.begin()) {
                a.erase(*a.end());
                minX++;
            } else {
                k--;
                //cout << *k << ' ';
                a.erase(*k);
            }
        }

        for(ll i = n - 1; i >= 0; --i) {
            auto k = aa.lower_bound(b[i]);
            if(k == aa.end()) {
                aa.erase(*aa.begin());
            } else {
                aa.erase(*k);
                maxX++;
            }
        }

        cout << maxX - minX + 1 << '\n';
    }
}