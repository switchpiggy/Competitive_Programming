#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
//hopefully getting a CP girlfriend soon
ll w, m;
vector<ll> res;

void getRes(ll x, ll y) {
    while(x) {
        ll k = x%y;
        res.push_back(k);
        x /= y;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> w >> m;
    getRes(m, w);

    bool ok = 1;
    for(ll i = 0; i < (ll)res.size(); ++i) {
        if(res[i] != 1 && res[i] != 0) ok = 0;
    }

    if(ok) {
        cout << "YES\n";
        return 0;
    }

    for(ll i = 0; i < (ll)res.size(); ++i) {
        if(res[i] == 0 || res[i] == 1) continue;
        if(res[i] == w - 1 || res[i] == w) {
            res[i] = 0;
            if(i == (ll)res.size() - 1) res.push_back(1);
            else res[i + 1]++;
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}