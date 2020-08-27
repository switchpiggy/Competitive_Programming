#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;
char c;
queue<ll> q;
vector<ll> res[11];

int main() {
    scanf("%lld", &n);
    while(cin >> c >> k) {
        if(c == 'C') {
            q.push(k);
        } else {
            ll f = q.front();
            q.pop();
            res[k].push_back(f);
        }
    }

    for(ll i = 1; i <= n; ++i) {
        for(ll j = 0; j < (ll)res[i].size(); ++j) {
            printf("%lld ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}