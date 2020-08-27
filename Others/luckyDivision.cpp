#include <bits/stdc++.h>

using namespace std;

bool lucky(int x) {
	
	string s = to_string(x);
	
	for(int i = 0; i < s.length(); ++i) {
		
		if(s[i] != '4' && s[i] != '7') return false;
		
	}
	
	return true;
	
}	

int main() {

    int num;
    
    bool flag = false;

    scanf("%d", &num);

    for(int i = 1; i <= num; ++i) {

        if(num%i == 0 && lucky(i)) {

            printf("YES\n");
            
            flag = true;

            break;

        }

    }
    
    if(flag == false) printf("NO\n");

}