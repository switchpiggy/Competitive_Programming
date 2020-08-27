/*
ID: alanxia1
PROG: numtri
LANG: C++
*/



#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vi;

ll r;

vi adj[1005];

ll getDFS(ll row, ll num) {
    if(row == r - 1) return adj[r - 1][num];
    ll maxs = max(getDFS(row + 1, num), getDFS(row + 1, num + 1)) + adj[row][num];
    return maxs;
}

int main() {
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);

    scanf("%lld", &r);
    for(ll i = 0; i < r; ++i) {
        for(ll j = 0; j <= i; ++j) {
            ll temp;
            scanf("%lld", &temp);
            adj[i].push_back(temp);
        }
    }
    printf("%lld\n",getDFS(0, 0));

}