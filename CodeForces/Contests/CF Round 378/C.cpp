#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[1000007], k, b[1000007];
set<ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    cin >> k;
    for(ll i = 0; i < k; ++i) cin >> b[i];
    vector<pair<ll, pair<ll, ll>>> v;

    ll j = 0, i = 0, maxInd = 0, sum = 0, p = 0;
    while(i < n && j < k) {
        sum += a[i];
        if(a[i] > a[maxInd]) {
            maxInd = i;
        }

        occ.insert(a[i]);
        if(sum == b[j]) {
            if((ll)occ.size() < 2) {
                cout << "NO\n";
                return 0;
            }

            occ.clear();
            v.push_back({maxInd, {p, i}});
            j++;
            sum = 0;
            maxInd = p = ++i;
            continue;
        }

        if(sum > b[j]) {
            cout << "NO\n";
            return 0;
        }

        i++;
    }

    if(!(i == n && j == k && !sum)) {
        cout << "NO\n";
        return 0;
    }

    for(ll i = 0; i < (ll)v.size(); ++i) {
        pair<ll, pair<ll, ll>> p = v[i];
    }
}