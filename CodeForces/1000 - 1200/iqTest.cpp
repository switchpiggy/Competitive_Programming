#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, a[105];

    int even = 0, odd = 0, mod;

    scanf("%d", &n);

    for(int i = 0 ; i < n; ++i) scanf("%d", &a[i]);

    for(int i = 0; i < n; ++i) {

        if(a[i]%2 == 0) {

            even++;

        } else odd++;

    }

    if(odd == 1) mod = 1;

    else mod = 0;

    for(int i = 0; i < n; ++i) {

        if(a[i]%2 == mod) {

            printf("%d", i + 1);

            return 0;

        }   

    }



}