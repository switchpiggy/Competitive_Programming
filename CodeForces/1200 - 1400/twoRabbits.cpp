#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;

    scanf("%d", &t);

    while(t--) {

        int x,y, a, b;

        scanf("%d %d %d %d", &x, &y, &a, &b);

        if(abs(x - y)%(a+b) != 0) {

            printf("-1\n");

        } else {

            printf("%d\n", abs(x-y)/(a+b));

        }

    }

}