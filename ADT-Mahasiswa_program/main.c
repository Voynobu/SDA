#include <stdio.h>
#include <stdlib.h>
#include "Mahasiswa.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	address L1 = NULL, L2 = NULL, First1 = NULL, First2 = NULL;
	int Jumlah;
	Create_Node(&L1);
	Isi_Node(&L1, 80, "Jajang");
	Ins_Awal(&First1, L1);
	Tampil_List(First1);
	
	Create_Node(&L1);
	Isi_Node(&L1, 70, "Hermawan");
	Ins_Akhir(&First1, L1);
	SortByName(First1);
	Tampil_List(First1);	
	SortByInfo(First1);
	Tampil_List(First1);	
	
	Create_Node(&L1);
	Isi_Node(&L1, 85, "Naufal");
	InsertAfter(&First1, L1);
	SortByName(First1);
	Tampil_List(First1);	
	SortByInfo(First1);
	Tampil_List(First1);	
	
	Create_Node(&L1);
	Isi_Node(&L1, 90, "Zaidan");
	InsertAfter(&First1, L1);
	SortByName(First1);
	Tampil_List(First1);	
	SortByInfo(First1);
	Tampil_List(First1);	
	
	Create_Node(&L1);
	Isi_Node(&L1, 65, "Bebadobee");
	InsertAfter(&First1, L1);
	SortByName(First1);
	Tampil_List(First1);
	SortByInfo(First1);
	Tampil_List(First1);
	
	Jumlah = NbElmt(First1);
	printf("\nTotal elemen dalam list adalah %d\n\n", Jumlah);
	
	Destroy_All(&First1);
	Tampil_List(First1);
	First1 = NULL;
}
