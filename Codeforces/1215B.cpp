#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;
 
signed main() {
        int n;
        cin >> n;
        
        int a[n];
        int ans = 0;
        int odd = 0, even = 0;
        for(int i = 0; i < n; i++) {
                cin >> a[i];
                if(a[i] >= 0) {
                        even++;
                }
                else {
                        swap(odd,even);
                        odd++;
                }
                ans += odd;
        }
        
        int tot = (n * (n +  1)) / 2;
        
        cout << ans << " " << tot - ans << endl;
	
	return 0;
}
