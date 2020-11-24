#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
ll k, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> s;
    ll cur = 0;
    bool ok = 1;
    for(ll i = 1; i < n; ++i) {
        if(s[i] != s[i - 1]) ok = 0;
        if(s.substr(0, i) == s.substr(n - i)) {
            cur = i;
        }
    }

    if(ok) {
        cout << string(n + k - 1, s[0]) << '\n';
        return 0;
    }

    string ans = s;
    for(ll i = 1; i < k; ++i) ans.append(s.substr(cur));

    cout << ans << '\n';
    return 0;
}