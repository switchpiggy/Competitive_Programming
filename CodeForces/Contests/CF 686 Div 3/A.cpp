#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        vector<ll> ans;
        for(ll i = 1; i <= n; ++i) {
            if(i%2 == 0) ans.push_back(i - 1);
            else if(i != n) ans.push_back(i + 1);
        }

        if(n%2 == 1) {
            ans.push_back(n);
            reverse(ans.begin(), ans.end());
        }

        for(ll i = 0; i < n; ++i) cout << ans[i] << ' ';

        cout << '\n';
    }

    return 0;
}