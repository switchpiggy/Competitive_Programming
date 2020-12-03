#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll k;
string q;
vector<ll> ans;
map<char, bool> taken;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> q;
    for(ll i = 0; i < (ll)q.length(); ++i) {
        if(!taken[q[i]]) {
            ans.push_back(i);
            taken[q[i]] = 1;
        }

        if((ll)ans.size() == k) {
            cout << "YES\n";
            for(ll j = 0; j < (ll)ans.size() - 1; ++j) cout << q.substr(ans[j], ans[j + 1] - ans[j]) << '\n';
            cout << q.substr(ans.back()) << '\n';
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}