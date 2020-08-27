#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;

    scanf("%d", &t);

    while(t--) {

        int n, d, arr[105];

        scanf("%d %d", &n, &d);

        for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);

        int count = 0;

        for(int i = 1; i < n && d > 0; ++i) {

            count += min(d/i, arr[i]);

            d -= min(d, i * arr[i]);

        }

        printf("%d\n", count + arr[0]);

    }

}