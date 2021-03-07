#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, s, k;

ll inv(ll a, ll m) 
{ 
    ll m0 = m; 
    ll y = 0, x = 1; 
  
    if (m == 1) 
        return 0; 
  
    while (a > 1) { 
        ll q = a / m; 
        ll t = m; 
  
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    } 
  
    if (x < 0) 
        x += m0; 
  
    return x; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> s >> k;
        ll a = k, b = n - s, m = n, g = __gcd(a, __gcd(b, m));

        a /= g, b /= g, m /= g;
        if(__gcd(a, m) != 1) {
            cout << "-1\n";
            continue;
        }

        cout << (inv(a, m)%m * b%m + m)%m << '\n';
    }

    return 0;
}