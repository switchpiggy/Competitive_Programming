#include <bits/stdc++.h>

using namespace std;

#define s(n) scanf("%d", &n);

int main() {

    int t, s, n, k, floors[10000000005];

    s(t);

    while(t--) {

        s(n);

        s(s);

        s(k);

        for(int i = 1; i <= n; ++i) floors[i] = 0;


        for(int i = 1; i <= k; ++i) {

            int c;

            s(c);

            floors[c] = 1;

        }

        int i = s, j = s;

        while(1) {

            if(floors[i] == 0 || floors[j] == 0) break;

            i--;

            j++;

        }

        printf("%d\n", abs(s - min(abs(s - i), abs(s - j))));



        

    }

}