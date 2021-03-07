#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<ll> ans;
    for(ll i = 1; i * i <= n; ++i) {
        if(n%i == 0) {
            ans.push_back(i);
            if(n%(n/i) == 0 && i != n/i) ans.push_back(n/i);
        }
    }

    sort(ans.begin(), ans.end());
    for(ll x : ans) cout << x << '\n';

    return 0;
}