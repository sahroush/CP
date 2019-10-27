#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 1e5+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);


int n , m;

set <int> st[110];
map<int , int> mp;

int main (){
    migmig;
    cin >> n >> m;
    int cnt= 0 ;
    for (int i = 0 ; i < n ; i ++){
        int sz , inp;
        cin >> sz;
        if (sz == 0){
            cnt++;
        }
        for (int j = 0; j < sz ; j ++){
            cin >> inp;
            st[inp].insert(i+1);
            //cout << inp << '\t' << i+1 << endl;
        }
    }
    for (int i  = 1 ; i <=m ; i ++ ){
        mp[i] = i;
        if (st[i].size() == 0){
            mp[i] = 0;
        }
    }

    for (int  i = 1 ; i<=m ; i ++){
        for (int j =i + 1 ; j <= m ; j ++){
            if (i!=j and mp[i]!=0 and mp[j]!=0){
            std::set<int>::iterator it = st[i].begin();
            while (it!= st[i].end()){
                if (it == st[i].begin()){
                    if (st[j].count(*it)){
                        int mn = min(mp[j] , mp[i]);
                        mp[i] = mn;
                        mp[j] = mn;
                        break;
                    }
                }
                if (it == --st[i].end()){
                    break;
                }
                it ++;
                if (st[j].count(*it)){
                    int mn = min(mp[j] , mp[i]);
                    mp[i] = mn;
                    mp[j] = mn;
                    break;
                }
            }
        }
        }
    }
    set <int> ans;


    for (int i = 1 ; i <=m ; i ++){
        if (mp[i]!= 0 ) ans.insert(mp[i])   ;
    }
    int sz = ans.size();
    cout << max(sz-1 , 0) + cnt;



    return (0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
