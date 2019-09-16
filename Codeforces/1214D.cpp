#include <bits/stdc++.h> 
#define int long long
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;

signed main() {
    
        int n, m;
        cin >> n >> m;
        
        char s[n][m];
        for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                        cin >> s[i][j];
        
        bool src[n][m] = {};
        for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                        if(s[i][j] == '#') {
                                continue;
                        }
                        bool can = false;
                        if(i == 0 && j == 0) {
                                can = true;
                        }
                        if(i > 0) {
                                can = can | src[i - 1][j];
                        }
                        if(j > 0) {
                                can = can | src[i][j - 1];
                        }
                        src[i][j] = can;
                }
        }
        
        bool des[n][m] = {};
        for(int i = n - 1; i >= 0; i--) {
                for(int j = m - 1; j >= 0; j--) {
                        if(s[i][j] == '#') {
                                continue;
                        }
                        bool can = false;
                        if(i == n - 1 && j == m - 1) {
                                can = true;
                        }
                        if(i < n - 1) {
                                can = can | des[i + 1][j];
                        }
                        if(j < m - 1) {
                                can = can | des[i][j + 1];
                        }
                        des[i][j] = can;
                }
        }
        
        int lvl[n + m + 5] = {};
        for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                        if(src[i][j] && des[i][j]) {
                                lvl[i + j]++;
                        }
                }
        }
        
        int ans = 2;
        if(!src[n - 1][m - 1] || !des[0][0]) {
                ans = 0;
        }
        else {
                for(int i = 1; i < n + m - 2; i++)
                        if(lvl[i] == 1)
                                ans = 1;
        }
        cout << ans << endl;
        
        return 0;
}
