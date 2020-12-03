#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, p[9], q[9], pq[9];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(ll i = 0; i < n; ++i) cin >> p[i];
    for(ll i = 0; i < n; ++i) cin >> q[i];
    for(ll i = 0; i < n; ++i) pq[i] = i + 1;

    ll a, b;
    ll cur = 0;
    do {
        cur++;
        bool ok = 0, ok2 = 0;
        for(ll i = 0; i < n; ++i) {
            if(q[i] != pq[i]) ok2 = 1;
            if(p[i] != pq[i]) ok = 1;
        }

        if(!ok) a = cur;
        if(!ok2) b = cur;
    } while(next_permutation(pq, pq + n));

    cout << abs(a - b) << '\n';
}