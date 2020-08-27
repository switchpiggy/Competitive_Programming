#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll n, a, b;
vector<pair<ll, ll>> v;

int main() {
    bool flag = false;
    scanf("%lld", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%lld %lld", &a, &b);
        if(a != b) flag = true;
        v.push_back(make_pair(a, b));
    }
    if(!flag) {
        printf("Poor Alex");
        return 0;
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; ++i) {
        if(v[i].second > v[i + 1].second) {
            printf("Happy Alex");
            return 0;
        }
    }

    printf("Poor Alex");
}