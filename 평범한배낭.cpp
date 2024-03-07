#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int n,k;
int w,v;

int weight[100001];
int value[100001];
int dp[101][100001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;

    for(int i=0; i<=n; i++){
        for(int j=0; j<=k; j++){
            dp[i][j] = 0;
        }
    }

    for(int i=1; i<=n; i++){
        cin >> weight[i] >> value[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(j >= weight[i]){//가져갈 수 있는 경우
                dp[i][j] = max(value[i]+dp[i-1][j-weight[i]], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][k]<<"\n";
    return 0;
}