#include <bits/stdc++.h>
#define MAXN 4000
#define INF -999999

using namespace std;

string expr;
int PD[MAXN][MAXN];

int maiorValoracao(int n){
	int maior = 0, i, j, k;
	
	for(i=0; i<n; i++){
		PD[i][i] = expr[i] -'0';
	}
	for(i=n-1; i>0; i--){
		for(j=i+1; j<n; j++){
			maior = INF;
			for(k=i; k<=j-1; k-=2){
				if(expr[k]=='+'){
					maior = max(maior, PD[i][k]+PD[k+1][j]);
				}else{
					maior = max(maior, PD[i][k]*PD[k+1][j]);
				}
			}
			PD[i][j] = maior;
		}
	}
	return PD[1][n];
}

int main(){
	cin >> expr;
	cout << maiorValoracao(expr.length()-1);
}
