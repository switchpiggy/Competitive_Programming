#include <bits/stdc++.h>

using namespace std;

int main() {

    int t, n;

    scanf("%d", &t);

    while(t--) {

        scanf("%d", &n);

        int a;

        bool odd = false;

        bool even = false;

        for(int i = 0; i < n; ++i) {

            scanf("%d", &a);

            if(a%2 == 0) even = true;

            if(a%2 == 1) odd = true;

        }

        if(even && odd && n%2 == 0) printf("YES\n");

        else if(n%2 == 1 && odd) printf("YES\n");

        else printf("NO\n");

    }

}   