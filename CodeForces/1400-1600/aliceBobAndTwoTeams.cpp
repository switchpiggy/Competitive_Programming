#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, p[500007], pref[500007], suff[500007];
string s;

int main() {
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> p[i];
    }

    cin >> s;
    ll sum = 0;
    for(ll i = 0; i < n; ++i) if(s[i] == 'B') sum += p[i];

    ll cur = 0;
    ll ans = sum;
    for(ll i = 0; i < n; ++i) {
        if(s[i] == 'A') cur += p[i];
        else cur -= p[i];

        ans = max(sum + cur, ans);
    }

    cur = 0;
    for(ll i = n - 1; i >= 0; --i) {
        if(s[i] == 'A') cur += p[i];
        else cur -= p[i];

        ans = max(sum + cur, ans);
    }   

    cout << ans << endl;
    return 0;
}