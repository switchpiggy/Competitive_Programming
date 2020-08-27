#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll n, t, a, b;
vector<pair<ll, ll>> v;

int main() {
    scanf("%lld", &t);
    while(t--) {
        bool flag = false;
        v.clear();
        v.push_back(make_pair(0, 0));
        scanf("%lld", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%lld %lld", &a, &b);
            v.push_back(make_pair(a, b));
        }
        for(int i = 0; i < v.size() - 1; ++i) {
            if(v[i + 1].second < v[i].second || v[i + 1].first - v[i].first < v[i + 1].second - v[i].second || v[i + 1].first < v[i].first) {
                printf("NO\n");
                flag = 1;
                break;
            }
        }
        if(!flag) printf("YES\n");
    }
}