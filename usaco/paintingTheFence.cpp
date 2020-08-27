#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, dist, cur;
char dir;
map<ll, ll> diff;
ll mins = INT_MAX, maxs = INT_MIN;

int main() {
    scanf("%lld %lld", &n, &k);
    for(ll i = 0; i < n; ++i) {
        cin >> dist >> dir;
        if(dir == 'L') {
            diff[cur + 1]--;
            diff[cur - dist]++;
            cur = cur - dist;
        } else {
            diff[cur]++;
            diff[cur + dist + 1]--;
            cur = cur + dist;
        }
        maxs = max(maxs, cur);
        mins = min(mins, cur);
    }

    ll res = 0, paint = 0;
    map<ll, ll>::iterator prev;

    for(auto itr = diff.begin(); itr != diff.end(); ++itr) {
        if(itr != diff.begin() && paint >= k) res += itr->first - prev->first;
        prev = itr;
        paint += itr->second;
    }

    printf("%lld\n", res);

    return 0;
}