#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k, a[200005];

    int ans;

    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);

    sort(a, a + n);

    if(k == 0) ans = a[0] - 1;

    else ans = a[k - 1];

    int cur = 0;

    for(int i = 0; i < n; ++i) {

        if(a[i] <= ans) ++cur;

        else break;

    }

    if(cur == k && ans >= 1 && ans <= 1000 * 1000 * 1000) printf("%d", ans);

    else printf("-1");
}