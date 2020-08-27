#include <bits/stdc++.h>

using namespace std;

#define s(n) scanf("%d", &n);

int main() {

    int n, m, k, sum = 0;

    vector<int> v;

    s(n);

    s(m);

    s(k);

    int diff = n - k;

    int i;

    s(i);

    for(int a = 1; a < n; ++a) {

        int c;

        s(c);

        v.push_back(c-  i);

        i = c;

    }

    sort(v.begin(), v.end());

    for(int i = 0; i < diff; ++i) sum += v[i];

    printf("%d", sum + k);
}