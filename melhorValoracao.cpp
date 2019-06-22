#include <bits/stdc++.h>
#define MAXN 3000

using namespace std;

string expr;
int PD[MAXN][MAXN];

int maiorValoracao(int i, int j){
	if(i==j){
		return (int)expr[i] -'0';
	}
	if(PD[i][j] != -1){
		return PD[i][j];
	}
	
	int maxima = 0;
	int k;
	for(k=i+1; k<j; k+=2){
		if(expr[k] == '+'){
			maxima = max(maxima, maiorValoracao(i, k-1) + maiorValoracao(k+1, j));
		}else{
			maxima = max(maxima, maiorValoracao(i, k-1) * maiorValoracao(k+1, j));
		}
	}
	PD[i][j] = maxima;
	return maxima;
}

int main(){
	
	cin >> expr;
	for(int i=0; i<(int)expr.length()+20; i++){
		for(int j=0; j<(int)expr.length()+20; j++){
			PD[i][j] = -1;
		}
	}
	cout << maiorValoracao(0, expr.length()-1);
}

