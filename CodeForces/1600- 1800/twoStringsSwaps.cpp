#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s >> t;

    ll ans = 0;
    for(ll i = 0; i < n/2; ++i) {
        char a = s[i], b = s[n - i - 1], c = t[i], d = t[n - i - 1];
        if((a == b && c == d) || (a == d && c == b) || (a == c && b == d)) continue;
        
        if(a == d || a == c || b == d || b == c || c == d) ans++;
        else ans += 2; 
        //cout << ans << ' ' << i << ' ' << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    }

    cout << ans + ((n%2 == 1 && s[n/2] != t[n/2])) << '\n';
    return 0;
}