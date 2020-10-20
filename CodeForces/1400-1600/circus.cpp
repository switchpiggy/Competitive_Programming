#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b, c, d;
string s, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s >> t;
    for(ll i = 0; i < n; ++i) {
        if(s[i] == '0' && t[i] == '0') a++;
        if(s[i] == '0' && t[i] == '1') b++;
        if(s[i] == '1' && t[i] == '0') c++;
        if(s[i] == '1' && t[i] == '1') d++;
    }

    for(ll i = 0; i <= b; ++i) {
        for(ll j = 0; j <= c; ++j) {
            ll k = (b + d - j - i)/2, l = n/2 - (i + j + k);

            if(i + j + k > n/2 || k > d || l > a || k * 2 != b + d - j - i || k < 0 || l < 0) continue;
            //cout << i << ' ' << j << ' ' << k << ' ' << l << '\n';

            ll cnta = 0, cntb = 0, cntc = 0, cntd = 0;
            
            for(ll m = 0; m < n; ++m) {
                if(s[m] == '0' && t[m] == '0' && cnta < l) {
                    cnta++;
                    cout << m + 1 << ' ';
                } else if(s[m] == '0' && t[m] == '1' && cntb < i) {            
                    cntb++;
                    cout << m + 1 << ' ';
                } else if(s[m] == '1' && t[m] == '0' && cntc < j) {
                    cntc++;
                    cout << m + 1 << ' ';
                } else if(s[m] == '1' && t[m] == '1' && cntd < k) {
                    cntd++;
                    cout << m + 1 << ' ';
                }
            }

            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}