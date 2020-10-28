#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, d, a[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d;
    ll ans = 10 * (n - 1);
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        ans += a[i];
    }

    if(ans > d) {
        cout << "-1\n";
        return 0;
    }    

    cout << 2 * (n - 1) + ((d - ans)/5) << '\n';
    return 0;
}