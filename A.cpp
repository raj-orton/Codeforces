#include <bits/stdc++.h>
using namespace std;

#define lli long long
#define pii pair<lli,lli>

int parse(string s) {
    int ans = 0;
    int minus = 0;
    for(int i = 0; i < s.size(); i++) {
        if(i == 0 && s[i] == '-') {
            minus = 1;
            continue;
        }
        ans = ans * 10 + (s[i] - '0');
    }
    if(minus)
        return -ans;
    return ans;
}

int main() {
    
    int t;
    cin >> t;
    
    while(t--) {
        string s[3];
        cin >> s[0] >> s[1] >> s[2];
        int x = parse(s[0]);
        int y = parse(s[2]);
        if(s[1] == "!=") {
            if(x != y) cout<<"true\n";
            else cout<<"false\n";
        }
        if(s[1] == "=="){
            if(x == y) cout<<"true\n";
            else cout<<"false\n";
        }
        if(s[1] == "<"){
            if(x < y) cout<<"true\n";
            else cout<<"false\n";
        }
        if(s[1] == "<="){
            if(x <= y) cout<<"true\n";
            else cout<<"false\n";
        }
        if(s[1] == ">"){
            if(x > y) cout<<"true\n";
            else cout<<"false\n";
        }
        if(s[1] == ">="){
            if(x >= y) cout<<"true\n";
            else cout<<"false\n";
        }
    }
    
	return 0;
}
