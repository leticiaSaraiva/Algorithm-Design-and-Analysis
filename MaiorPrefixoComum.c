#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

char* PrefixUtilComum(char* str1, char* str2) { 
    char* result = (char*) malloc(sizeof(char)*500);
    int n1 = strlen(str1);
    int n2 = strlen(str2); 
  
	int i, j;
    for(i=0, j=0; i<n1 && j<n2; i++, j++){ 
        if(str1[i] != str2[j]){ 
            break;
        } 
        int t = strlen(result);
        result[t] = str1[i]; 
    } 
    return result; 
} 
  
char* PrefixComum(char** arr, int low, int high){
    if(low == high){ 
        return arr[low]; 
	}
    if (high > low){ 
        int mid = low+(high-low)/2; 
  
        char* str1 = PrefixComum(arr, low, mid); 
        char* str2 = PrefixComum(arr, mid+1, high); 
  
        return PrefixUtilComum(str1, str2); 
    }
    return 0; 
} 
  
int main(){
	int n, i, tam = 0;
	scanf("%d", &n);
	
	char** arr = (char**) malloc(sizeof(char*) * n);
	for(i=0; i<n; i++){
		arr[i] = (char*) malloc(sizeof(char)*500);
		scanf("%s", arr[i]);
		tam = tam + sizeof(arr[i])*4;
	}
    
    int tamZero = sizeof (arr[0])*4;
	
	int x = tam / tamZero; 
	
    char* ans = PrefixComum(arr, 0, x-1); 
    
    int tam1 = strlen(ans);
    printf("%d ", tam1);
      
    return (0); 
} 
