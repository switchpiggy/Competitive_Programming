#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;

    scanf("%d", &n);

    int one = 0, two = 0, three = 0;

    for(int i = 0; i < n; ++i) {

        int a;

        scanf("%d", &a);

        if(a%3 == 0) three++;

        else if(a%3 == 1) one++;

        else if(a%3 == 2) two++;

    }

    printf("%d", three/2 + min(one, two));

}