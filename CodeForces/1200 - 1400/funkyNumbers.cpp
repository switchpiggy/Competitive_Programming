#include <bits/stdc++.h>

using namespace std;

long long const int N = 1e5 + 1;

long long int n;

long long int a[N];

int main() {

    scanf("%lld", &n);

    a[0] = 0;

    for(int i = 1; i < N; ++i) a[i] = a[i - 1] + i;

    for(int i = 1; i < N; ++i) {

        if(binary_search(a + 1, a + N, n - a[i])) {

            printf("YES");

            return 0;

        }

    }

    printf("NO");

}