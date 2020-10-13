//Tamaño de vector 2000
//De 0 a 1.000.000 en  0.078125 segundos
//De 0 a 10.000.000 en  2.3906 segundos
//De 0 a 1.000.000.000 en  segundos
//Tamaño de vector 200
//De 0 a 1.000.000 en  0.2656 segundos
//De 0 a 10.000.000 en 43.01 segundos
//De 0 a 1.000.000.000 en segundos
//Tamaño de vector 20000
//De 0 a 1.000.000 en 0.0468 segundos
//De 0 a 10.000.000 en 1.31 segundos
//De 0 a 1.000.000.000 en segundos
//Tamaño de vector 200000
//De 0 a 1.000.000 en 0.0625 segundos
//De 0 a 10.000.000 en 1.15 segundos
//De 0 a 1.000.000.000 en 567.734 segundos

//Usando únicamente vector dinámico con primos_VD.cpp

//De 0 a 1.000.000 en 0.046875 segundos
//De 0 a 100.000.000 en 15.515625 segundos
//De 0 a 1.000.000.000 en 324.428750  segundos
//g++ -O3 primos_VE_Lista.cpp -o primos_VE_Lista
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <cmath>
#include <list> 
#include <vector> 
#include <iterator> 

using namespace std;
static const  int TAM = 2000000;


int main(){
	
	clock_t t;
	int n_primos = 0, k, FIN; 
	bool es_primo;

	list <vector<int>> primos;
	double raiz = 0;
	
	cout << "\nIntroduce un FINAL\n";
	cin >> FIN;
   
	t = clock();
	list <vector<int>> :: iterator it; 

	//Añadimos el primer vector a la lista primos
	vector<int> nuevo ;
	
	primos.push_back(nuevo);
	
	
	for ( k = 1; k < FIN; k++)
    {	
		//Si el último vector del último elemento de la lista está lleno creamos un nuevo elemento
		std::list <vector<int>>::iterator it2 = primos.end();
		--it2;
		if((*it2).size() == TAM){
			vector<int> nuevo;
			primos.push_back(nuevo);
		} 
		
		//es_primo se mantiene en true mientras siga la posibilidad de que siga siendo primo
    	es_primo = true;
    	raiz = sqrt (k);
		
		
		//Recorremos cada vector en la lista 
    	for (it = primos.begin(); it != primos.end() && es_primo; ++it)
		{
			
			//Recorremos cada elemento del vector
			for (int i = 0; (i < (*it).size()) && (es_primo) && ((*it)[i] <= raiz); i++){
				if(k % (*it)[i] == 0 && (*it)[i] != 1) es_primo = false;
			}
			if(es_primo || k == 1){		
				(*it).push_back(k); 
				n_primos++;
			}
			
		}
         
  	}

  	
	t = clock() - t;
	cout << "\nNumero de primos encontrados: " << n_primos << "\n";
	printf ("\nEl programa tarda %f segundos.\n",t,((float)t)/CLOCKS_PER_SEC);

	return 0;
}
