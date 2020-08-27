#include <bits/stdc++.h>

using namespace std;

int main() {

    int t, a, b, x, y;

    scanf("%d", &t);

    while(t--) {

        scanf("%d %d %d %d", &a, &b, &x, &y);

        x++;
        
        y++;

        printf("%d\n", max(max((a - x) * b, (x - 1) * b), max((b - y) * a, (y - 1) * a)));

    }

}