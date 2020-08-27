#include <bits/stdc++.h>

using namespace std;

int main() {

    int t, n, a[105], b[105];

    scanf("%d", &t);

    while(t--) {

        scanf("%d", &n);

        for(int i = 0; i < n; ++i) scanf("%d", &a[i]);

        for(int i = 0; i < n; ++i) scanf("%d", &b[i]);

        sort(a, a + n);

        sort(b, b + n);

        for(int i = 0; i < n; ++i) printf("%d ", a[i]);

        printf("\n");

        for(int i = 0; i < n; ++i) printf("%d ", b[i]);
        
        printf("\n");

    }

}