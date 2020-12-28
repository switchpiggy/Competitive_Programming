#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll k, d, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(12);
    cin >> k >> d >> t;
    ll period = (k + d - 1)/d * d;
    ll cook = k + period;
    ll num = (2 * t)/cook;

    cout << num * period + ((2 * t - num * cook > 2 * k) ? 2 * t - num * cook - k : (long double)(2 * t - num * cook)/2.0) << '\n';
}