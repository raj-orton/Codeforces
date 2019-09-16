#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;
 
signed main() {
        int a1, a2, k1, k2, n;
        cin >> a1 >> a2 >> k1 >> k2 >> n;
        
        int mi = max(0LL, n - ((k1 - 1) * a1) - ((k2 - 1) * a2));
        int ma = 0LL;
        if(k1 > k2) {
                swap(k1, k2);
                swap(a1, a2);
        }
        
        int can = min(n / k1, a1);
        n = n - can * k1;
        ma += can;
        
        can = min(n / k2, a2);
        n = n - can * k2;
        ma += can;
        
        cout << mi << " " << ma << endl;
	
	return 0;
}
