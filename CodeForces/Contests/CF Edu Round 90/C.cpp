#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t;
string s;
ll a[1000007];

int main() {
    cin >> t;
    while(t--) {
        cin >> s;
        for(ll i = 0; i < s.length(); ++i) {
            a[i + 1] = a[i];
            if(s[i] == '-') a[i + 1]--;
            else a[i + 1]++;
            //cout << a[i + 1] << ' '; 
        }

        ll ans = 0, raise = 0;
        for(ll i = 1; i <= s.length(); ++i) {
            if(a[i] + raise >= 0) continue;
            else {
                ans += (abs(a[i]) - raise) * i;
                raise = abs(a[i]);
            }
        }

        cout << ans + s.length() << endl;
    }

    return 0;
}