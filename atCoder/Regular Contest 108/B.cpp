#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    string t;
    ll ans = n;
    for(ll i = 0; i < n; ++i) {
        t += s[i];
        if((ll)t.length() >= 3 && t.back() == 'x' && t[(ll)t.length() - 2] == 'o' && t[(ll)t.length() - 3] == 'f') {
            t.erase(t.end() - 3, t.end());
            ans -= 3;
        }
    }

    cout << ans << '\n';
    return 0;
}