#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll w, r, grid[57][107];
vector<pair<ll, ll>> v;

bool cmp(pair<ll, ll> x, pair<ll, ll> y) {
    ll a = (w + 1)/2;
    double dx = sqrt(abs(x.second - a) * abs(x.second - a) + abs(x.first - 1) * abs(x.first - 1)), dy = sqrt(abs(y.second - a) * abs(y.second - a) + abs(y.first - 1) * abs(y.first - 1));
    if(dx == dy) {
        if(x.first == y.first) return x.second < y.second;
        return x.first < y.first; 
    }

    return dx < dy;
}

int main() {
    scanf("%lld %lld", &w, &r);
    for(ll i = 1; i <= r; ++i) {
        for(ll j = 1; j <= w; ++j) {
            v.push_back(make_pair(i, j));
        }
    }

    sort(v.begin(), v.end(), cmp);

    for(ll i = 0; i < v.size(); ++i) {
        grid[v[i].first][v[i].second] = i + 1;
    }

    for(ll i = r; i >= 1; --i) {
        for(ll j = 1; j <= w; ++j) printf("%lld ", grid[i][j]);
        printf("\n");
    }

    return 0;
}