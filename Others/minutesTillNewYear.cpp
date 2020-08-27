#include <bits/stdc++.h>

using namespace std;

int main() {

    int t, h, m;

    scanf("%d", &t);

    while(t--) {

        scanf("%d %d", &h, &m);

        printf("%d\n", 1440 - (60 * h) - m);
    
    
    }

    return 0;

}