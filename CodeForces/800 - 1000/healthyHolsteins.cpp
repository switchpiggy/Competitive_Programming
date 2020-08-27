/*
ID: alanxia1
TASK: holstein
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll numV, numF, req[30], best, bestF[20], cur, curF[20], feeds[20][30];

void getFeed(ll fcnt, ll fid) {
    ll i;
    for(i = 0; i < numV; i++) {
        if(req[i] > 0) break;
    }
    if(i >= numV) {
        best = fcnt;
        for(int a = 0; a < best; ++a) bestF[a] = curF[a];
        return;
    }
    while(fid < numF && fcnt + 1 < best) {
        for(ll j = 0; j < numV; ++j) {
            req[j] -= feeds[fid][j];
        }
        curF[fcnt] = fid;

        getFeed(fcnt + 1, fid + 1);

        for(ll j = 0; j < numV; ++j) {
            req[j] += feeds[fid][j];
        }
        fid++;
    }
}

int main() {

    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);

    scanf("%lld", &numV);
    for(int i = 0; i < numV; ++i) scanf("%lld", &req[i]);
    scanf("%lld", &numF);
    for(int i = 0; i < numF; ++i) {
        for(int j = 0; j < numV; ++j) scanf("%lld", &feeds[i][j]);
    }
    best = numF + 1;
    getFeed(0, 0);
    printf("%lld", best);
    for(ll i = 0; i < best; ++i) printf(" %lld", bestF[i] + 1);
    printf("\n");

}