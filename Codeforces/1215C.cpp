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
        
        string s, t;
        cin >> s >> t;
        
        vector<int> ab, ba;
        for(int i = 0; i < n; i++) {
                if(s[i] != t[i]) {
                        if(s[i] == 'a')
                                ab.push_back(i);
                        else
                                ba.push_back(i);
                }
        }
        
        int x = ab.size();
        int y = ba.size();
        int tot = x + y;
        if(tot & 1) {
                cout << -1 << endl;
                return 0;
        }
        
        vector<pii> ans;
        
        int i = 0, j = 0;
        while(true) {
                if(i >= x && j >= y) {
                        break;
                }
                if(i + 1 < x) {
                        ans.push_back({ab[i], ab[i + 1]});
                        i += 2;
                        continue;
                }
                if(j + 1 < y) {
                        ans.push_back({ba[j], ba[j + 1]});
                        j += 2;
                        continue;
                }
                ans.push_back({ab[i], ab[i]});
                ans.push_back({ab[i], ba[j]});
                i++; j++;
        }
        
        cout << ans.size() << endl;
        for(pii it : ans)
                cout << it.ff + 1 << " " << it.ss + 1 << endl;
        
	return 0;
}
