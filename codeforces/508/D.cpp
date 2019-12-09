#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =10e5+10;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ms(x , y) memset(x , y , sizeof x);
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n;
stack <int> ans;
int name[75*75][75*75];
pii tag[maxn];
int deg[maxn];
int indx[maxn];
int in[maxn] , out[maxn] , par[maxn];
vector <int> adj[maxn];
bool mark[maxn];

void dfs(int v){
    while(indx[v] < adj[v].size()){
        dfs(adj[v][indx[v]++]);
    }
    ans.push(v);
}



int main(){
    migmig
    cin >> n;
    ms(deg , 0);
    ms(indx , 0);
    int cnt = 0;
    for (int i = 0 ; i < 75 ; i ++){
        for (int j = 0 ; j < 75 ; j ++){
            name[i][j] = cnt;
            tag[cnt] = make_pair(i , j);
            ++cnt;
        }
    }
    int thechosenone = -1;
    for (int i = 0 ; i < n; i ++){
        string inp;
        cin >> inp;
        deg[name[(int)inp[0] -  48][(int)inp[1] - 48]]++;
        deg[name[(int)inp[1] -  48][(int)inp[2] - 48]]++;
        out[name[(int)inp[0] -  48][(int)inp[1] - 48]]++;
        in[name[(int)inp[1] -  48][(int)inp[2] - 48]]++;
        adj[name[(int)inp[0] -  48][(int)inp[1] - 48]].pb(name[(int)inp[1] - 48][(int)inp[2] - 48]);
        mark[name[(int)inp[0] -  48][(int)inp[1] - 48]] = 1;
        mark[name[(int)inp[1] -  48][(int)inp[2] - 48]] = 1;
        if(thechosenone == -1){
            thechosenone = name[(int)inp[0] -  48][(int)inp[1] - 48];
        }
    }
    int cnt2 = 0;
    for (int i =0 ;  i < 75*75 ; i ++){
        cnt2 += abs(in[i] - out[i]);
    }
    cnt = 0 ;
    int pos  = -1;
    for (int i = 0 ; i < 75 ; i ++){
        for (int j = i ; j < 75 ; j ++){
            if(deg[name[i][j]]%2){
                cnt++;
            }
        }
    }
    if(cnt > 2 or cnt2 > 2){
        dokme("NO");
    }
    if(cnt2 == 2  ){
        for (int i =0 ;  i < 75*75 ; i ++){
            if(out[i] > in[i]){
                dfs(i);
                break;
            }
        }
    }
    else{
        dfs(thechosenone);
    }
    if(ans.size()!=n+1){
        dokme("NO");
    }
    cout << "YES" << endl;
    cout << (char)(tag[ans.top()].first + 48);
    while(!ans.empty()){
        cout << (char)(tag[ans.top()].second+ 48);
        ans.pop();
    }
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
