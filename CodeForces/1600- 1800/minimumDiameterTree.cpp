#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b, deg[100007];
long double s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(12);
    cin >> n >> s;
    for(ll i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
    }

    long double ans = 0;
    for(ll i = 1; i <= n; ++i) if(deg[i] == 1) ans += 1.0;

    cout << (2.0 * s)/ans << '\n';
}