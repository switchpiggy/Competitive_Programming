#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
ll n;
map<char, ll> occ;

bool check(ll k) {
    ll cnt = 0;
    for(char i = 'a'; i <= 'z'; ++i) {
        cnt += (occ[i] + k - 1)/k;
    }

    if(cnt > n) return 0;
    return 1;
}

int main() {
    ll dist = 0;
    cin >> s >> n;
    for(ll i = 0; i < s.length(); ++i) {
        occ[s[i]]++;
        if(occ[s[i]] == 1) dist++;
    }

    if(dist > n) {
        cout << "-1" << endl;
        return 0;
    }

    ll l = 1, r = s.length(), ans = s.length();
    while(l <= r) {
        ll m = (l + r)/2;
        if(check(m)) {
            r =  m - 1;
            ans = m;
        }
        else l = m + 1;
    }

    cout << ans << endl;

    ll cnt = 0;

    for(char i = 'a'; i <= 'z'; ++i) {
        for(ll j = 0; j < (occ[i] + ans - 1)/ans; ++j) {
            cout << i;
            cnt++;
        }
    }

    for(ll i = cnt; i < n; ++i) cout << 'a';

    return 0;
}