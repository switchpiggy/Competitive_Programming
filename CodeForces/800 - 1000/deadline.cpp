#include <bits/stdc++.h>

using namespace std;

int main() {

    double n, d;

    int t;

    scanf("%d", &t);

    while(t--) {

        bool flag = false;

        scanf("%lf %lf", &n, &d);

        for(int i = 0; i <= n; ++i) {

            if(i + ceil(d/(i + 1)) <= n) {

                printf("YES\n");

                flag = true;

                break;

            }

        }

        if(!flag) printf("NO\n");



    }

    

}