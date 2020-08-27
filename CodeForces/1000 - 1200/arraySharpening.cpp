#include <bits/stdc++.h>

using namespace std;

int main() {

    int t, n, a[300005];

    scanf("%d", &t);

    while(t--) {

        cin >> n;

        for(int i = 0; i < n; ++i) cin >> a[i];

        int pre = -1;

        int suf = n;

        for(int i = 0; i < n; ++i) {

            if(a[i] < i) break;

            pre = i;

        }

        for(int i = n - 1; i >= 0; --i) {

            if(a[i] < n - i - 1) break;

            suf = i;

        }

        if(suf <= pre) printf("YES\n");
        
        else printf("NO\n");

    }

}