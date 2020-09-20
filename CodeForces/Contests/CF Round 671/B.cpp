#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        ll ans = 0;
        ll temp = n;
        for(ll i = 1; (i * (i + 1))/2 <= n && temp; i = i * 2 + 1) {
            if(temp < (i * (i + 1))/2) break;
            ans++;
            temp -= (i * (i + 1))/2;
        }

        cout << ans << '\n';
    }

    return 0;
}