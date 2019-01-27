#include <bits/stdc++.h>
using namespace std;

#define lli long long
#define pii pair<lli,lli>
#define ff first
#define ss second

const lli MOD = (lli) 1e9 + 7;
const int N = 10101;
lli a[N];

lli nc2(lli n) {
    if(n < 2)
        return 0;
    return ((n * (n - 1)) / 2);
}

int main() {
	
	lli t;
	cin >> t;
	
	while(t--) {
	    
	    lli n;
	    cin >> n;
	    
	    for(int i = 0; i < n; i++)
	        cin >> a[i];
	    a[n] = 1e6;
	    sort(a, a + n);
	    
	    lli ans = 0;
	    lli l = 0, r = 0, last = -1;
	    while(l <= n && r <= n) {
	        if(a[r] - a[l] < 32)
	            r++;
	        else {
	            ans += nc2(r - l);
	            ans -= nc2(last - l);
	            last = r;
	            l++;
	        }
	    }
	    cout << ans << endl;
	}
	return 0;
}
