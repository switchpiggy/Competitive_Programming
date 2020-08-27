#include <bits/stdc++.h>

using namespace std;

int main() {

    double a, x, y;

    scanf("%lf %lf %lf", &a, &x, &y);

    int ay = a;
    
    int yy = y;

    bool flag = false;

    int numRow = floor(y/a) + 1;
    
    if(y == 0 || yy % ay == 0) {
    	
    	printf("-1");
    	
    	return 0;
    	
    }

    if(numRow == 1 || numRow == 2 || (numRow > 3 && (numRow - 3) % 2 == 1)) {

        if(x <= -1 * (a/2) || x >= (a/2)) printf("-1");

        else {

            int res;

            if(numRow == 1 || numRow == 2) res = numRow;

            else res = (numRow/2) * 3 - 1;

            printf("%d", res);

        }

    } else {

        if(x <= -1 * a || x >= a || x == 0) printf("-1");

        else {

            int res;

            if(numRow == 3) {

                if(x < 0) res = 3;

                else res = 4;

            } else if(x < 0) {

                res = ((numRow + 1)/2) * 3 - 3;

            } else if(x > 0) {

                res = ((numRow + 1)/2) * 3 - 2;

            }

            printf("%d", res);

        }

    }

}