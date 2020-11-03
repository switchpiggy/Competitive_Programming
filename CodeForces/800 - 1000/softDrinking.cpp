#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, l, d, p, c, nl, np;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    cout << min((l * k)/nl, min(c * d, p/np))/n << '\n';

    return 0;
}