#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, pref[3][100007], ans = 0;
char temp;

int main() {
    scanf("%lld", &n);
    pref[0][0] = pref[1][0] = pref[2][0] = 0; 
    for(ll i = 1; i <= n; ++i) {
        cin >> temp;
        if(temp == 'P') pref[2][i]++;
        else if(temp == 'S') pref[0][i]++;
        else pref[1][i]++;
    }

    for(ll i = 1; i <= n; ++i) {
        pref[2][i] += pref[2][i - 1];
        pref[1][i] += pref[1][i - 1];
        pref[0][i] += pref[0][i - 1];
    }

    for(ll i = 1; i <= n; ++i) {
        ll max1 = max(pref[0][i], max(pref[1][i], pref[2][i])), max2 = max(pref[0][n] - pref[0][i], max(pref[1][n] - pref[1][i], pref[2][n] - pref[2][i]));
        ans = max(max1 + max2, ans);
    }

    printf("%lld\n", ans);

    return 0;
}