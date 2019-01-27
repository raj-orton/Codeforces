#include <bits/stdc++.h>
using namespace std;

#define lli long long
#define pii pair<lli,lli>

int n = 9;
int a[10][10];

int check_row(int c) {
    int f[10] = { };
    for(int i = 0; i < n; i++) 
        f[a[i][c]]++;
    return *max_element(f, f+10) == 1;
}

int check_col(int r) {
    int f[10] = { };
    for(int i = 0; i < n; i++) 
        f[a[r][i]]++;
    return *max_element(f, f+10) == 1;
}

int check_sub(int r, int c) {
    int f[10] = { };
    for(int i = 0; i < 3; i++) 
        for(int j = 0; j < 3; j++)
            f[a[r+i][c+j]]++;
    return *max_element(f, f+10) == 1;
}

int main() {
    
    int t;
    cin >> t;
    
    while(t--) {
        
        string s[n];
        for(int i = 0; i < n; i++)
            cin >> s[i];
            
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                a[i][j] = (s[i][j] - '0');
        
        int ok = 0;
        
        for(int i = 0; i < n; i++) {
            ok += check_row(i) * 1;
            ok += check_col(i) * 1;
        }
        
        for(int i = 0; i < n; i += 3)
            for(int j = 0; j < n; j += 3)
                ok += check_sub(i, j) * 1;
        
        cout << (ok == 27 ?"Valid" :"Invalid") << endl;
        
    }
    
	return 0;
}
