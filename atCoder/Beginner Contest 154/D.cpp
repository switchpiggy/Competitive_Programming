#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k; 
long double p[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(ll i = 0; i < n; ++i) {
        cin >> p[i];
        p[i] = (p[i] + 1)/2;
        if(i) p[i] += p[i - 1];
    }

    long double ans = 0;
    for(ll i = 0; i < n - k + 1; ++i) {
        ans = max(ans, (p[i + k - 1] - (i ? p[i - 1] : 0)));
    }

    cout << fixed << setprecision(12) << ans << '\n';
    return 0;
}