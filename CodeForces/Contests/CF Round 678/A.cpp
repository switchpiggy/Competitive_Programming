#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[107], q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> q;
    while(q--) {
        cin >> n >> m;
        ll sum = 0;
        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }

        if(m == sum) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}