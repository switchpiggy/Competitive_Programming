#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<pair<string, string>> v;
vector<string> p = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        string a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        v.push_back({a, f});
    }

    sort(p.begin(), p.end());
    
    do {
        bool ok2 = 1;
        for(ll i = 0; i < n; ++i) {
            bool ok = 0;
            for(ll j = 0; j < 7; ++j) {
                if((v[i].first == p[j] && v[i].second == p[j + 1]) || (v[i].first == p[j + 1] && v[i].second == p[j])) {
                    ok = 1;
                    break;
                }
            }

            if(!ok) {
                ok2 = 0;
                break;
            }
        }

        if(ok2) {
            for(ll i = 0; i < 8; ++i) cout << p[i] << '\n';
            return 0;
        }
    } while(next_permutation(p.begin(), p.end()));
}