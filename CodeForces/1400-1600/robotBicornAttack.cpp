#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    string s;
    cin >> s;

    ll n = s.length();
    if(n < 3 || n > 21) {
        cout << "-1" << endl;
        return 0;
    }

    ll ans = -1;
    for(ll i = 0; i < n - 1; ++i) {
        for(ll j = i + 1; j < n - 1; ++j) {
            if(s.substr(0, i + 1).length() > 7 || s.substr(i + 1, j - i).length() > 7 || s.substr(j + 1).length() > 7) continue;
            ll a = stoll(s.substr(0, i + 1)), b = stoll(s.substr(i + 1, j - i)), c = stoll(s.substr(j + 1));
            if(a > 1000000 || b > 1000000 || c > 1000000) continue;
            if(((signed)s.substr(0, i + 1).length() == 1 || s.substr(0, i + 1)[0] != '0') && ((signed)s.substr(i + 1, j - i).length() == 1 || s.substr(i + 1, j - i)[0] != '0') && ((signed)s.substr(j + 1).length() == 1 || s.substr(j + 1)[0] != '0')) {
                ans = max(ans, a + b + c);
            }
            //cout << a << ' ' << b << ' ' << c << endl;
            //ans = max(ans, a + b + c);
        }
    }

    cout << ans << endl;
    return 0;
}