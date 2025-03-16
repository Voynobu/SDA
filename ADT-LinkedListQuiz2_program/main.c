#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	address First;
	address P;
	infotype nilai;
	
	First = NULL;
	Create_Node(&P);
	Isi_Node(&P, 7);
	Ins_Awal(&First, P);
	Tampil_List(First);
	
	Create_Node(&P);
	Isi_Node(&P, 11);
	Ins_Akhir(&First, P);
	Tampil_List(First);
	
	Create_Node(&P);
	Isi_Node(&P, 9);
	InsertAfter(&First, P);
	Tampil_List(First);
	
	Create_Node(&P);
	Isi_Node(&P, 5);
	Ins_Awal(&First, P);
	Tampil_List(First);
	
	Create_Node(&P);
	Isi_Node(&P, 13);
	Ins_Akhir(&First, P);
	
	Del_Akhir(&First, &nilai);
	Tampil_List(First);
	printf ("elemen yang terhapus adalah %d\n", nilai);
	
	Del_After(&First, &nilai);
	Tampil_List(First);
	printf ("elemen yang terhapus adalah %d\n", nilai);
	
	Del_Awal(&First, &nilai);
	Tampil_List(First);
	printf ("elemen yang terhapus adalah %d\n", nilai);

	Destroy_All(&First);
	Tampil_List(First);
	return 0;
}
