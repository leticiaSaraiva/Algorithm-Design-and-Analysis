#include <stdio.h>

int min(int a, int b){
	if(a < b){
		return a;
	}else{
		return b;
	}
}

int num_moedas(int N, int M, int* m) {
    int dp[N+1];

    dp[0] = 0;

    for(int i=1; i<=N; i++) {
        dp[i] = 1000000;

        for(int j=0; j<M; j++) {
            if(i-m[j] >= 0) {
                dp[i] = min(dp[i], dp[i-m[j]]+1);
            }
        }
    }

    return dp[N];
}
int main(){
	int i = 0, N, M, m[5000];
	scanf("%d %d", &N, &M);
	
	for(i=0; i<M; i++){
        scanf("%d", &m[i]);
    }
	
	int result = num_moedas(N, M, m);
	
	if(result != 1000000){
		printf("troco");
	}else{
		printf("balinha");
	}
}
