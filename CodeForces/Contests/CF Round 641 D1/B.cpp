#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[100007], t;
vector<ll> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(ll i = 0; i < n; ++i) cin >> a[i];
        bool ok = 0;
        for(ll i = 0; i < n; ++i) {
            if(a[i] == k) {
                ok = 1;
                a[i] = 1;
            } else if(a[i] > k) { 
                a[i] = 2;
            } else a[i] = 0;
        }

        if(!ok) {
            cout << "no\n";
            continue;
        }

        ok = 0;
        for(ll i = 0; i < n; ++i) {
            v.clear();
            //bool flag = 0;
            v.push_back(a[i]);
            for(ll j = 1; j < 3; ++j) {
                if(i + j >= n) continue;
                v.push_back(a[i + j]);
                sort(v.begin(), v.end());
                //if(n == 4) for(ll i : v) cout << i << ' ';
                //cout << '\n';
                if((ll)v.size() > 1 && 1 <= v[((ll)v.size() - 1)/2]) {
                    ok = 1;
                    break;
                }
            }

            if(ok) break;
        }

        if(n == 1 && a[0] == 1) ok = 1;
        //cout << a[0] << ' ';

        cout << (ok ? "yes\n" : "no\n");
    }

    return 0;
}