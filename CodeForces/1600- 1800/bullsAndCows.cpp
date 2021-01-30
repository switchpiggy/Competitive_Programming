#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define m1(x) memset(x, 1, sizeof(x))
#define m0(x) memset(x, 0, sizeof(x))
#define inf(x) memset(x, 0x3f, sizeof(x))
#define flout cout << fixed << setprecision(12)
ll n;
vector<pair<string, pair<ll, ll>>> v;
vector<string> res;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        string t;
        ll a, b;
        cin >> t >> a >> b;
        v.push_back({t, {a, b}});
    }

    for(ll a = 0; a <= 9; ++a) {
        for(ll b = 0; b <= 9; ++b) {
            for(ll c = 0; c <= 9; ++c) {
                for(ll d = 0; d <= 9; ++d) {
                    if(a == b || b == c || c == d || b == d || a == c || a == d) continue;
                    string s;
                    s += char(a + '0');
                    s += char(b + '0');
                    s += char(c + '0');
                    s += char(d + '0');
                    //cout << s << '\n';
                    bool ok = 1;
                    for(ll i = 0; i < n; ++i) {
                        ll bull = 0, cow = 0;
                        for(ll j = 0; j < 4; ++j) {
                            if(s[j] == v[i].first[j]) bull++;
                            else if(v[i].first.find(s[j]) != string::npos) cow++;
                        }

                        if(bull != v[i].second.first || cow != v[i].second.second) {
                            ok = 0;
                            break;
                        }
                    }

                    if(ok) res.push_back(s);
                }
            }
        }
    }

    if(sz(res) > 1) cout << "Need more data\n";
    else if(!sz(res)) cout << "Incorrect data\n";
    else cout << res[0] << '\n';
    return 0;
}