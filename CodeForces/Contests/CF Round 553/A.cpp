#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    string t = "ACTG";
    ll ans = INT_MAX;

    for(ll i = 0; i < (ll)s.length() - 3; ++i) {
        ll cur = 0;
        for(ll j = i; j < i + 4; ++j) if(s[j] != t[j - i]) cur += min(abs((s[j] - 'a') - (t[j - i] - 'a')), 26 - abs((s[j] - 'a') - (t[j - i] - 'a')));

        ans = min(ans, cur);
    }

    cout << ans << '\n';
    return 0;
}