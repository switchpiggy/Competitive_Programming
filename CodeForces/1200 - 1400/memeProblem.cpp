#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;

    scanf("%d", &t);

    while(t--) {

        int d;

        scanf("%d", &d);

        bool flag = false;

        int low = 0;

        int high = d;

        while(low <= high) {

            if(low * high < d) low++;

            else if(low * high > d) high--;

            else {

                flag = true;

            }
        }

    }

}