#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;

    scanf("%d", &t);

    while(t--) {

        int n;

        scanf("%d", &n);

        int count = 0;

        while(n >= 10) {

            count += n - n%10;

            int temp = floor(n/10);

            n = n%10;

            n += temp;

        }

        count += n;

        printf("%d\n", count);

    }

}