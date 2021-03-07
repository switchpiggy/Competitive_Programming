#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s, t;

int main() {
    cin >> s >> t;
    ll ans = 0;
    for(ll i = 0; i < s.length(); ++i) {
        if(s[i] != t[i]) ans++;
    }

    printf("%lld\n", ans);
    return 0;
}