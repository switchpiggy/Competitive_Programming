#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    if(n <= m) {
        cout << n << '\n';
        return 0;
    }
    
    ll l = 0, r = 1e18 + 1, ans = -1;
    while(l < r) {
        ll mid = (l + r)/2;
        if(mid >= (2 * (n - m) + mid)/(mid + 1)) {
            ans = mid;
            r = mid;
        } else l = mid + 1;
    }

    cout << m + ans << '\n';
}