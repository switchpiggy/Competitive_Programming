#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;

    scanf("%d", &t);

    while(t--) {

        int a;

        scanf("%d", &a);

        if(a%2 == 1) {

            printf("7");

            a -= 3;

        }

        for(int i = 0; i < (a - a%2)/2; ++i) printf("1");

        printf("\n");

    }

}