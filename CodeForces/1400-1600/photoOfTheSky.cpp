#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < 2 * n; ++i) cin >> a[i];

    sort(a, a + 2 * n);

    cout << (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]) << '\n';
    return 0;
}