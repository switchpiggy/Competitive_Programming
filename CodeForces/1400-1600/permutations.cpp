#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, maxn;
vector<ll> p;
vector<vector<ll>> permutations;

int main() {
    cin >> n >> m;

    for(ll i = 1; i <= n; ++i) p.push_back(i);

    do {

        ll res = 0;

        for(ll i = 0; i < p.size(); ++i) {
            for(ll j = i; j < p.size(); ++j) {
                ll mins = INT_MAX;
                for(ll k = i; k <= j; ++k) {
                    mins = min(mins, p[k]);
                }
                res += mins;
            } 
        }

        if(res == maxn) {
            permutations.push_back(p);
        } else if(res > maxn) {
            permutations.clear();
            permutations.push_back(p);
            maxn = res;
        }

    } while(next_permutation(p.begin(), p.end()));
    sort(permutations.begin(), permutations.end());

    for(ll i = 0; i < permutations[m - 1].size(); ++i) cout << permutations[m - 1][i] << ' ';
    return 0;
}