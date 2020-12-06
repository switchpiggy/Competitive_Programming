#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    ll l = 0, r = 1000000000000000001, ans = 0;
    while(l < r) {
        ll m = (l + r)/2;
        //cout << m << ' ';
        if(m <= (2 * (n + 1))/(m + 1)) {
            ans = m;
            l = m + 1;
        } else r = m;
    }

    cout << n + 1 - ans << '\n';
    return 0;
}