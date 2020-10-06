#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];

        ll two = 0, one = 0, zero = 0;
        for(ll i = 0; i < n; ++i) {
            if(a[i]%3 == 0) zero++;
            if(a[i]%3 == 1) one++;
            if(a[i]%3 == 2) two++;
        }

        ll ans = min(two, one);
        one -= ans;
        two -= ans;

        cout << ans + one/3 + two/3 + zero << '\n';
    }
}