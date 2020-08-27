#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;

    set<char> c = {'a', 'e', 'i', 'o', 'u', 'y'};

    cin >> s;

    for(int i = 0; i < s.length(); ++i) {

        if(c.find(tolower(s[i])) == c.end()) {
        	
        	printf(".");
        	
        	printf("%c", tolower(s[i]));
        	
        }

    }

    

}