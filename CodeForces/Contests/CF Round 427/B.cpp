#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll k;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> s;
    sort(s.begin(), s.end());

    ll sum = 0;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        sum += s[i] - '0';
    }

    //cout << s << '\n';

    ll ans = 0;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(sum >= k) break;
        sum += 9 - (s[i] - '0');
        ans++;
    }

    cout << ans << '\n';
}