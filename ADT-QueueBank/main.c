#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	address Q1 = NULL;
	int loop = 1;
	while(loop == 1){
		int choice;
		printf("\n");
		printf("-=-=-===============-=-=-\n");
		printf("-=-=-= AntiranBank =-=-=-\n");
		printf("-=-=-===============-=-=-\n");
		
		printf("\n 1. Ambil Antrian");
		printf("\n 2. Proses Antrian");
		printf("\n 3. Tampil Antrian");
		printf("\n 4. Reset");
		
		printf("\n\nPilih opsi yang tersedia di atas: ");
		scanf("%d", &choice);
		getchar();
		
		if(choice == 1){
			if(Q1 == NULL){
				address New1;
				Create_QNode(&New1);
				Fill_QNode(&New1, 1);
				Get_inQueue(&Q1, New1);
				Show_Queue(Q1);	
			} else {	
			address New;
			Create_QNode(&New);
			infotype jumlah = Waiting_inQueue(Q1) + 1;
			Fill_QNode(&New, jumlah);
			Get_inQueue(&Q1, New);
			Show_Queue(Q1);
			}
		}
		
		if(choice == 2){
			infotype processed;
			Show_Queue(Q1);
			if(Q1 != NULL){
				Get_outQueue(&Q1, &processed);
				printf("Nomor antrian yang sedang di proses: %d...", processed);
				printf("\n...proses selesai!!\n");
				printf("Nomor antiran selanjutnya: %d", Q1->info);
				printf("\n\nKeadaan Queue saat ini: \n");
				Show_Queue(Q1);
			}
		}
		
		if(choice == 3){
			Show_Queue(Q1);
		}
		
		if(choice == 4){
			Destroy_Queue(Q1);
			Q1 = NULL;
			Show_Queue(Q1);
			loop = 0;
		}
	}	
	return 0;
}
