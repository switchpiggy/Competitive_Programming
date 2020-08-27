#include <bits/stdc++.h>

using namespace std;

#define s(n) scanf("%d", &n);

int main() {

    int t, a, b, c, n;

    s(t);

    while(t--) {

        s(a);

        s(b);

        s(c);

        s(n);

        int ay = (a + b + c + n)/3 - a;

        int by = (a + b + c + n)/3 - b;

        int cy = (a + b + c + n)/3 - c;

        if(a + ay == b + by && b + by == c + cy && ay >= 0 && by >= 0 && cy >= 0 && ay + by + cy == n) printf("YES\n");

        else printf("NO\n");

    }



}