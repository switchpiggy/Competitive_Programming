#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;

int main() {
    cin >> n >> s;
    ll r = 0, g = 0, b = 0;
    for(ll i = 0; i < s.length(); ++i) {
        if(s[i] == 'R') r++;
        else if(s[i] == 'G') g++;
        else b++;
    }

    ll ans = r * g * b;
    for(ll i = 1; i <= n/2; ++i) {
        for(ll j = 0; j < n - 2 * i; ++j) {
            if(s[j] != s[j + i] && s[j + i] != s[j + 2 * i] && s[j] != s[j + 2 * i]) ans--;
        }
    }

    cout << ans << endl;
    return 0;
}