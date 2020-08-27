#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, a, g;

    scanf("%d", &n);

    int totalA = 0, totalG = 0;

    for(int i = 0; i < n; ++i) {

        scanf("%d %d", &a, &g);

        if(totalA + a - totalG <= 500) {

            printf("A");

            totalA += a;

        } else {

            printf("G");

            totalG += g;

        }   

    }

    return 0;

}