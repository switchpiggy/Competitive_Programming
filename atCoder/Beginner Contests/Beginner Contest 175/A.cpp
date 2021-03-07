#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
ll ans = 0;

int main() {
    cin >> s;
    ll cnt = 0;
    for(ll i = 0; i < s.length(); ++i) {
        if(s[i] == 'R') {
            cnt++;
            ans = max(ans, cnt);
        }
        else {
            cnt = 0;
        }
    }

    cout << ans << endl;
    return 0;
}