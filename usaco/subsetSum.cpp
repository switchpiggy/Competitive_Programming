/*
ID: alanxia1
LANG: C++
PROG: subset
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, c = 0, sum;
bool visited[45];

void getAns(ll cur) {
    if(cur == sum) {
        c++;
        return;
    }
    
    if(cur > sum) return;

    for(ll i = 1; i <= n; ++i) {
        if(!visited[i]) {
            visited[i] = 1;
            getAns(cur + i);
            visited[i] = 0;
        }
    }
}

int main() {
    //freopen("subset.in", "r", stdin);
    //freopen("subset.out", "w", stdout);

    scanf("%lld", &n);
    sum = (n * (n + 1))/4;
    set<ll> x;

    getAns(0, x);
    printf("%lld\n", c/2);
}