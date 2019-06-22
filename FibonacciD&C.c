#include <stdio.h>
#include <stdlib.h>

typedef long long int lli;

typedef struct{
	lli **m;
	int l, c;
}matriz;

lli** criarMatriz(int lin, int col){
	lli **r = (lli**) malloc(sizeof(lli)*(lin+1));
	for(int i = 0; i <= lin; i++){
		r[i] = (lli*) malloc(sizeof(lli)*(col+1));
	}
	return r;
}

matriz multiplicarMatriz(matriz A, matriz B){
	matriz C;
	C.m = criarMatriz(A.l, B.c);
	C.l = A.l; C.c = B.c;
	int i, j, k;
	
	for(i = 1; i <= A.l; i++){
		for(j = 1; j <= B.c; j++){
			C.m[i][j] = 0;
			for(k = 1; k <= A.c; k++){
				C.m[i][j] += A.m[i][k] * B.m[k][j];
			}
		}
	}
	return C;
}

matriz exponenciaMatriz(matriz M, int exp){
	if(exp <= 1){
		return M;
	}
	if(exp%2 == 1){
		return multiplicarMatriz(M, exponenciaMatriz(M,exp-1));
	}
	matriz MatrizAux = exponenciaMatriz(M,exp/2);
	
	return multiplicarMatriz(MatrizAux,MatrizAux);
}

int main(){
	
	matriz M;
	M.l = 2;
	M.c = 2;
	M.m = criarMatriz(2,2);
	M.m[1][1] = 1;
	M.m[1][2] = 1;
	M.m[2][1] = 1;
	M.m[2][2] = 0;
	
	int n;
	scanf("%d", &n);	
	
	M = exponenciaMatriz(M, n-1);

	printf("%lli", M.m[1][1]);
	
	return 0;
}
