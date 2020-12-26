#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s, good;
ll k, pref[1507];
set<string> st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> good >> k;

    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(good[s[i] - 'a'] == '0') pref[i]++;
        if(i) pref[i] += pref[i - 1];
    }

    ll ans = 0;
    for(ll i = 1; i <= (ll)s.length(); ++i) {
        st.clear();
        string cur = s.substr(0, i);
        if(pref[i - 1] <= k) {
            st.insert(cur);
            ans++;
            //cout << cur << ' ';
        }

        for(ll j = i; j < (ll)s.length(); ++j) {
            cur.erase(cur.begin());
            cur += s[j];
            if(pref[j] - pref[j - i] <= k && st.find(cur) == st.end()) {
                ans++;
                st.insert(cur);
                //cout << cur << ' ';
            }
        }
    }

    cout << ans << '\n';
    return 0;
}