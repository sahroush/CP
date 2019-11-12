#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const ll maxn = 1e3+100;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }

ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

/*
bool setmin(int a , int b){
    if (b < a){
        a = b;
        return(1);
    }
    return(0);
}
*/

int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};
int n , m;
int dist[3][maxn][maxn], inf;
char s[maxn][maxn];

void pre(int cur) {
    char target=char('1'+cur);
    memset(dist[cur], 50 , sizeof(dist[cur])); inf=dist[cur][0][0];
    queue<pii> q;
    bool inside[maxn][maxn]; memset(inside, 0 , sizeof(inside));
    for(int i = 1; i <= n; i++){
        for(int j = 1;j <=m; j++){
            if(s[i][j]==target) {
                inside[i][j]=true;
                dist[cur][i][j]=0;
                q.push(make_pair(i, j));
            }
        }
    }
    while(!q.empty()){
        int x=q.front().first, y=q.front().second;
        q.pop();
        inside[x][y]=false;
        for(int k = 0; k < 4 ; k++) {
            int x0=x+dx[k], y0=y+dy[k];
            if(x0<1 || x0>n || y0<1 || y0>m || s[x0][y0]=='#') continue;
            int d=dist[cur][x][y];
            if(s[x0][y0]=='.') ++d;
            if(setmin(dist[cur][x0][y0], d)) {
                dist[cur][x0][y0] = d;
                if(!inside[x0][y0]) {
                    inside[x0][y0]=true;
                    q.push(make_pair(x0, y0));
                }
            }
        }
    }
}

