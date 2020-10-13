//De 0 a 1.000.000 en 0.046875 segundos
//De 0 a 10.000.000 en 0.812500 segundos
//g++ -O3 primos_VE.cpp -o primos_VE
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <cmath>

using namespace std;

int main(){
	const  int TAM = 1000000;
	clock_t t;
	int a=0;
	 int i = 0, n_primos = 0, k, FIN, INICIO; 
	int primos [TAM];
	double raiz = 0;
	
	cout << "\nIntroduce un INICIO\n";
	cin >> INICIO;
	cout << "\nIntroduce un FINAL\n";
	cin >> FIN;
   
	t = clock();

	
	for ( k = 1; k < FIN; k++)
    	{	
    		a = 0;
    		i = 0;
    		raiz = sqrt (k);
    		//cout << raiz << "\n";
    		
        	while ( (i < n_primos) && (a <= 1) && (primos [i] <= raiz)){
        	 	if(k % primos [i] == 0){
            			a++;
        	    	}
        	    i++;
        	}
        	if(a == 1 || k == 1){
				        	    
        	    primos [n_primos] = k; 
        	    n_primos++;
        	    
         	}
         
  	}
  	
	t = clock() - t;
	
        cout << "\nNumero de primos encontrados: " << n_primos << "\n";
	printf ("\nEl programa tarda %f segundos.\n",t,((float)t)/CLOCKS_PER_SEC);

	return 0;
}
