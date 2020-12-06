#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<string> v;
map<char, ll> m;
vector<pair<char, char>> vp;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    for(ll i = 0; i < n; ++i) {
        for(ll j = i + 1; j < n; ++j) {
            for(ll k = 0; k < min((ll)v[i].length(), (ll)v[j].length()); ++k) {
                if(v[i][k] == v[j][k]) continue;
                if(v[i][k] < v[j][k]) {
                    vp.push_back({v[i][k], v[j][k]});
                } else {
                    vp.push_back({v[j][k], v[i][k]});
                }
            }
        }
    }
}