int main (){
    
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        scanf("%s", s[i]+1);
    }
    /*
    set <int> ct1 , ct2 ,ct3;
    ll dist1[maxn] , dist2[maxn] , dist3[maxn] , ans = 1e9;
    map < int , pii > pos;
    map < pii , int > name;
    queue < int > q;
    bool mark[maxn];
    int cnt = 3;
    for (int i = 0; i < n; i ++){
        for (int j = 0 ; j < m ; j ++){
            if (s[i][j] == '.'){
                ++cnt;
                pos[cnt] = make_pair(i , j);
                name[make_pair(i , j)] = cnt;
            }
        }
    }
    for (int i = 0;  i < n; i ++){
        for(int j = 0 ; j < m ; j ++){
            if (s[i][j] == '1'){
                if (name.count(make_pair(i-1 , j))){
                    ct1.insert(name[make_pair(i - 1 , j)]);
                    //vec[name[make_pair(i-1 , j)]].pb(1);
                }
                if (name.count(make_pair(i+1 , j))){
                    ct1.insert(name[make_pair(i + 1 , j)]);
                    //vec[name[make_pair(i+1 , j)]].pb(1);
                }
                if (name.count(make_pair(i , j-1))){
                    ct1.insert(name[make_pair(i  , j - 1)]);
                    //vec[name[make_pair(i , j - 1)]].pb(1);
                }
                if (name.count(make_pair(i , j+1))){
                    ct1.insert(name[make_pair(i , j + 1)]);
                    //vec[name[make_pair(i , j + 1)]].pb(1);
                }
            }
            if (s[i][j] == '2'){
                if (name.count(make_pair(i-1 , j))){
                    ct2.insert(name[make_pair(i - 1 , j)]);
                    //vec[name[make_pair(i-1 , j)]].pb(1);
                }
                if (name.count(make_pair(i+1 , j))){
                    ct2.insert(name[make_pair(i + 1 , j)]);
                    //vec[name[make_pair(i+1 , j)]].pb(1);
                }
                if (name.count(make_pair(i , j-1))){
                    ct2.insert(name[make_pair(i  , j - 1)]);
                    //vec[name[make_pair(i , j - 1)]].pb(1);
                }
                if (name.count(make_pair(i , j+1))){
                    ct2.insert(name[make_pair(i , j + 1)]);
                    //vec[name[make_pair(i , j + 1)]].pb(1);
                }
            }
            if (s[i][j] == '3'){
                if (name.count(make_pair(i-1 , j))){
                    ct3.insert(name[make_pair(i - 1 , j)]);
                    //vec[name[make_pair(i-1 , j)]].pb(1);
                }
                if (name.count(make_pair(i+1 , j))){
                    ct3.insert(name[make_pair(i + 1 , j)]);
                    //vec[name[make_pair(i+1 , j)]].pb(1);
                }
                if (name.count(make_pair(i , j-1))){
                    ct3.insert(name[make_pair(i  , j - 1)]);
                    //vec[name[make_pair(i , j - 1)]].pb(1);
                }
                if (name.count(make_pair(i , j+1))){
                    ct3.insert(name[make_pair(i , j + 1)]);
                    //vec[name[make_pair(i , j + 1)]].pb(1);
                }
            }
        }
    }
    q.push(1);
    mark[1] = 1;
    dist1[1] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if (v == 1 or v == 2 or v == 3){
            std::set <int> :: iterator it;
            if (v == 1){
                for (it = ct1.begin() ; it!=ct1.end() ; it++){
                    if (!mark[*it]){
                        dist1[*it] = dist1[v]+1;
                        q.push(*it);
                        mark[*it] = 1;
                    }
                }
            }
            if (v == 2){
                for (it = ct2.begin() ; it!=ct2.end() ; it++){
                    if (!mark[*it]){
                        dist1[*it] = dist1[v]+1;
                        q.push(*it);
                        mark[*it] = 1;
                    }
                }
            }
            if (v == 3){
                for (it = ct3.begin() ; it!=ct3.end() ; it++){
                    if (!mark[*it]){
                        dist1[*it] = dist1[v]+1;
                        q.push(*it);
                        mark[*it] = 1;
                    }
                }
            }
        }
        else{
            int x  = pos[v].first , y = pos[v].second;
            if (ct1.find(name[pos[v]])!=ct1.end()){
                if (!mark[1]){
                    mark[1] = 1;
                    q.push(1);
                    dist1[1] = dist1[v];
                }
            }
            if (ct2.find(name[pos[v]])!=ct2.end()){
                if (!mark[2]){
                    mark[2] = 1;
                    q.push(2);
                    dist1[2] = dist1[v];
                }
            }
            if (ct3.find(name[pos[v]])!=ct3.end()){
                if (!mark[3]){
                    mark[3] = 1;
                    q.push(3);
                    dist1[3] = dist1[v];
                }
            }
            if (x){
                if (!mark[name[make_pair(x - 1 , y)]]){
                    mark[name[make_pair(x - 1 , y)]] = 1;
                    q.push(name[make_pair(x - 1 , y)]);
                    dist1[name[make_pair(x - 1 , y)]] = dist1[v] + 1;
                }
            }
            if (y){
                if (!mark[name[make_pair(x  , y - 1)]]){
                    mark[name[make_pair(x  , y - 1)]] = 1;
                    q.push(name[make_pair(x , y - 1)]);
                    dist1[name[make_pair(x  , y - 1)]] = dist1[v] + 1;
                }
            }
            if (x < n){
                if (!mark[name[make_pair(x + 1 , y)]]){
                    mark[name[make_pair(x + 1 , y)]] = 1;
                    q.push(name[make_pair(x + 1 , y)]);
                    dist1[name[make_pair(x + 1 , y)]] = dist1[v] + 1;
                }
            }
            if (y < n){
                if (!mark[name[make_pair(x  , y + 1)]]){
                    mark[name[make_pair(x  , y +1)]] = 1;
                    q.push(name[make_pair(x , y +1)]);
                    dist1[name[make_pair(x , y + 1)]] = dist1[v] + 1;
                }
            }
        }
    }
    if(!mark[1] or !mark[2] or !mark[3]){dokme(-1);}
    memset(mark , 0 , sizeof(mark));
    q.push(2);
    mark[2] = 1;
    dist2[2] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if (v == 1 or v == 2 or v == 3){
            std::set <int> :: iterator it;
            if (v == 1){
                for (it = ct1.begin() ; it!=ct1.end() ; it++){
                    if (!mark[*it]){
                        dist2[*it] = dist2[v]+1;
                        q.push(*it);
                        mark[*it] = 1;
                    }
                }
            }
            if (v == 2){
                for (it = ct2.begin() ; it!=ct2.end() ; it++){
                    if (!mark[*it]){
                        dist2[*it] = dist2[v]+1;
                        q.push(*it);
                        mark[*it] = 1;
                    }
                }
            }
            if (v == 3){
                for (it = ct3.begin() ; it!=ct3.end() ; it++){
                    if (!mark[*it]){
                        dist2[*it] = dist2[v]+1;
                        q.push(*it);
                        mark[*it] = 1;
                    }
                }
            }
        }
        else{
            int x  = pos[v].first , y = pos[v].second;
            if (ct1.find(name[pos[v]])!=ct1.end()){
                if (!mark[1]){
                    mark[1] = 1;
                    q.push(1);
                    dist2[1] = dist2[v];
                }
            }
            if (ct2.find(name[pos[v]])!=ct2.end()){
                if (!mark[2]){
                    mark[2] = 1;
                    q.push(2);
                    dist2[2] = dist2[v];
                }
            }
            if (ct3.find(name[pos[v]])!=ct3.end()){
                if (!mark[3]){
                    mark[3] = 1;
                    q.push(3);
                    dist2[3] = dist2[v];
                }
            }
            if (x){
                if (!mark[name[make_pair(x - 1 , y)]]){
                    mark[name[make_pair(x - 1 , y)]] = 1;
                    q.push(name[make_pair(x - 1 , y)]);
                    dist2[name[make_pair(x - 1 , y)]] = dist2[v] + 1;
                }
            }
            if (y){
                if (!mark[name[make_pair(x  , y - 1)]]){
                    mark[name[make_pair(x  , y - 1)]] = 1;
                    q.push(name[make_pair(x , y - 1)]);
                    dist2[name[make_pair(x  , y - 1)]] = dist2[v] + 1;
                }
            }
            if (x < n){
                if (!mark[name[make_pair(x + 1 , y)]]){
                    mark[name[make_pair(x + 1 , y)]] = 1;
                    q.push(name[make_pair(x + 1 , y)]);
                    dist2[name[make_pair(x + 1 , y)]] = dist2[v] + 1;
                }
            }
            if (y < n){
                if (!mark[name[make_pair(x  , y + 1)]]){
                    mark[name[make_pair(x  , y +1)]] = 1;
                    q.push(name[make_pair(x , y +1)]);
                    dist2[name[make_pair(x , y + 1)]] = dist2[v] + 1;
                }
            }
        }
    }
    memset(mark , 0 , sizeof(mark));
    q.push(3);
    mark[3] = 1;
    dist3[3] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if (v == 1 or v == 2 or v == 3){
            std::set <int> :: iterator it;
            if (v == 1){
                for (it = ct1.begin() ; it != ct1.end() ; it++){
                    if (!mark[*it]){
                        dist3[*it] = dist3[v]+1;
                        q.push(*it);
                        mark[*it] = 1;
                    }
                }
            }
            if (v == 2){
                for (it = ct2.begin() ; it != ct2.end() ; it++){
                    if (!mark[*it]){
                        dist3[*it] = dist3[v]+1;
                        q.push(*it);
                        mark[*it] = 1;
                    }
                }
            }
            if (v == 3){
                for (it = ct3.begin() ; it != ct3.end() ; it++){
                    if (!mark[*it]){
                        dist3[*it] = dist3[v]+1;
                        q.push(*it);
                        mark[*it] = 1;
                    }
                }
            }
        }
        else{
            int x  = pos[v].first , y = pos[v].second;
            if (ct1.find(name[pos[v]])!=ct1.end()){
                if (!mark[1]){
                    mark[1] = 1;
                    q.push(1);
                    dist3[1] = dist3[v];
                }
            }
            if (ct2.find(name[pos[v]])!=ct2.end()){
                if (!mark[2]){
                    mark[2] = 1;
                    q.push(2);
                    dist3[2] = dist3[v];
                }
            }
            if (ct3.find(name[pos[v]])!=ct3.end()){
                if (!mark[3]){
                    mark[3] = 1;
                    q.push(3);
                    dist3[3] = dist3[v];
                }
            }
            if (x){
                if (!mark[name[make_pair(x - 1 , y)]]){
                    mark[name[make_pair(x - 1 , y)]] = 1;
                    q.push(name[make_pair(x - 1 , y)]);
                    dist3[name[make_pair(x - 1 , y)]] = dist3[v] + 1;
                }
            }
            if (y){
                if (!mark[name[make_pair(x  , y - 1)]]){
                    mark[name[make_pair(x  , y - 1)]] = 1;
                    q.push(name[make_pair(x , y - 1)]);
                    dist3[name[make_pair(x  , y - 1)]] = dist3[v] + 1;
                }
            }
            if (x < n){
                if (!mark[name[make_pair(x + 1 , y)]]){
                    mark[name[make_pair(x + 1 , y)]] = 1;
                    q.push(name[make_pair(x + 1 , y)]);
                    dist3[name[make_pair(x + 1 , y)]] = dist3[v] + 1;
                }
            }
            if (y < n){
                if (!mark[name[make_pair(x  , y + 1)]]){
                    mark[name[make_pair(x  , y +1)]] = 1;
                    q.push(name[make_pair(x , y +1)]);
                    dist3[name[make_pair(x , y + 1)]] = dist3[v] + 1;
                }
            }
        }
    }
    ans = min(ans , dist1[2] + dist1[3] - 1);
    ans = min(ans , dist2[1] + dist2[3] - 1);
    ans = min(ans , dist3[1] + dist3[2] - 1);
    for (int i = 0 ; i < n ; i ++){
        for (int j = 0 ; j < m ; j ++){
            if (s[i][j] == '.' and mark[name[make_pair(i , j)]]){
                ans = min(ans , dist1[name[make_pair(i , j)]] + dist2[name[make_pair(i , j)]] + dist3[name[make_pair(i , j)]]);
            }
        }
    }
    cout << ans;
    */
    //I consider the piece of code above as one of my life achivements

    /*
    set <int> ct1 , ct2 ,ct3;
    ll dist1[maxn] , dist2[maxn] , dist3[maxn] , ans = 1e9;
    map < int , pii > pos;
    map < pii , int > name;
    queue < int > q;
    bool mark[maxn];
    int cnt = 3;
    for (int i = 0; i < n; i ++){
        for (int j = 0 ; j < m ; j ++){
            if (s[i][j] == '.'){
                ++cnt;
                pos[cnt] = make_pair(i , j);
                name[make_pair(i , j)] = cnt;
            }
        }
    }
    for (int i = 0;  i < n; i ++){
        for(int j = 0 ; j < m ; j ++){
            if (s[i][j] == '1'){
                if (name.count(make_pair(i-1 , j))){
                    ct1.insert(name[make_pair(i - 1 , j)]);
                    //vec[name[make_pair(i-1 , j)]].pb(1);
                }
                if (name.count(make_pair(i+1 , j))){
                    ct1.insert(name[make_pair(i + 1 , j)]);
                    //vec[name[make_pair(i+1 , j)]].pb(1);
                }
                if (name.count(make_pair(i , j-1))){
                    ct1.insert(name[make_pair(i  , j - 1)]);
                    //vec[name[make_pair(i , j - 1)]].pb(1);
                }
                if (name.count(make_pair(i , j+1))){
                    ct1.insert(name[make_pair(i , j + 1)]);
                    //vec[name[make_pair(i , j + 1)]].pb(1);
                }
            }
            if (s[i][j] == '2'){
                if (name.count(make_pair(i-1 , j))){
                    ct2.insert(name[make_pair(i - 1 , j)]);
                    //vec[name[make_pair(i-1 , j)]].pb(1);
                }
                if (name.count(make_pair(i+1 , j))){
                    ct2.insert(name[make_pair(i + 1 , j)]);
                    //vec[name[make_pair(i+1 , j)]].pb(1);
                }
                if (name.count(make_pair(i , j-1))){
                    ct2.insert(name[make_pair(i  , j - 1)]);
                    //vec[name[make_pair(i , j - 1)]].pb(1);
                }
                if (name.count(make_pair(i , j+1))){
                    ct2.insert(name[make_pair(i , j + 1)]);
                    //vec[name[make_pair(i , j + 1)]].pb(1);
                }
            }
            if (s[i][j] == '3'){
                if (name.count(make_pair(i-1 , j))){
                    ct3.insert(name[make_pair(i - 1 , j)]);
                    //vec[name[make_pair(i-1 , j)]].pb(1);
                }
                if (name.count(make_pair(i+1 , j))){
                    ct3.insert(name[make_pair(i + 1 , j)]);
                    //vec[name[make_pair(i+1 , j)]].pb(1);
                }
                if (name.count(make_pair(i , j-1))){
                    ct3.insert(name[make_pair(i  , j - 1)]);
                    //vec[name[make_pair(i , j - 1)]].pb(1);
                }
                if (name.count(make_pair(i , j+1))){
                    ct3.insert(name[make_pair(i , j + 1)]);
                    //vec[name[make_pair(i , j + 1)]].pb(1);
                }
            }
        }
    }
    q.push(1);
    mark[1] = 1;
    dist1[1] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if (v == 1 or v == 2 or v == 3){
            std::set <int> :: iterator it;
            if (v == 1){
                for (it = ct1.begin() ; it!=ct1.end() ; it++){
                    if (!mark[*it]){
                        dist1[*it] = dist1[v]+1;
                        q.push(*it);
                        mark[*it] = 1;
                    }
                }
            }
            if (v == 2){
                for (it = ct2.begin() ; it!=ct2.end() ; it++){
                    if (!mark[*it]){
                        dist1[*it] = dist1[v]+1;
                        q.push(*it);
                        mark[*it] = 1;
                    }
                }
            }
            if (v == 3){
                for (it = ct3.begin() ; it!=ct3.end() ; it++){
                    if (!mark[*it]){
                        dist1[*it] = dist1[v]+1;
                        q.push(*it);
                        mark[*it] = 1;
                    }
                }
            }
        }
        else{
            int x  = pos[v].first , y = pos[v].second;
            if (ct1.find(name[pos[v]])!=ct1.end()){
                if (!mark[1]){
                    mark[1] = 1;
                    q.push(1);
                    dist1[1] = dist1[v];
                }
            }
            if (ct2.find(name[pos[v]])!=ct2.end()){
                if (!mark[2]){
                    mark[2] = 1;
                    q.push(2);
                    dist1[2] = dist1[v];
                }
            }
            if (ct3.find(name[pos[v]])!=ct3.end()){
                if (!mark[3]){
                    mark[3] = 1;
                    q.push(3);
                    dist1[3] = dist1[v];
                }
            }
            if (x){
                if (!mark[name[make_pair(x - 1 , y)]]){
                    mark[name[make_pair(x - 1 , y)]] = 1;
                    q.push(name[make_pair(x - 1 , y)]);
                    dist1[name[make_pair(x - 1 , y)]] = dist1[v] + 1;
                }
            }
            if (y){
                if (!mark[name[make_pair(x  , y - 1)]]){
                    mark[name[make_pair(x  , y - 1)]] = 1;
                    q.push(name[make_pair(x , y - 1)]);
                    dist1[name[make_pair(x  , y - 1)]] = dist1[v] + 1;
                }
            }
            if (x < n){
                if (!mark[name[make_pair(x + 1 , y)]]){
                    mark[name[make_pair(x + 1 , y)]] = 1;
                    q.push(name[make_pair(x + 1 , y)]);
                    dist1[name[make_pair(x + 1 , y)]] = dist1[v] + 1;
                }
            }
            if (y < n){
                if (!mark[name[make_pair(x  , y + 1)]]){
                    mark[name[make_pair(x  , y +1)]] = 1;
                    q.push(name[make_pair(x , y +1)]);
                    dist1[name[make_pair(x , y + 1)]] = dist1[v] + 1;
                }
            }
        }
    }
    if(!mark[1] or !mark[2] or !mark[3]){dokme(-1);}
    */
    for(int i = 0 ; i < 3 ; i ++){pre(i);}
    ll ans = inf;
    for (int i = 1; i <= n ; i ++){
        for (int j = 1 ; j <= m ; j ++){
            if(s[i][j]!='#') {
                ll t =min(inf + 10, dist[0][i][j] + dist[1][i][j]) + dist[2][i][j];
                if(s[i][j]=='.'){
                    t-=2;
                }
                setmin(ans, t);
            }
        }
    }
    if (ans >= inf){
        ans=  -1;
    }
    dokme(ans)
    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you wiint come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
