#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;

    scanf("%d", &t);

    while(t--) {

        int n, arr[200005];

        scanf("%d", &n);

        for(int i = 1; i <= 2 * n; ++i) cin >> arr[i];

        sort(arr, arr + 2 * n + 1);

        printf("%d\n", arr[n + 1] - arr[n]);

    }

}