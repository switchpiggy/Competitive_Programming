#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
pair<ll, ll> minX = make_pair(INT_MAX, 0), maxX = make_pair(0, 0), minY = make_pair(INT_MAX, 0), maxY = make_pair(0, 0), maxX2 = make_pair(0, 0), minX2 = make_pair(INT_MAX, 0), maxY2 = make_pair(0, 0), minY2 = make_pair(INT_MAX, 0);
vector<pair<ll, ll>> v;
ll n;

int main() {
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
    
    scanf("%lld", &n);

    for(ll i = 0; i < n; ++i) {
    	ll x, y;
        scanf("%lld %lld", &x, &y);
        v.push_back(make_pair(x, y));
    }

    for(ll i = 0; i < n; ++i) {
        if(v[i].first >= maxX.first) {
            maxX2.first = maxX.first;
            maxX2.second = maxX.second;
            maxX.first = v[i].first;
            maxX.second = i;
        } else if(v[i].first > maxX2.first) {
            maxX2.first = v[i].first;
            maxX2.second = i;
        }

        if(v[i].first <= minX.first) {
            minX2.first = minX.first;
            minX2.second = minX.second;
            minX.first = v[i].first;
            minX.second = i;
        } else if(v[i].first < minX2.first) {
            minX2.first = v[i].first;
            minX2.second = i;
        } 

        if(v[i].second >= maxY.first) {
            maxY2.first = maxY.first;
            maxY2.second = maxY.second;
            maxY.first = v[i].second;
            maxY.second = i;
        } else if(v[i].second > maxY2.first) {
            maxY2.first = v[i].second;
            maxY2.second = i;
        }

        if(v[i].second <= minY.first) {
            minY2.first = minY.first;
            minY.first = v[i].second;
        } else if(v[i].second < minY2.first) {
            minY2.first = v[i].second;
            minY2.second = i;
        }
        //cout << maxX.first << endl << maxY.first << endl << minX.first << endl << minY.first << endl;
    }

    ll res = INT_MAX;
    
    //cout << maxX2.first << endl << minX.first << endl << maxY2.first << endl << minY.first << endl;

    if(maxX.second == maxY.second) res = min(res, abs(maxX2.first - minX.first) * abs(maxY2.first - minY.first));
    else {
        res = min(res, abs(maxX.first - minX.first) * abs(maxY2.first - minY.first));
        //cout << res << endl;
        res = min(res, abs(maxX2.first - minX.first) * abs(maxY.first - minY.first));
    }
    
    //cout << res << endl;

    if(minX.second == minY.second) res = min(res, abs(maxX.first - minX2.first) * abs(maxY.first - minY2.first));
    else {
        res = min(res, abs(maxX.first - minX2.first) * abs(maxY.first - minY.first));
        res = min(res, abs(maxX.first - minX.first) * abs(maxY.first - minY2.first));
    }

    printf("%lld\n", res);

    return 0;
}