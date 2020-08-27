/*

The code that follows will make you confused and depressed. If this would help, I would like to provide a safety pig for your viewing pleasure.
.
                         _
 _._ _..._ .-',     _.._(`))
'-. `     '  /-._.-'    ',/
   )         \            '.
  / _    _    |             \
 |  a    a    /              |
 \   .-.                     ;  
  '-('' ).-'       ,'       ;
     '-;           |      .'
        \           \    /
        | 7  .__  _.-\   \
        | |  |  ``/  /`  /
       /,_|  |   /,_/   /
          /,_/      '`-'

*/

#include <bits/stdc++.h>

using namespace std;

int main() {

    int numCases;

    scanf("%d", &numCases);

    while(numCases--) {

        string p;

        string hash;

        bool flag = false;

        cin >> p >> hash;

        sort(p.begin(), p.end());

        for(int i = 0; i + p.length() <= hash.length(); ++i) {

            string r = hash.substr(i, p.length());

            sort(r.begin(), r.end());

            if(r.compare(p) == 0) {

                printf("YES\n");

                flag = true;

                break;

            }

        }

        if(flag == false) printf("NO\n");
    }

    return 0;

}