#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
bool taken[100007];
map<ll, ll> m;

int main() {
    cin >> t;

    while(t--) {
        m.clear();
        memset(taken, 0, sizeof(taken));
        cin >> n;

        bool ok = 0;
        for(ll i = 1; i <= n; ++i) {
            ll minn = INT_MAX, k;

            cin >> k;
            for(ll j = 0; j < k; ++j) {
                ll temp;
                cin >> temp;
                if(taken[temp]) continue;
                minn = min(minn, temp);
            }

            if(minn == INT_MAX) continue;

            taken[minn] = 1;
            m[i] = minn;
        }

        for(ll i = 1; i <= n; ++i) {
            if(!m[i]) {
                ll kingdom = 1;
                while(taken[kingdom]) kingdom++;
                cout << "IMPROVE" << endl << i << ' ' << kingdom << endl;
                ok = 1;
                break;
            }
        }

        if(!ok) cout << "OPTIMAL" << endl;
    }

    return 0;
}