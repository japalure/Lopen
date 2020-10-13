//De 0 a 1.000.000 en 0.046875 segundos
#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

int main(){
	clock_t t;
	int a=0, i, n_primos = 0; 
	long long int FIN, INICIO, k;
	cout << "\nIntroduce hasta que numero INICIO\n";
	cin >> INICIO;
	cout << "\nIntroduce hasta que numero FINAL\n";
	cin >> FIN;
   
	t = clock();
	for ( k = INICIO; k < FIN; k++)
    {	 a = 0;
         for (i = 1; i < (k+1); i++){
         	if(k%i == 0){
            		a++;
            	}
         }
         if(a == 2 || k == 1){
            n_primos++;
         }
         
    }
	t = clock() - t;
        cout << "\nNumero de primos encontrados: " << n_primos << "\n";
	printf ("\nEl programa tardó %f segundos.\n",t,((float)t)/CLOCKS_PER_SEC);

    return 0;
}
