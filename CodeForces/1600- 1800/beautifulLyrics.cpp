#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue

bool isv(ll x) {
    if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') return 1;
    return 0;
}

ll n, cnt[1000007][5], total[1000007];
vector<string> v;
vector<pair<char, string>> a[1000007];
char vow[5] = {'a', 'e', 'i', 'o', 'u'};
vector<pair<string, string>> same, dif;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
        ll cur = 0;
        char last;
        for(char c : s) {
            if(isv(c)) {
                cur++;
                last = c;
            }
        }

        a[cur].push_back({last, s});
    }

    //for(ll i = 1; i <= 1000000; ++i) total[i] = cnt[i][0] + cnt[i][1] + cnt[i][2] + cnt[i][3] + cnt[i][4];

    //ll ans = 0;
    for(ll i = 1; i <= 1000000; ++i) {
        //sort(cnt[i], cnt[i] + 5, greater<ll>());
        sort(a[i].begin(), a[i].end());
        string pre = "";
        for(ll j = 0; j < (ll)a[i].size(); ) {
            if(j + 1 < (ll)a[i].size() && a[i][j + 1].first == a[i][j].first) {
                same.push_back({a[i][j].second, a[i][j + 1].second});
                j += 2;
            } else {
                if(!pre.empty()) {
                    dif.push_back({a[i][j].second, pre});
                    pre = "";
                } else pre = a[i][j].second;
                j++;
            }
        }
    }

    cout << min((ll)same.size(), ((ll)same.size() + (ll)dif.size())/2) << '\n';

    for(ll i = 0; i < min((ll)same.size(), (ll)dif.size()); ++i) {
        cout << dif[i].first << ' ' << same[i].first << '\n';
        cout << dif[i].second << ' ' << same[i].second << '\n';
    }

    for(ll i = (ll)dif.size(); i < (ll)same.size() - 1; i += 2) {
        cout << same[i].first << ' ' << same[i + 1].first << '\n';
        cout << same[i].second << ' ' << same[i + 1].second << '\n';
    }

    return 0;
}