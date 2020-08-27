#include <bits/stdc++.h>

using namespace std;

#define s(n) scanf("%d", &n);

int main() {

    int n, k, count = 0;

    int v[55];

    s(n);

    s(k);

    for(int i = 0; i < n; ++i) s(v[i]);

    int cur = v[k -1];

    for(int i = 0; i < n; ++i) {

        if(v[i] >= cur && v[i] > 0) count++;

    }

    printf("%d\n", count);



}