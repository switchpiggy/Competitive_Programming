#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

int main() {
    cin >> s;
    ll ans = 0;
    for(ll i = 0; i < s.length() - 1; ++i) {
        ll cur = stoll(s.substr(i, 2));
        if(cur%4 == 0) ans += i + 1;
    }

    for(ll i = 0; i < s.length(); ++i) if((s[i] - '0')%4 == 0) ans++;

    cout << ans << '\n';
    return 0;
}