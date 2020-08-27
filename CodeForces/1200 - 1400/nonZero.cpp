#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;

    scanf("%d", &t);

    while(t--) {

        int n;

        scanf("%d", &n);

        int sum = 0, zeros = 0, count = 0;

        for(int i = 0; i < n; ++i) {

            int temp;

            scanf("%d", &temp);

            sum += temp;

            if(temp == 0) zeros++;

        }

        sum += zeros;

        count += zeros;

        if(sum == 0) count++;

        printf("%d\n", count);

    }

}