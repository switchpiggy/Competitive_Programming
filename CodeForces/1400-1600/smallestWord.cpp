#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
ll ans[1007];

int main() {
    cin >> s;
    for(ll i = 1; i < (ll)s.length(); ++i) {
        if(s[i] == 'a') {
            ans[i - 1] = 1 - ans[i - 1];
            ans[i] = 1;
        }
    }

    for(ll i = 0; i < (ll)s.length(); ++i) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}