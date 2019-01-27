#include <bits/stdc++.h>
using namespace std;

#define lli long long
#define pii pair<lli,lli>
#define ff first
#define ss second
const lli MOD = (lli) 1e9 + 7;

class disjoint_set
{
    public :
        vector<int> r, p;
        disjoint_set(int n) {
            r.resize(n+5, 0);
            p.resize(n+5);
            for(int i = 0; i <= n; i++)
                p[i] = i;
        }
        int find_set(int i) {
            return (p[i] == i) ?i :(p[i] = find_set(p[i]));
        }
        int same_set(int i, int j) {
            return find_set(i) == find_set(j);
        }
        void union_set(int i, int j) {
            if(!same_set(i, j)) {
                int x = find_set(i), y = find_set(j);
                if(r[y] < r[x])
                    p[y] = x;
                else {
                    p[x] = y;
                    if(r[x] == r[y])
                        r[y]++;
                }
            }
        }
};

lli modularExponentiation(lli x,lli n,lli M) {
    lli result = 1;
    while(n > 0) {
        if(n % 2 == 1)
            result = (result * x) % M;
        x = (x * x) % M;
        n = n / 2;
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        
        int n, m;
        cin >> n >> m;
        
        string s;
        cin >> s;
        s = '.'+s;
        
        disjoint_set dsu(n);
        
        for(int i  = 1; i <= n; i++) 
            dsu.union_set(i, n - i + 1);
        
        int l, r;
        for(int i = 0; i < m; i++) {
            cin >> l >> r;
            dsu.union_set(l, r);
        }
        
        set<char> st[n+5];
        for(int i = 1; i <= n; i++)
            st[dsu.find_set(i)].insert(s[i]);
        
        lli x = 0, cant = 0;
        for(int i = 1; i <= n; i++) {
            if(st[i].size() == 0)
                continue;
            if(st[i].size() == 1) { 
                if(*st[i].begin() == '?')
                    x++;
                continue;
            }
            if(st[i].size() == 2) {
                int flag = 0;
                for(auto i : st[i])
                    if(i == '?')
                        flag = 1;
                if(flag != 1)
                    cant = 1;
                continue;
            }
            cant = 1;
            break;
        }
        
        if(cant)
            cout << 0 << endl;
        else
            cout << modularExponentiation(26LL, x, MOD) << endl;
        
    }
	  return 0;
}
