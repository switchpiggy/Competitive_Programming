#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
long double h, l;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> l;

    cout << fixed << setprecision(7) << (l * l - h * h)/(2.0 * h) << '\n';
    return 0;
}