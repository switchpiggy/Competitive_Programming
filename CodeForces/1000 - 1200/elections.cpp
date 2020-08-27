#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll n, m, city[105];
ll winners[105];

ll checkWinner() {

    ll maxVote = INT_MIN, maxIndex = 0;

    for(ll i = 1; i <= n; ++i) {
        if(city[i] > maxVote) maxIndex = i;
        maxVote = max(maxVote, city[i]);
    }

    return maxIndex;

}

int main() {

    scanf("%lld %lld", &n, &m);
    for(ll i = 1; i <= m; ++i) {

        memset(city, 0, sizeof(city));

        for(ll j = 1; j <= n; ++j) scanf("%lld", &city[j]);

        winners[checkWinner()]++;

    }

    ll maxIndex, maxVote = INT_MIN;

    for(ll i = 1; i <= n; ++i) {

        if(winners[i] > maxVote) maxIndex = i;
        maxVote = max(maxVote, winners[i]);

    }

    printf("%lld", maxIndex);

} 