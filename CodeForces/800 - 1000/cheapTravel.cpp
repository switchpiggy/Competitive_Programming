#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> a >> b;
    if(m * a <= b) {
        cout << a * n << '\n';
        return 0;
    }
    if(b <= n%m * a) {
        cout << b * (n + m - 1)/m << '\n';
        return 0;
    }

    //cout << b * (n/m) << ' ' << a * (n%m) << '\n';
    cout << b * (n/m) + a * (n%m) << '\n';
    return 0;
}