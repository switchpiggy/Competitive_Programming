#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;string s;
	cin>>n;
	while(n--) {
		cin>>s;
		if(s[s.size()-1]=='o') cout<<"FILIPINO\n";
		else if(s[s.size()-1]=='u') cout<<"JAPANESE\n";
		else cout<<"KOREAN\n";
	}
	return 0;
}