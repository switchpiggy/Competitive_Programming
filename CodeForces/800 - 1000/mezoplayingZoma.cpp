#include <bits/stdc++.h>

using namespace std;

int main() {

    int count;

    int lc = 0, rc = 0;

    scanf("%d", &count);

    for(int i = 0; i < count; ++i) {

        char c;

        scanf("%c", &c);
        
        if(c == 'R') rc++;

        else lc--;

    }



    printf("%d\n", rc - lc + 1);

    return 0;

}