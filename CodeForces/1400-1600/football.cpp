#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k;

    scanf("%d %d", &n, &k);

    if(n*(n-1)/2 < n * k) {

        printf("-1");

        return 0;

    }

    printf("%d\n", n * k);

    for(int i = 1; i <= n; ++i) {

        for(int j = i + 1; j <= i + k; ++j) {
        	
        	int cur = j%n;
        	
        	if(cur == 0) cur = n;

            printf("%d %d\n", i, cur);

        }

    }

}