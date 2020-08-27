#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int n;
vector<ll> a;

int main() {
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    sort(a.rbegin(), a.rend());

    ll ans = 0;
    for(int i = 1; i <= n; i *= 4) {
        ans += accumulate(a.begin(), a.begin() + i, 0ll);
    }

    cout << ans << endl;
    return 0;
}