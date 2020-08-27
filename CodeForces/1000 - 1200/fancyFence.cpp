#include <bits/stdc++.h>

using namespace std;

#define s(n) scanf("%d", &n);

int main() {

    int t, angle;

    s(t);

    while(t--) {

        bool flag = false;

        s(angle);

        if(angle < 60) {

            printf("NO\n");

            continue;

        }

        for(int i = 3; i <= 360; ++i) {

            if(angle == 180 - (360/i) && 360%i == 0) {

                printf("YES\n");

                flag = true;

                break;

            }

        }

        if(!flag) printf("NO\n");

    }

    return 0;




}