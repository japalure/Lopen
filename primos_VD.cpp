//De 0 a 1.000.000 en 0.046875 segundos
//De 0 a 100.000.000 en 15.515625 segundos
//De 0 a 1.000.000.000 en 324.428750  segundos
//g++ -O3 primos_VD.cpp -o primos_VD
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <cmath>
#include <vector>

using namespace std;

int main(){
	clock_t t;
	int a=0;
	static const int INICIO = 0;
	int i = 0, n_primos = 0, k, FIN; 
	vector<int> primos;
	unsigned int raiz = 0;
	

	cout << "\nIntroduce un FINAL\n";
	cin >> FIN;
   
	t = clock();

	
	for ( k = 1; k < FIN; k++)
    	{	
    		a = 0;
    		i = 0;
    		raiz = sqrt (k);
    		//cout << raiz << "\n";
    		
        	while ( (i < primos.size()) && (a <= 1) && (primos [i] <= raiz)){
        	 	if(k % primos [i] == 0)  a++;
        
        	    i++;
        	}
        	if(a == 1 || k == 1){
        	   primos.push_back(k) ;
         	}
         
  	}
  	
	t = clock() - t;
	
    cout << "\nNumero de primos encontrados: " << primos.size() << "\n";
	printf ("\nEl programa tarda %f segundos.\n",t,((float)t)/CLOCKS_PER_SEC);

	return 0;
}
