#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, freq[100007], distinct = 0;

void hold_round() {
    for(ll i = 0; i < n; ++i) {
        if(--freq[i] == 0) {
            distinct--;
        }
    }
}

int main() {
    scanf("%lld %lld", &n, &m);
    for(ll i = 0; i < m; ++i) {
        ll temp;
        scanf("%lld", &temp);

        temp--;

        if(freq[temp]++ == 0) {
            distinct++;
        }

        if(distinct == n) {
            hold_round();
            printf("1");
        } else printf("0");
    }
}