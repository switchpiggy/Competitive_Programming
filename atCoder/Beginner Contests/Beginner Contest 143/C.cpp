#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    ll ans = 1;
    for(ll i = 1; i < (ll)s.length(); ++i) if(s[i] != s[i - 1]) ans++;
    cout << ans << '\n';
    return 0;
}