#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;

    scanf("%d %d", &n, &m);

    int l = 1;

    int h = n;

    for(int i = 0; i < m; ++i) {

        int a, b;

        scanf("%d %d", &a, &b);

        if(min(a, b) >= h || max(a, b) <= l) {

            printf("0");

            return 0;

        }
        
        l = max(l, min(a, b));

        h =  min(h, max(a, b));

    }

    printf("%d", h - l);



}