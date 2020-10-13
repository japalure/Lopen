//De 0 a 1.000.000 en 0.046875 segundos
//De 0 a 100.000.000 en 15.296875 segundos
//De 0 a 1.000.000.000 en 350.015625  segundos
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <cmath>
#include <list>

using namespace std;

int main(){

	clock_t t;
	int a=0;
	int k, FIN; 
	list<int> primos;
	double raiz = 0;

	cout << "\nIntroduce un FINAL\n";
	cin >> FIN;
   
	t = clock();

	primos.push_back(1);
	primos.push_back(2);
	primos.push_back(3);
	
	for ( k = 5; k < FIN; k+=2)
    	{	
    		a = 0;
    		
    		list<int>::iterator it = primos.begin();
    		raiz = sqrt (k);
    		
        	while ( (it != primos.end() ) && (a <= 1) && ( (*it) <= raiz)){
        	 	if(k % (*it) == 0){
            			a++;
        	    }
        	    ++it;
        	}
        	if(a == 1){

				//cout << k << "\n";
        	    primos.push_back(k);        	    
         	}
         
  	}
  	
	t = clock() - t;
	
    cout << "\nNumero de primos encontrados: " << primos.size() << "\n";
    cout << "\nUltimo primo encontrado: " << primos.back() << "\n";
	printf ("\nEl programa tarda %f segundos.\n",t,((float)t)/CLOCKS_PER_SEC);

	return 0;
}
