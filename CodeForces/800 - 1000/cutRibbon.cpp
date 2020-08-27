#include <bits/stdc++.h>

using namespace std;

#define s(n) scanf("%d", &n);

int main() {

    int n, a, b, c;

    int count = INT_MIN;

    s(n);

    s(a);

    s(b);

    s(c);

    for(int i = 0; i <= n/a; ++i) {
      
        for(int j = 0; j <= n/b; ++j) {

            if(a * i + b * j > n) break;
        	
        	int k = n - (a * i) - (b * j);

            if(k%c == 0 && k >= 0) count = max(count, i + j + k/c);

        }
    }
    
    printf("%d", count);

}