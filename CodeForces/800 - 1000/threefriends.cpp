#include <bits/stdc++.h>

using namespace std;

#define s(n) scanf("%d", &n)

int count(int a, int b, int c) {

    return abs(a-b) + abs(a - c) + abs(b - c);

}

int main() {

    int arr[3], t;

    s(t);

    while(t--) {

        int res = INT_MAX;

        s(arr[0]);

        s(arr[1]);

        s(arr[2]);

        sort(arr, arr + 3);

        for(int i = -1; i <= 1; ++i) {
            for(int j = - 1; j <= 1; ++j) {
                for(int k = -1; k <= 1; ++k) {
    
                    res = min(res, count(arr[0] + i, arr[1] + j, arr[2] + k));

                }
            }
        }

        printf("%d\n", res);



    }

}