#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s, t;

vector<ll> pos[37];
vector<ll> pos2[37];
vector<ll> q1;
vector<ll> q2;
vector<pair<ll, ll>> v;

int main() {
    cin >> n >> s >> t;

    for(ll i = 0; i < n; ++i) {
        if(s[i] == '?') q2.push_back(i);
        else pos[s[i] - 'a'].push_back(i);
        if(t[i] == '?') q1.push_back(i);
        else pos2[t[i] - 'a'].push_back(i);
    }

    ll cur = 0, cur2 = 0;

    for(char i = 0; i <= 26; ++i) {

        for(ll j = 0; j < min((ll)pos[i].size(), (ll)pos2[i].size()); ++j) {
            //cout << pos[i][j] << ' ' << pos2[j];
            v.push_back(make_pair(pos[i][j], pos2[i][j]));
        }

        if((ll)pos[i].size() > (ll)pos2[i].size() && cur < (ll)q1.size()) {
            for(ll j = (ll)pos2[i].size(); j < (ll)pos[i].size(); ++j) {
                if(cur >= (ll)q1.size()) break;
                v.push_back(make_pair(pos[i][j], q1[cur]));
                cur++;
            }
        }

        if((ll)pos2[i].size() > (ll)pos[i].size() && cur2 < (ll)q2.size()) {
            for(ll j = (ll)pos[i].size(); j < (ll)pos2[i].size(); ++j) {
                if(cur2 >= (ll)q2.size()) break;
                v.push_back(make_pair(q2[cur2], pos2[i][j]));
                cur2++;
            }
        }
    }

    while(cur < (ll)q1.size() && cur2 < (ll)q2.size()) {
        v.push_back(make_pair(q2[cur2], q1[cur]));
        cur++;
        cur2++;
    }

    cout << (ll)v.size() << '\n';
    for(ll i = 0; i < (ll)v.size(); ++i) cout << v[i].first + 1 << ' ' << v[i].second + 1 << '\n';

    return 0;
}