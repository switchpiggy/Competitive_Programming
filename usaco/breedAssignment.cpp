#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a, b;
char c;

ll cnt = 0;

ll breed[16];
char relationships[16][16];

bool valid(ll cur, ll g) {
    for(ll i = 1; i < cur; ++i) {
        if(relationships[cur][i] == 'D' && breed[i] == g) return false;
        if(relationships[cur][i] == 'S' && breed[i] != g) return false;
    }

    return true;
}

void backtrack(ll cur) {
    if(cur > n) {
        cnt++;
        return;
    }

    for(ll i = 1; i <= 3; ++i) {
        if(valid(cur, i)) {
            breed[cur] = i;
            backtrack(cur + 1);
            breed[cur] = 0;
        } 
    }

    return;

}

int main() {
    scanf("%lld %lld", &n, &k);

    for(ll i = 0; i < k; ++i) {
        cin >> c >> a >> b;
        relationships[a][b] = relationships[b][a] = c;
    }

    backtrack(1);

    printf("%lld\n", cnt);

    return 0;
}