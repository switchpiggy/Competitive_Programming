#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[1007], odd = 0, even = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i]%2) odd++;
        else even++;
    }

    ll ans = 0;
    for(ll i = 0; i <= n; ++i) {
        if(odd < i || (odd - i)%2 == 1) continue;
        //if(odd >= i && (odd - i)/2 + even >= i - 1) ans = i * 2 - 1;
        if(odd >= i && (odd - i)/2 + even >= i) ans = i * 2;
        if(odd >= i && (odd - i)/2 + even >= i + 1) ans = i * 2 + 1;
    }
    
    cout << ans << '\n';
    return 0;
}