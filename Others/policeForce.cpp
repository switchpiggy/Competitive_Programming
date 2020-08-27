#include <bits/stdc++.h>

using namespace std;

int main() {

    int num, crimes = 0;

    int police = 0, s;

    scanf("%d", &num);

    for(int i = 0; i < num; ++i) {

        scanf("%d", &s);

        if(s > 0) police += s;

        else {

            if(police == 0) crimes++;

            else police -= 1;

        }

    }

    printf("%d\n", crimes);

}