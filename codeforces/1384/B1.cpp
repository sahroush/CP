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

int qq;
int n , k , l;
int a[200][200];
queue < pii > q;
bool mark[200][200];

int main(){
    migmig
    cin >> qq;
    while(qq -- ){
        cin >> n >> k >> l;
        ms(mark , 0);
        for(int i = 0 ; i < n ; i ++)
            cin >> a[0][i];
        for(int i = 1 ; i  <= k ; i ++)
            for(int j = 0 ; j < n ; j ++)
                a[i][j] = a[i-1][j]+1;
        for(int i = k+1 ; i <= 2*k-1 ; i ++){
            for(int j = 0 ; j < n ; j ++)
                a[i][j] = a[i-1][j]-1;
        }
        for(int i = 0 ; i <= 2*k - 1 ; i ++){
            if(a[i][0] <= l){
                q.push({i , 0});
                mark[i][0] = 1;
            }
        }
        while(!q.empty()){
            auto [i , j] = q.front();
            q.pop();
            if(a[(i+1)%(2*k)][j] <= l and !mark[(i+1)%(2*k)][j]){
                mark[(i+1)%(2*k)][j] = 1;
                q.push({(i+1)%(2*k), j});
            }
            if(j+1 <= n-1 and a[(i+1)%(2*k)][j+1] <= l and !mark[(i+1)%(2*k)][j+1]){
                mark[(i+1)%(2*k)][j+1] = 1;
                q.push({(i+1)%(2*k), j+1});
            }
        }
        bool ok = 0;
        for(int i = 0 ; i <= 2*k-1 ; i ++)
            ok|=mark[i][n-1];
        if(ok)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }





    return(0);
}