#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s, t;

int main() {
    cin >> s >> t;
    ll cur = 0, i = 0;
    ll ans = 0;
    while(cur < (ll)t.length()) {
        if(t[cur] == s[i]) {
            //cout << t[cur] << '\n';
            cur++;
        }

        i++;
        if(i == 26) {
            ans++;
            i = 0;
        }
    }

    cout << ans + (i > 0) << '\n';
    //cout << s << ' ' << t << '\n';
    return 0;    
}