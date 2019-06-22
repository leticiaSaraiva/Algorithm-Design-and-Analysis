#include <stdio.h> 
#include <math.h>
           
int buscaK(int i, int j, int v, int n){
	if(i == j){
		if(pow(v,i) == n){
			return 1;
		}else{
			return 0;
		}
		int meio = i+j/2;
		if(pow(v,meio) == n){
			return 1;
		}
		if(pow(v,meio) < n){
			return buscaK(i, meio-1, v, n);
		}else{
			return buscaK(meio+1, j, v, n);
		}
	}
}
   
int main(){      
    int v, n;
    scanf("%d %d", &v, &n); 
	
	int r = buscaK(1, n-1, v, n);
	
	if(r){
		printf("V");
    }else{
		printf("F");
	}
    
    return 0;    
} 
