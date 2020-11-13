#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<pair<string, ll>> v;
ll n;
char res[227];

bool cmp(pair<string, ll> s, pair<string, ll> t) {
    if((ll)s.first.length() == (ll)t.first.length()) return s.first < t.first;
    return (ll)s.first.length() < (ll)t.first.length();
}

void solve(string ans) {
    for(ll i = 0; i < 2 * n - 2; i += 2) {
        //cout << v[i].first << ' ' << v[i + 1].first << ' ';
        if(ans.substr(0, (ll)v[i].first.length()) == v[i + 1].first && v[i].first == ans.substr(n - (ll)v[i].first.length())) {
            res[v[i].second] = 'S';
            res[v[i + 1].second] = 'P';
        } else if(ans.substr(0, (ll)v[i].first.length()) == v[i].first && v[i + 1].first == ans.substr(n - (ll)v[i].first.length())) {
            res[v[i].second] = 'P';
            res[v[i + 1].second] = 'S';
        } else return;
    }

    for(ll i = 0; i < 2 * n - 2; ++i) cout << res[i];
    exit(0);    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < 2 * n - 2; ++i) {
        string s;
        cin >> s;
        v.push_back({s, i});
    }

    if(n == 2) {
        cout << "SP\n";
        return 0;
    }

    sort(v.begin(), v.end(), cmp);
    string ans;

    ans = v[2 * n - 3].first;
    ans += v[2 * n - 4].first.back();
    solve(ans);
    ans = v[2 * n -4].first;
    ans += v[2 * n - 3].first.back();
    solve(ans);
    return 0;
}