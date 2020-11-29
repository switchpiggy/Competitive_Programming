#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[107], m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> m;
    ll sum = 0;
    for(ll i = 0; i < n - 1; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    if(sum >= m * n) cout << 0 << '\n';
    else if(m * n - sum <= k) cout << m * n - sum << '\n';
    else cout << "-1\n";
    return 0;
}