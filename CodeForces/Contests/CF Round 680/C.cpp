#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, p, q;

bool isPrime(ll x) {
    for(ll i = 2; i * i <= x; ++i) {
        if(x%i == 0) return 0;
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> p >> q;

        if(p < q || p%q != 0) {
            cout << p << '\n';
            continue;
        }

        if(isPrime(q)) {
            while(p%q == 0) p /= q;
            cout << p << '\n';
            continue;
        }

        ll ans = 1;
        for(ll i = 2; i * i <= q; ++i) {
            if(p%i == 0 && q%i == 0) {
                ll x = p, cnt = 1, z = q;
                while(z%i == 0) {
                    cnt *= i;
                    z /= i;
                }
                while(x%cnt == 0) x /= i;
                ans = max(ans, x);

                if(i != q/i && p%(q/i) == 0) {
                    x = p, cnt = 1, z = q;
                    while(z%(q/i) == 0) {
                        cnt *= q/i;
                        z /= q/i;
                    }

                    while(x%cnt == 0) x /= q/i;
                    ans = max(ans, x);
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}