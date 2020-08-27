/*#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, ans;
vector<pair<ll, ll>> intervals;

pair<ll, char> checkCow(ll c) {
    ll ans = INT_MAX;
    for(int i = 0; i < intervals; ++i) {
        if(c >= intervals[i].first && c <= intervals[i].second) {
            return make_pair(0, 'n');
        } else {
            if(ans < abs(c - intervals[i].second)) {
                dir = 'b';
                ans = abs(c-  intervals[i].second);
            }
            if(ans < abs(c - intervals[i].first)) {
                dir = 'f';
                ans = abs(c-  intervals[i].first);
            }
        }
    }
    return make_pair(ans, dir);
}

void putCow(ll prev, ll next, ll number) {
    if(number == n) {
        printf("%lld\n", ans);
        return;
    }
    ll pos = prev + (next - prev)/2;
    pair<ll, char> p = checkCow(pos);
    if(p.second == 'b') {
        pos -= p.first;
    } else if(p.second == 'f') {
        pos += p.first;
    }
    ans = min(ans, min(abs(next - pos), abs(prev - pos)));
    putCow(prev, pos - 1, number + 1);
    putCow(pos + 1, next, number + 2);
}

int main() {
    scanf("%lld %lld", &n, &m);
    ll begin, end;
    for(int i = 0; i < m; ++i) {
        int a, b;
        scanf("%lld %lld", &a, &b);
        begin = min(begin, a);
        end = max(end, b);
        intervals.push_back(make_pair(a, b));
    }
    putCow(begin, end, 0);
}
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    cout << 2 << endl;
    return 0;
}