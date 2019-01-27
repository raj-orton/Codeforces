#include <bits/stdc++.h>
using namespace std;

#define lli long long
#define pii pair<lli,lli>

int main() {
    
    int t;
    cin >> t;
    
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        
        if((a > 0 && b > 0 && c > 0) && a + b + c == 180)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
	return 0;
}
