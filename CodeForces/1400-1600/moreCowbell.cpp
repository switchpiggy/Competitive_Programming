#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k, a[100005];

    cin >> n >> k;

    int res = INT_MIN;

    for(int i = 0; i < n; ++i) {

        cin >> a[i];

        res = max(res, a[i]);

    }

    for(int i = 0; i < n - k; ++i) {

        res = max(a[i] + a[2 * (n - k) - 1 - i], res);

    }

    printf("%d", res);

}