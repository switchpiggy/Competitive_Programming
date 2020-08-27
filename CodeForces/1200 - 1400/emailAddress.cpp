#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string email;

int main() {
    cin >> email;
    for(ll i = 1; i < email.length() - 2; ++i) {
        if(email[i] == 'a' && email[i + 1] == 't') {
            email[i] = '@';
            email.erase(i + 1, 1);
            break;
        }
    }

    for(ll i = 1; i < email.length() - 3; ++i) {
        if(email[i] == 'd' && email[i + 1] == 'o' && email[i + 2] == 't') {
            email[i  + 1] = '.';
            email.erase(i, 1);
            email.erase(i + 1, 1);
        }
    }

    cout << email << endl;
}