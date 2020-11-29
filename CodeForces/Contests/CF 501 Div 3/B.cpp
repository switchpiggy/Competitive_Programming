#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s, t;
ll n;
vector<ll> res;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s >> t;
    string v = s, u = t;
    sort(v.begin(), v.end());
    sort(u.begin(), u.end());

    if(v != u) {
        cout << "-1\n";
        return 0;
    }

    for(ll i = 0; i < n; ++i) {
        if(s[i] == t[i]) continue;
        for(ll j = i + 1; j < n; ++j) {
            if(s[j] == t[i]) {
                for(ll k = j - 1; k >= i; --k) {
                    res.push_back(k + 1);
                    swap(s[k], s[k + 1]);
                }
                break;
            }
        }
    }

    cout << (ll)res.size() << '\n';
    for(ll i : res) cout << i << ' ';
    return 0;
}