#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 1e5+100;
const ll ZERO = 0; 
const ll SADAT = 7.84e-17;
const ll INF = 1000100000;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
long long n,m,a,b,x,y,z,g,i,j,suma;
int l[3005][3005],rsp1[3005][3005],rsp2[3005][3005],cs,cd,dq[3005];

int main(){
    cin >> n >> m >> a >> b >> g >> x >> y >> z;
    for( i = 1 ; i <= n ; i++ ){
        for( j = 1 ; j <= m ; j++ ){
            l[ i ][ j ] = g;
            g = ( g * x + y ) % z;
        }
    }
    for( j = 1 ; j <= m ; j++ ){
        cs = 1 ;
        cd = 0 ;
        for( i = 1 ; i <= n ; i++){
            while( cd >= cs && l[ i ][ j ] <= l[ dq[ cd ] ][ j ] ) cd--;
            dq[cd+1] = i ;
            cd++;
            if( dq[cs]  == i - a ) cs++;
            rsp1[ i - a + 1 ][ j ] = l[ dq[ cs ] ][ j ];
        }
    }
    for( i = 1 ; i <= n ; i++ ){
        cs = 1 ;
        cd = 0 ;
        for( j = 1 ; j <= m ; j++ ){
            while( cd >= cs && rsp1[ i ][ j ] <= rsp1[ i ][ dq[ cd ] ] ) cd--;
            dq[ cd + 1 ] = j ;
            cd++;
            if( dq[ cs ] == j - b ) cs++;
            rsp2[ i ][ j - b + 1] = rsp1[ i ][ dq[ cs ] ];
        }
    }
    for( i = 1 ; i <= n - a + 1 ; i++ ){
        for( j = 1 ; j <= m - b + 1 ; j++ ) suma += rsp2[i][j];
    }
    cout << suma;
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moling... you will come to a better place.
