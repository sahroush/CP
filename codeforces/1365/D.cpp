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

int t;
int n , m;
string s[maxn];
queue < pii > q;

bool hb(int i ,int j){
    return(s[i][j] == 'B');
}

bool bad(int i , int j){
    bool ok=0;
    if(i){
        ok |= hb(i-1 , j);
    }
    if(j){
        ok |= hb(i , j - 1);
    }
    if(i < n - 1){
        ok |= hb(i+1 , j);
    }
    if(j < m - 1){
        ok |= hb(i , j+1);
    }
    return(ok);
}

int main(){
    migmig
    cin >> t;
    while(t -- ){
        cin >> n >> m;
        for(int i = 0 ; i < n ; i ++)
            cin >> s[i];
        bool ok = 1;
        for(int i = 1 ; i < n - 1 ; i ++)
            for(int j = 1 ; j < m - 1 ; j ++){
                if(s[i][j] == '#')continue;
                if(s[i][j] == '.')continue;
                if(s[i][j] == 'G')
                    if(s[i - 1][j] == 'B' or s[i+1][j] == 'B' or s[i][j+1] == 'B' or s[i][j - 1] == 'B')
                        ok = 0;
                if(s[i][j] == 'B')
                    if(s[i - 1][j] == 'G' or s[i+1][j] == 'G' or s[i][j+1] == 'G' or s[i][j - 1] == 'G')
                        ok = 0;
            }
        bool hh = 0;
        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < m ; j ++)
                hh |= (s[i][j] == 'G');
        if(!hh){
            cout << "Yes" << endl;
            continue;
        }
        if(bad(n-1 , m - 1)){
            cout << "No" << endl;
            continue;
        }
        q.push({n- 1 , m - 1});
        while(!q.empty()){
            pii v = q.front();
            q.pop();
            if(v.first > 0){
                if(s[v.first - 1][v.second]!='#' and !bad(v.first - 1,v.second)){
                    s[v.first - 1][v.second] = '#';
                    q.push({v.first - 1,v.second});
                }
            }
            if(v.first < n-1){
                if(s[v.first + 1][v.second]!='#' and !bad(v.first + 1,v.second)){
                    s[v.first + 1][v.second] = '#';
                    q.push({v.first + 1,v.second});
                }
            }
            if(v.second > 0){
                if(s[v.first ][v.second-1]!='#' and (!bad(v.first,v.second-1)) ){
                    s[v.first][v.second-1] = '#';
                   q.push({v.first,v.second-1});
                }
            }
            if(v.second < m-1){
                if(s[v.first ][v.second+1]!='#' and (!bad(v.first,v.second+1))){
                    s[v.first][v.second+1] = '#';
                    q.push({v.first,v.second+1});
                }
            }
        }
        hh = 0;
        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < m ; j ++)
                hh |= (s[i][j] == 'G');
        if(hh)
            ok = 0;
        cout << ((ok)?"Yes":"No") << endl;

    }




    return(0);
}