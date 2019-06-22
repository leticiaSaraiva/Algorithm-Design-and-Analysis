#include <stdio.h>
#include <math.h>

int buscaBinariaAdaptada(int vet[], int inicio, int fim){
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
		return buscaBinariaAdaptada(vet, meio+1, fim);
	}else{
		if(meio > inicio && vet[meio] >= vet[meio-1]){
			return (fim-meio+1) + buscaBinariaAdaptada(vet, inicio, meio-1);
		}else{
			return (fim-inicio+1) - buscaBinariaAdaptada(vet, inicio, meio-1);
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
	
	int result = buscaBinariaAdaptada(vet, 0, n-1);
	
	printf("%d", result);
	return 0;
}
