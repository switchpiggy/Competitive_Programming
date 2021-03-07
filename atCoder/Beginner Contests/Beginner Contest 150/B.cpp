#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    ll ans = 0;
    for(ll i = 0; i < (ll)s.length() - 2; ++i) {
        if(s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') ans++;
    }

    cout << ans << '\n';
    return 0;
}