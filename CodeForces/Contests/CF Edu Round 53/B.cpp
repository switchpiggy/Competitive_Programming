#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007], b[200007];
bool taken[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < n; ++i) cin >> b[i];

    ll i = 0;
    for(ll j = 0; j < n; ++j) {
        if(taken[b[j]]) {
            cout << 0 << ' ';
            continue;
        }
        ll cur = 1;
        while(a[i] != b[j]) {
            taken[a[i]] = 1;
            i++;
            cur++;
        }
        taken[b[j]] = 1;
        i++;
        cout << cur << ' ';
    }

    return 0;
}