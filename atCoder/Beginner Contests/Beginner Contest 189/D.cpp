#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define flout cout << fixed << setprecision(12)
ll n;
vector<string> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll orcnt = 0;
    for(ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
        orcnt += (v[i] == "AND");
    }

    ll ans = 1;
    for(ll i = 0; i < n; ++i) {
        if(v[i] == "OR") {
            ans += (1ll << (i + 1));
        }
    }

    cout << ans << '\n';
    return 0;
}