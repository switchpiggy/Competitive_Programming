#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
vector<ll> ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        ans.clear();
        cin >> n;
        ll sum = 0, cur = 1;
        while(sum + cur <= n) {
            sum += cur;
            ans.push_back(cur);
            cur *= 2;
        }

        if(sum < n) ans.push_back(n - sum);
        sort(ans.begin(), ans.end());

        cout << (ll)ans.size() - 1 << '\n';
        for(ll i = 1; i < (ll)ans.size(); ++i) {
            cout << ans[i] - ans[i - 1] << ' ';
        }
        cout << '\n';
    }

    return 0;
}