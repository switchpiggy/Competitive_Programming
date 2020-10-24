#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<ll> alice, bob, none;
ll n, k, ans = 0;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ll cnt = 0, ans = 0;
    for(ll i = 0; i < n; ++i) {
        cin >> s >> k;
        if(s == "00") none.push_back(k);
        else if(s == "01") bob.push_back(k);
        else if(s == "10") alice.push_back(k);
        else {
            cnt++;
            ans += k;
        }
    }

    sort(alice.begin(), alice.end(), greater<ll>());
    sort(bob.begin(), bob.end(), greater<ll>());

    for(ll i = 0; i < min((ll)bob.size(), (ll)alice.size()); ++i) ans += alice[i] + bob[i];
    for(ll i = (ll)alice.size(); i < (ll)bob.size(); ++i) none.push_back(bob[i]);
    for(ll i = (ll)bob.size(); i < (ll)alice.size(); ++i) none.push_back(alice[i]);

    sort(none.begin(), none.end(), greater<ll>());

    for(ll i = 0; i < cnt && i < (ll)none.size(); ++i) ans += none[i];

    cout << ans << '\n';
    return 0;
}