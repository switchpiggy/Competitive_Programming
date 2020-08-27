#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, y;
vector<pair<ll, ll>> v;

bool cmp(pair<ll, ll> x, pair<ll, ll> y) {
    return x.second < y.second;
}

int main() {
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end());

    ll x = 0, minx = INT_MAX, j = 0;
    for(ll i = 0; i <= 1e6; i += 2) {
        while(v[j].first <= i) j++;
        if(abs(j - (n - j)) < minx) {
            minx = abs(j - (n - j));
            x = i;
        }
    }

    sort(v.begin(), v.end(), cmp);

    ll y = 0, miny = INT_MAX, k = 0;
    for(ll i = 0; i <= 1e6; i += 2) {
        while(v[k].second <= i) k++;
        if(abs(k - (n - k)) < miny) {
            miny = abs(k - (n - k));
            y = i;
        }        
    }

    ll a = 0, b = 0, c = 0, d = 0;
    for(ll i = 0; i < n; ++i) {
        if(v[i].first > x && v[i].second > y) a++;
        else if(v[i].first < x && v[i].second > y) b++;
        else if(v[i].first < x && v[i].second < y) c++;
        else d++;
    }

    cout << max(max(a, b), max(c, d)) << endl;
    return 0;
}