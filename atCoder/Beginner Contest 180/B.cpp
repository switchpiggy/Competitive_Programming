#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
long double n, x[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    long double man = 0, euclid = 0, cheby = INT_MIN;

    for(ll i = 0; i < n; ++i) {
        cin >> x[i];
        man += abs(x[i]);
        cheby = max(cheby, abs(x[i]));
        euclid += x[i] * x[i];
    }

    cout << fixed << setprecision(12) << man << '\n' << sqrt(euclid) << '\n' << cheby << '\n';
}