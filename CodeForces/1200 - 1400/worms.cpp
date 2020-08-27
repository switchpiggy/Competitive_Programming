#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m, a[100005];

    scanf("%d", &n);

    a[0] = 0;

    for(int i = 1; i <= n; ++i) {

        scanf("%d", &a[i]);

        a[i] += a[i - 1];

    }
    
    scanf("%d", &m);

    while(m--) {

        int cur;

        int r = n;

        int l = 1;

        scanf("%d", &cur);

        while(l <= r) {

            int mid = (l + r)/2;

            if(a[mid] < cur) l = mid + 1;

            else if(a[mid - 1] >= cur) r = mid - 1;

            else {

                printf("%d\n", mid);

                l = n + 1;

            }

        }

    }

}