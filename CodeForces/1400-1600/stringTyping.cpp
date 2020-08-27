#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;

int main() {
    cin >> n >> s;
    ll ans = 0;
    for(ll i = 1; i <= n; ++i) {
        string pref = s.substr(0, i);
        string suff = s.substr(i, i);
        if(pref == suff) ans = max(ans, i);
    }

    if(ans) cout << s.length() - ans + 1 << endl;
    else cout << s.length() << endl;

    return 0;
}