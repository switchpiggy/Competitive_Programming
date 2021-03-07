#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
long double a, b, c, d;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c >> d;
    long double k = (b * (c - a))/(d + b);
    cout << fixed << setprecision(12) << a + k << '\n';
    return 0;
}