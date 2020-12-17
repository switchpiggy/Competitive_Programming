#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    ll ans = 1;
    for(ll i = 2; i * i <= a; ++i) {
        if(a%i == 0 && b%i == 0) {
            while(a%i == 0) {
                a /= i;
            }
            ans++;
        }
    }

    if(b%a == 0 && a > 1) ans++;
    cout << ans << '\n';
    return 0;
}