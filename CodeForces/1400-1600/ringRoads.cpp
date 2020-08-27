#include <bits/stdc++.h>

using namespace std;

int adj[105][105];

int main() {

    int n, a, b, c;

    scanf("%d", &n);

    long long int t = 0;
 
    for(int i = 1; i <= n; ++i) {

        scanf("%d %d %d", &a, &b, &c);

        adj[a][b] = c;

        adj[b][a] = c * -1;

        t += c;

    }
    
    int cur = 1, prev = 0;

    long long int res = 0;

    while(true) {

        for(int i = 1; i <= n; ++i) {

            if(i != prev && adj[cur][i] != 0) {

                if(adj[cur][i] > 0) res += adj[cur][i];

                prev = cur;

                cur = i;
                
                break;

            }

        }

        if(cur == 1) break;

    }

    printf("%d", min(t - res, res));

}