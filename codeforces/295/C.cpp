#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const ll maxn = 60;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n , k ,h = 0 , l = 0;
bool mark[maxn][maxn];
queue <pii> q;
int dist[maxn][maxn];
int name[maxn][maxn];
pii pos[1000000];
vector <int> vec[maxn];
ll ent[maxn][maxn];
ll val[2][maxn][maxn][500];
int cnt = 0 ;
ll ans = -1;

void entkh(){
    //cout << 2;
    for(int i=0; i<55; i++){
        for(int j=0; j<55; j ++){
            if(i==0 or j==0){
                ent[i][j]=1;
            }
            else{
                //cout << 2;
                ent[i][j]=(ent[i-1][j]+ent[i][j-1])%mod;
            }
        }
    }
}
void adad(int a,int b, int c, int d, ll ctt){
    if(val[d][b][c][a]==-1){
        val[d][b][c][a]=ctt%mod;
    }
    else{
        val[d][b][c][a]=(val[d][b][c][a]+ctt)%mod;
    }
}

ll entekhab(int n, int r){
    return ent[n-r][r];
}

int main (){
    migmig
    entkh();
    cin >> n >> k;
    memset(val,-1,sizeof(val));
    for (int i = 0 ; i < n ; i ++){
        int inp;
        cin >> inp;
        if (inp == 50){
            l ++;
        }
        else{
            h ++;
        }
    }
    k/=50;
    val[0][l][h][0]=1;
    /*
    for (int i = 0;i  <= l; i ++){
        for (int j = 0 ; j <=h ; j ++){
            name[i][j] = cnt;
            pos[cnt] = make_pair(i , j);
            cnt ++;
        }
    }
    */
    for(int t=0; t<450; t++){
        if(val[1][0][0][t] >= 0){
            break;
        }
        for(int i = 0 ; i <= l; i++){
            for(int j = 0 ; j <= h; j++){
                if(val[0][i][j][t] >= 0){
                    for(int p = 0; p <= i ; p++){
                        for(int  q = 0 ; q <= j ; q++){
                            if(p+2*q<=k){
                                if(p+q>0){
                                    adad( t +1 , i - p , j - q, 1 , val[ 0 ] [ i ] [ j ] [t ] * (entekhab ( i, p ) * entekhab ( j , q) % mod));
                                }
                            }
                            else{
                                break;
                            }
                        }
                    }
                }
                if(val[1][i][j][t] >= 0){
                    for(int p = 0 ; p <= l - i; p++){
                        for(int  q = 0 ; q <= h - j ; q ++){
                            if(p+2*q<=k){
                                if(p+q>0){
                                    adad( t +1 , i + p ,j + q , 0, val [ 1 ][ i ] [ j ][ t ] * ( entekhab( l - i , p )* entekhab ( h -j , q )% mod ));
                                }
                            }
                            else{
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i=0; i<499; ++i){
        //cout << val[1][0][0][i] << endl;
        if(val[1][0][0][i] >= 0){
            ans=i;
            break;
        }
    }
    if(ans == -1){
        cout << -1 << endl << 0;
        return(0);
    }
    cout << ans << endl;
    cout << val[1][0][0][ans];
    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you wiint come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
