#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, s, t, p, pref[200007], w;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w;
    for(ll i = 0; i < n; ++i) {
        cin >> s >> t >> p;
        pref[s] += p;
        pref[t] -= p;
    }

    for(ll i = 0; i <= 200000; ++i) {
        if(i) pref[i] += pref[i - 1];
        if(pref[i] > w) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    return 0;
}