#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s, cur;
vector<string> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    ll ans = 0;

    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] != '.' && s[i] != ',' && s[i] != ':') cur += s[i];
        else if(!cur.empty()) {
            for(ll j = 0; j < (ll)v.size(); ++j) ans += (v[j] == cur);
            v.push_back(cur);
            cur.clear();
        }

        if(s[i] == '.' && !v.empty()) v.pop_back();
    }

    cout << ans << '\n';

    return 0; 
}