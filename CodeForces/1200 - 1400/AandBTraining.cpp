#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;

    scanf("%d %d", &n, &m);

    int count = 0;

    while((n >= 1 && m >= 2) || (m >= 1 && n >= 2)) {

        if(n <= m) {

            n--;

            m -= 2;

        } else {

            n -= 2;

            m--;

        }

        count++;

    }
    
    printf("%d", count);

}