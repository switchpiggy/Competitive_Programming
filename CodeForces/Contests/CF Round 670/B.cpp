#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
vector<ll> pos;
vector<ll> neg;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        pos.clear();
        neg.clear();

        cin >> n;

        for(ll i = 0; i < n; ++i) {
            ll temp;
            cin >> temp;

            if(temp > 0) pos.push_back(temp);
            if(temp < 0) neg.push_back(temp);
        }

        sort(pos.begin(), pos.end(), greater<ll>());
        sort(neg.begin(), neg.end());

        if((ll)pos.size() + (ll)neg.size() < 5) {
            cout << 0 << '\n';
            continue;
        }

        if((ll)pos.size() + (ll)neg.size() < n && pos.empty()) {
            cout << 0 << '\n';
            continue;
        }

        //cout << pos.size() << ' ' << neg.size() << '\n';

        if((ll)pos.size() == 0) {
            ll res = 1;
            for(ll i = neg.size() - 1; i >= (ll)neg.size() - 5; --i) res *= neg[i];
            cout << res << '\n';
            continue;
        }

        if((ll)neg.size() == 1) {
            ll res = neg[0];
            for(ll i = (ll)pos.size() - 1; i >= (ll)pos.size() - 4; --i) res *= pos[i];
            cout << res << '\n';
            continue;
        }

        ll ans = INT_MIN;

        for(ll i = 0; i <= neg.size() && i <= 4; i += 2) {
            if(5 - i > pos.size()) continue;
            ll cnt = 1;
            for(ll j = 0; j < i; ++j) cnt *= neg[j];
            for(ll j = 0; j < 5 - i; ++j) cnt *= pos[j];
            ans = max(ans, cnt);
        }        

        cout << ans << '\n';
    }

    return 0;
}