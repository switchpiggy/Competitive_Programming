#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;

    scanf("%d", &t);

    int n, k;

    while(t--) {

        scanf("%d %d", &n, &k);
        
        int s;
        
        if(floor(k/2) > n%k) s = n%k;
        
        else s = (k/2);

        printf("%d\n", ((n/k) * k) + s);


    }

    return 0;

}