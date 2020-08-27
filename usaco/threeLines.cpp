#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b;
map<ll, ll> occ;
vector<pair<ll, ll>> v;

void yes() {
    printf("1\n");
    exit(0);
}

bool calcAns() {
    sort(v.begin(), v.end());

    ll distinct = 0;
    occ.clear();

    for(ll i = 0; i < n; ++i) {
        if(!occ[v[i].second]) distinct++; 
        occ[v[i].second]++;
    }

    if(distinct <= 3) return 1;

    ll i = 0, j = 0;
    while(i < n) {
        while(j < n && v[i].first == v[j].first) {
            j++;
        }

        for(ll k = i; k < j; ++k) {
            if(occ[v[k].second] == 1) distinct--;
            occ[v[k].second]--;
        }

        if(distinct <= 2) return 1;

        for(ll k = i; k < j; ++k) {
            if(!occ[v[k].second]) distinct++;
            occ[v[k].second]++;
        }

        i = j;
    }
    
    return 0;
}

int main() {
    scanf("%lld", &n);

    for(ll i = 0; i < n; ++i) {
        scanf("%lld %lld", &a, &b);
        v.push_back(make_pair(a, b));
    }

    if(calcAns()) {
        yes();
    } else {
        for(ll i = 0; i < n; ++i) swap(v[i].first, v[i].second);

        if(calcAns()) yes();
        else {
            printf("0\n");
            return 0;
        }
    }

    return 0;
}