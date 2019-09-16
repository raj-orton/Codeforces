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
        
        string s;
        cin >> s;
        
        int lsum = 0;
        int rsum = 0;
        int l = 0, r = 0;
        for(int i = 0; i < n; i++) {
                if(i < n / 2) {
                        if(s[i] == '?') l++;
                        else lsum += s[i] - '0';
                }
                else {
                        if(s[i] == '?') r++;
                        else rsum += s[i] - '0';
                }
        }
        
        int turn = 0;
        while(true) {
                if(l == 0 && r == 0) {
                        break;
                }
                if(turn == 0) {
                        if(lsum > rsum) {
                                if(l > 0) {
                                        l--, lsum += 9;
                                }
                                else {
                                        r--, rsum += 0;
                                }
                        }
                        else if(lsum == rsum) {
                                if(l > r) {
                                        l--, lsum += 9;
                                }
                                else {
                                        r--, rsum += 9;
                                }
                        }
                        else {
                                if(r > 0) {
                                        r--, rsum += 9;
                                }
                                else {
                                        l--, lsum += 0;
                                }
                        }
                }
                else {
                        if(lsum > rsum) {
                                if(r > 0) {
                                        r--, rsum += 9;  
                                }
                                else { 
                                        l--, lsum += 0;
                                }
                        }
                        else if(lsum == rsum) {
                                if(l > r) {
                                        l--, lsum += 0;
                                }
                                else {
                                        r--, rsum += 0;
                                }
                        }
                        else {
                                if(l > 0) {
                                        l--, lsum += 9;  
                                }
                                else {
                                        r--, rsum += 0;
                                }
                        }
                }
                turn = 1 - turn;
        }
        if(lsum == rsum) {
                cout << "Bicarp";
        }
        else {
                cout << "Monocarp";
        }
        
	return 0;
}
