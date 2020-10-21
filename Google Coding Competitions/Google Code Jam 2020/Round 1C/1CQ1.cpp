#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, x, y;
string m;

int main() {
    scanf("%lld", &t);
    for(ll tc = 1; tc <= t; ++tc) {
        ll ans = -1;
        scanf("%lld %lld", &x, &y);
        cin >> m;

        if(x == 0 && y == 0) {
            printf("Case #%lld: 0\n", tc);
            continue;
        }

        for(ll i = 0; i < m.size(); ++i) {
            if(m[i] == 'S') y--;
            else if(m[i] == 'N') y++;
            else if(m[i] == 'W') x--;
            else x++;

            if(abs(x) + abs(y) <= i + 1) {
                ans = i + 1;
                break;
            }
        }

        if(ans == -1) {
            printf("Case #%lld: IMPOSSIBLE\n", tc);
        } else {
            printf("Case #%lld: %lld\n", tc, ans);
        }
    }
}