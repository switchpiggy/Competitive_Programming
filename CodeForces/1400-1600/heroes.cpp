#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, y, z;
string s, t, u;
vector<pair<string, string>> like;

int main() {
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> s >> t >> u;
        like.push_back(make_pair(s, u));
    }

    cin >> x >> y >> z;

    pair<ll, ll> ans = make_pair(INT_MAX, 0);

    for(ll a = 1; a <= 3; ++a) {
        for(ll b = 1; b <= 3; ++b) {
            for(ll c = 1; c <= 3; ++c) {
                for(ll d = 1; d <= 3; ++d) {
                    for(ll e = 1; e <= 3; ++e) {
                        for(ll f = 1; f <= 3; ++f) {
                            for(ll g = 1; g <= 3; ++g) {
                                set<string> teams[3];
                                teams[a - 1].insert("Anka");
                                teams[b - 1].insert("Chapay");
                                teams[c - 1].insert("Cleo");
                                teams[d - 1].insert("Troll");
                                teams[e - 1].insert("Dracul");
                                teams[f - 1].insert("Snowy");
                                teams[g - 1].insert("Hexadecimal");
                                if(teams[0].empty() || teams[1].empty() || teams[2].empty()) continue;

                                ll cnt = 0;
                                for(ll i = 0; i < 3; ++i) {
                                    for(ll j = 0; j < like.size(); ++j) {
                                        if(teams[i].count(like[j].first) && teams[i].count(like[j].second)) cnt++;
                                    }
                                }

                                ll res = max(x/(ll)teams[0].size(), max(y/(ll)teams[1].size(), z/(ll)teams[2].size())) - min(x/(ll)teams[0].size(), min(y/(ll)teams[1].size(), z/(ll)teams[2].size()));
                                //cout << res << endl << teams[0].size() << ' ' << teams[1].size() << ' ' << teams[2].size() << endl;

                                if(res < ans.first) {
                                    ans.first = res;
                                    ans.second = cnt;
                                } else if(res == ans.first && cnt > ans.second) {
                                    ans.first = res;
                                    ans.second = cnt;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans.first << ' ' << ans.second;
}