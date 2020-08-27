#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;
bool island[107][107];
char ans[107][107];

bool filled(ll r, ll c) {
    if(r >= n || r < 0 || c >= n || c < 0 || !island[r][c]) return 0;
    return 1;
}

bool adj(ll r, ll c) {
    if(!filled(r + 1, c) && !filled(r - 1, c) && !filled(r, c + 1) && !filled(r, c - 1)) return 0;
    return 1;
}

int main() {
    scanf("%lld %lld", &n, &k);
    ll cnt = 0;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            if(!adj(i, j) && cnt < k) {
                ans[i][j] = 'L';
                island[i][j] = 1;   
                cnt++;
            } else ans[i][j] = 'S';
        } 
        printf("\n");
    }

    if(cnt < k) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) cout << ans[i][j];
        cout << endl;
    }
    return 0;
}