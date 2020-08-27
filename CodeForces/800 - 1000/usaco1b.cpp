#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;



ll n;
vector<pair<ll, ll>> v;
ll s[100005];
set<int> se;

int main() {
    freopen("moop.in", "r", stdin);
    freopen("moop.out", "w", stdout);
    scanf("%lld", &n);
    for(int i = 0; i < n; ++i) {
        s[i] = i;
        ll x, y;
        scanf("%lld %lld", &x, &y);
        v.push_back(make_pair(x, y)); 
    }
    //for(int i = 0; i < v.size(); ++i) printf("%lld %lld\n", v[i].first, v[i].second);

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(s[i] != s[j] && i != j && ((v[i].first <= v[j].first && v[i].second <= v[j].second) || (v[i].first >= v[j].first && v[i].second >= v[j].second))) {
                s[i] = s[j] = min(s[i], s[j]);
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        cout << s[i] << ' ';
        se.insert(s[i]);
    }

    printf("%lld\n", se.size());

}