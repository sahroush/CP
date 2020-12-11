
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second
#define Mp                          make_pair
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define endl                        "\n"

const int N = 2e3 + 10;
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll inf = 8e18;
const int LOG = 22;

ll pw(ll a , ll b, ll M)  { return (!b ? 1 : (b & 1 ? (a * pw(a * a % M, b / 2, M)) % M : pw(a * a % M, b / 2, M))); }

ll ans;

int n, m, Up[N], D[N], v[N], Mx[2][N];

char M[N][N];

inline void solve(int cu)
{
    memset(Mx, -1, sizeof Mx);
    for(int j = 1; j <= m; j++)
    {
        v[j] = min(cu - Up[j], D[j] - cu);
        //cout << Up[j] << " " << D[j] << " " << v[j] << endl;
        if(j == 1) { Mx[0][j] = 0; continue; }
        if(M[cu][j] == M[cu][j - 1])
        {
            Mx[0][j] = min(Mx[0][j - 1] + 1, v[j]);
        }
        else { Mx[0][j] = 0; }
    }
    for(int j = m; j >= 1; j--)
    {
        if(j == m)
        {
            Mx[1][j] = 0;
            continue;
        }
        if(M[cu][j] == M[cu][j + 1])
        {
            Mx[1][j] = min(v[j], Mx[1][j + 1] + 1);
        }
        else
        {
            Mx[1][j] = 0;
        }
    }
    for(int j = 1; j <= m; j++)
    {
        //cout << Mx[0][j] << " " << Mx[1][j] << endl;
        ans += min(Mx[0][j], Mx[1][j]) + 1;
    }
}

int main(){
    fast_io;
    //cout << fixed << setprecision(15);
    //scanf("%d %d %f %lld %s %c", &x);
    //printf("%d %d %f %lld %s %c", x);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++)
        {
            M[i][j + 1] = s[j];
        }
    }
    for(int j = 1; j <= m; j++)
    {
        Up[j] = 1;
        for(int i = 1; i <= n; i++)
        {
            if(M[i][j] != M[1][j])
            {
                break;
            }
            D[j] = i;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        solve(i);
        if(i == n) { break; }
        for(int j = 1; j <= m; j++)
        {
            if(M[i][j] != M[i + 1][j])
            {
                Up[j] = i + 1;
                for(int i2 = i + 1; i2 <= n; i2++)
                {
                    if(M[i + 1][j] != M[i2][j])
                    {
                        break;
                    }
                    D[j] = i2;
                }
            }
        }
    }
    cout << ans;
    return 0;
}