#include <bits/stdc++.h>

using namespace std;

bool y[1005][1005];

bool center[1005];

int main() {

    int n, m, a, b;
    
    int res;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; ++i) {

        scanf("%d %d", &a, &b);

        y[a][b] = y[b][a] = true;

        center[a] = center[b] = true;

    }

    for(int i = 1; i <= n; ++i) {

        if(!center[i]) {

            res = i;

            break;

        }

    }

    printf("%d\n", n - 1);

    for(int i = 1; i <= n; ++i) {

        if(i != res) printf("%d %d\n", res, i);

    }

}