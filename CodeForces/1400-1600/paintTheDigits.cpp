#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, ans[200007];
string s;

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> s;
        vector<ll> s1, s2;

        bool flag = 0;

        for(ll i = 0; i <= 9; ++i) {
            s1.clear();
            s2.clear();

            bool ok2 = 0;
            for(ll j = 0; j < n; ++j) {
                if(s[j] - '0' > i) {
                    ok2 = 1;
                    s2.push_back(s[j] - '0');
                }
                if(s[j] - '0' == i) {
                    if(!ok2) s2.push_back(s[j] - '0');
                    else s1.push_back(s[j] - '0');
                }
                if(s[j] - '0' < i) {
                    s1.push_back(s[j] - '0');
                }
            }

            bool ok = 1;
            for(ll j = 1; j < s1.size(); ++j) if(s1[j] < s1[j - 1]) ok = 0;
            for(ll j = 1; j < s2.size(); ++j) if(s2[j] < s2[j - 1]) ok = 0;

            if(!ok) continue;

            if(!s1.empty() && !s2.empty() && s1.back() > s2.front()) ok = 0;

            if(ok) {
                bool ok3 = 0;
                for(ll j = 0; j < n; ++j) {
                    if(s[j] - '0' > i) {
                        ok3 = 1;
                        ans[j] = 2;
                    }
                    if(s[j] - '0' == i) {
                        if(!ok3) ans[j] = 2;
                        else ans[j] = 1;
                    }
                    if(s[j] - '0' < i) {
                        ans[j] = 1;
                    }
                }

                for(ll j = 0; j < n; ++j) cout << ans[j];
                flag = 1;
                break;
            }
        }

        if(!flag) cout << '-';
        cout << '\n';
    }

    return 0;
}