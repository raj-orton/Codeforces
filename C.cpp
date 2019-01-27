#include <bits/stdc++.h>
using namespace std;

#define lli long long
#define pii pair<lli,lli>

int main() {
    
    int t;
    cin >> t;
    
    while(t--) {
        int k, m, n;
        cin >> k >> m >> n;
        int a[n];
        int sum = 0;
        for(int i = 0; i < n; i++)
            cin >> a[i], sum += a[i];
        
        sort(a, a+n);
        reverse(a, a+n);
        
        sum = k - sum;
        int ans = 0;
        for(int i = 0; i < n && sum < m; i++) 
            ans++, sum += a[i];
        
        cout << ans << endl;
    }
    
	return 0;
}
