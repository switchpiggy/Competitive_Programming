#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s, t;
map<char, ll> occ;
map<char, ll> tc;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll res = 0, q = 0;

    cin >> s >> t;
    for(ll i = 0; i < (ll)t.length(); ++i) {
        tc[t[i]]++;
        if(s[i] == '?') {
            q++;
        } else occ[s[i]]++;
    }

    ll c = 0;
    bool flag = 1;
    for(char j = 'a'; j <= 'z'; ++j) {
        if(occ[j] > tc[j]) {
            flag = 0;
            break;
        }

        c += tc[j] - occ[j];
    }

    if(flag && c == q) res++;

    for(ll i = 1; i < (ll)s.length() - (ll)t.length() + 1; ++i) {
        if(s[i - 1] == '?') q--;
        else occ[s[i - 1]]--;

        if(s[i + (ll)t.length() - 1] == '?') q++;
        else occ[s[i + (ll)t.length() - 1]]++;

        bool ok = 1;

        ll cnt = 0;
        for(char j = 'a'; j <= 'z'; ++j) {
            if(occ[j] > tc[j]) {
                ok = 0;
                break;
            }

            cnt += tc[j] - occ[j];
        }

        //cout << q << ' ' << cnt << '\n';

        if(ok && cnt == q) res++;
    }

    cout << res << '\n';
    return 0;
}