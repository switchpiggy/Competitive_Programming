#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        
        ll ans = 0;
        while(n) {
            if(n%k == 0) {
                n /= k;
                ans++;
            } else {
                ans += n%k;
                n -= n%k;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}