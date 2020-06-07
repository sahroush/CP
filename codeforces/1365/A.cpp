#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n , m;
int a[100][100];

int main(){
    migmig
    cin >> q;
    while(q -- ){
        cin >> n >> m;
        set < int > r , c;
        r.clear();
        c.clear();
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                cin >> a[i][j];
                if(a[i][j])
                    r.insert(i) , c.insert(j);
            }
        }
        int cnt = 0;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                if(r.count(i))continue;
                if(c.count(j))continue;
                cnt++;
                r.insert(i) , c.insert(j);
            }
        }
        cout << ((cnt%2)?"Ashish":"Vivek") << endl;

    }




    return(0);
}