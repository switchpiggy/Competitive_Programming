#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<string> s;

int main() {
    cin >> n;

    ll ans = INT_MAX;
    for(ll i = 0; i < n; ++i) {
        string temp;
        cin >> temp;
        s.push_back(temp);
    }

    for(ll i = 0; i < n; ++i) {
        bool flag = 0;
        ll res = 0;
        string cur = s[i];

        for(ll j = 0; j < n; ++j) {
            bool ok = 0;
            if(j == i || s[j] == cur) continue;
            string t = s[j];
            for(ll k = 0; k < t.length(); ++k) {
                t.push_back(t[0]);
                t.erase(0, 1);
                if(t == cur) {
                    res += k + 1;
                    ok = 1;
                    break;
                }
            }

            if(!ok) {
                flag = 1;
                break;
            }
        }

        if(!flag) ans = min(res, ans);
    }

    if(ans == INT_MAX) ans = -1;
    cout << ans << endl;
    return 0;
}