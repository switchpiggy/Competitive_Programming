#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

// b, e, m
ll milk[3], n;
vector<pair<pair<ll, ll>, string>> logs;

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        ll a, b;
        string s;

        cin >> a >> s >> b;
        logs.push_back(make_pair(make_pair(a, b), s));
    }

    sort(logs.begin(), logs.end());

    ll ans = 0;

    vector<ll> prev = {0, 1, 2};

    for(ll i = 0; i < n; ++i) {
        pair<pair<ll, ll>, string> log = logs[i];
        if(log.second == "Mildred") milk[2] += log.first.second;
        else if(log.second == "Elsie") milk[1] += log.first.second;
        else milk[0] += log.first.second;

        bool flag = false;

        ll maxn = *max_element(milk, milk + 3);
        vector<ll> cur;
        for(ll j = 0; j < 3; ++j) {
            if(milk[j] == maxn) cur.push_back(j);
        }

        if(cur.size() != prev.size()) flag = 1;
        for(ll j = 0; j < cur.size(); ++j) {
            if(cur[j] != prev[j]) flag = 1;
        }

        if(flag) {
            ans++;
            prev = cur;
        }
    }
    
    printf("%lld\n", ans);
}