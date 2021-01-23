#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define flout cout << fixed << setprecision(12)
ll x, y, x2, y2, x3, y3;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> y >> x2 >> y2 >> x3 >> y3;
    if((x == x2 && x2 == x3) || (y == y2 && y2 == y3)) {
        cout << "1\n";
        return 0;
    }

    vector<pair<ll, ll>> p;
    p.push_back({x, y});
    p.push_back({x2, y2});
    p.push_back({x3, y3});

    for(ll i = 0; i < 3; ++i) {
        for(ll j = i + 1; j < 3; ++j) {
            if(p[i].first == p[j].first) {
                ll k = 3 - i - j;
                if(min(p[i].second, p[j].second) < p[k].second && p[k].second < max(p[i].second, p[j].second)) {
                    continue;
                }

                cout << "2\n";
                return 0;
            }

            if(p[i].second == p[j].second) {
                ll k = 3 - i - j;
                if(min(p[i].first, p[j].first) <= p[k].first && p[k].first <= max(p[i].first, p[j].first)) continue;

                cout << "2\n";
                return 0;
            }
        }
    }

    cout << "3\n";
    return 0;
}