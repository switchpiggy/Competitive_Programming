#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, p, a[1000007], b[1000007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> p;
    ll c = -1, d = -1;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i]%p != 0 && c == -1) {
            c = i;
        }
    }

    for(ll i = 0; i < m; ++i) {
        cin >> b[i];
        if(b[i]%p != 0 && d == -1) {
            d = i;
        }
    }

    cout << c + d << '\n';
    return 0;
}