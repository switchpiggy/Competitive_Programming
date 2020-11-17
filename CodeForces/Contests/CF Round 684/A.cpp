#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
ll t, n, c1, c0, h;
string s;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> t;
    while(t--) {
        cin >> n >> c0 >> c1 >> h >> s;
        ll sum = 0, zero = 0, one = 0;
        for(ll i = 0; i < (ll)s.length(); ++i) {
            if(s[i] == '1') {
                sum += c1;
                one++;
            }
            else {
                sum += c0;
                zero++;
            }
        }
 
        if(c1 > c0 && h < c1 - c0) cout << sum - (c1 - c0) * one + h * one << '\n';
        else if(c0 > c1 && h < c0 - c1) cout << sum - (c0 - c1) * zero + h * zero << '\n';
        else cout << sum << '\n';
    }
 
    return 0;
}