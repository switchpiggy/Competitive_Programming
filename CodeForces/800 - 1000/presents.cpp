#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, p[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 1; i <= n; ++i) {
        ll t;
        cin >> t;
        p[t] = i;
    }

    for(ll i = 1; i <= n; ++i) {
        cout << p[i] << ' ';
    }

    return 0;
}