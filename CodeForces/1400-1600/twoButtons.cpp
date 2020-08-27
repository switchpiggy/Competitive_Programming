#include <bits/stdc++.h>

/*  
*/

using namespace std;

int main() {

    int n, m;

    scanf("%d %d", &n, &m);

    int count = 0;

    while(n != m) {

        if(m < n) {

            m++;    

        } else {

            if(m%2 == 1) m++;

            else m /= 2;

        }

        count++;

    }

    printf("%d\n", count);

}