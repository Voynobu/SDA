#include <stdio.h>
#include <stdlib.h>
#include "StackBiner.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	int loop = 1;
	while (loop == 1){
		infotype nilai; 
		address First;
		char input;
		printf("Masukan bilangan desimal yang ingin di konversi: ");
		scanf("%d", &nilai);
		KonversiDecimaltoBiner(nilai, &First);
			printf("\n\n\nHasil konversi Desimal->Biner : ");
		TampilkanBiner(&First);
		
		printf("\nApakah anda ingin mencoba lagi('Y'/'T'): ");
		scanf("%c", &input);
		if(input == 'T'){
			loop = 0;
		}
	}  	
	return 0;
}
