#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
map<string, pair<ll, pair<ll, ll>>> m;
vector<pair<pair<ll, pair<ll, ll>>, string>> v;

int main() {
    cin >> n;
    string s;
    ll j, k;
    char c;

    for(ll i = 0; i < n; ++i) {
        cin >> s;   
    }

    for(ll i = 0; i < (n * (n - 1))/2; ++i) {
        cin >> s >> j >> c >> k;
        string a = "", b = "";
        for(ll i = 0; i < s.length(); ++i) {
            if(s[i] == '-') {
                b = s.substr(i + 1);
                break;
            }
            a += s[i];
        }

        if(j > k) {
            m[a].first += 3;
        }
        if(j == k) {
            m[a].first += 1;
            m[b].first += 1;
        }
        if(k > j) {
            m[b].first += 3;
        }

        m[a].second.second += j;
        m[b].second.second += k;

        m[a].second.first += j - k;
        m[b].second.first += k - j;
    }

    for(auto i = m.begin(); i != m.end(); ++i) {
        v.push_back(make_pair(i->second, i->first));
    }

    sort(v.begin(), v.end(), greater<pair<pair<ll, pair<ll, ll>>, string>>());

    vector<string> ans;

    for(ll i = 0; i < v.size()/2; ++i) ans.push_back(v[i].second);

    sort(ans.begin(), ans.end());
    for(ll i = 0; i < ans.size(); ++i) cout << ans[i] << endl;
    return 0;
}