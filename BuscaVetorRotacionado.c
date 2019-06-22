#include <stdio.h>

int buscaBinaria(int vet[], int inicio, int fim, int x){
	int meio;
	if(inicio == fim && vet[inicio] == x){
		return 1;
	}else if(inicio<fim){
		meio = (inicio+fim)/2;
		if(vet[meio] == x){
			return 1;
		}else{ 
			if(vet[meio] < x){
				return buscaBinaria(vet, meio+1, fim, x);
			}else{
				return buscaBinaria(vet, inicio, meio-1, x);
			}
		}
	}else{
		return 0;
	}
}

int rotacaoK (int vet[], int inicio, int fim){
	int meio = (inicio+fim)/2;
	if(inicio > fim){
		return 0;
	}
	if(inicio == fim){
		return 1;
	}
	
	if(vet[meio] >= vet[inicio] && vet[meio] <= vet[fim]){
		return (fim-inicio+1);
	}
	if(vet[meio] >= vet[inicio]){
		return rotacaoK(vet, meio+1, fim);
	}else{
		if(meio > inicio && vet[meio] >= vet[meio-1]){
			return (fim-meio+1) + rotacaoK(vet, inicio, meio-1);
		}else{
			return (fim-inicio+1) - rotacaoK(vet, inicio, meio-1);
		}
	}	
}

int main(){
	int n;
	scanf("%d", &n);
	
	int vet[n], i;
	for(i=0; i<n; i++){
		scanf("%d", &vet[i]);
	}
	
	int x;
	scanf("%d", &x);
	
	int k = rotacaoK(vet, 0, n-1);
	
	int result1 = buscaBinaria(vet, 0, n-k-1, x);
	int result2 = buscaBinaria(vet, n-k, n-1, x);
	
	if(result1 == 1 || result2 == 1){
		printf("V");
	}else{
		printf("F");
	}
	
	return 0;
}
