#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
ll k, w[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> k;
    for(ll i = 0; i < 26; ++i) cin >> w[i];

    ll sum = 0;
    for(ll i = 0; i < (ll)s.length(); ++i) sum += w[s[i] - 'a'] * (i + 1);

    ll m = *max_element(w, w + 26);
    for(ll i = (ll)s.length() + 1; i <= (ll)s.length() + k; ++i) sum += m * i;

    cout << sum << '\n';
    return 0;
}