#define StackBiner_H
#include <stdio.h>
#include <malloc.h>
#include "linked.h"

int StackisEmpty(address p){
//Mengecek apakah Stack yang digunakan = NULL
	isEmpty(p);
}

void CreateNodeStack(address *p){
//Membuat node baru yang akan digunakan untuk stack
	Create_Node(p);
}


void IsiNodeStack(address *p, infotype nilai){
//Memberi node yang baru dibuat sebuah nilai dan pointer next
	Isi_Node(p, nilai);
}

void PushStack(address *p, address SNew){
//Menambahkan node baru kedalam stack
	Ins_Awal(p, SNew);
}

int PopStack(address *p, infotype *X){
	//Menghapus satu node dalam stack (node yang dihapus adalah node yang terakhir kali dimasukkan
	//Menyimpan nilai dari node yang dihapus kedalam sebuah variabel
	Del_Awal(p, X);
}

void TampilkanNode(address *p, infotype *X){
//Menampilkan satu node yang telah dikeluarkan oleh stack
	PopStack(p, X);
	printf("%d", X);
}

void KonversiDecimaltoBiner(infotype decimal, address *p){
//Mengkonversi suatu nilai desimal menjadi biner dengan metode stack
	address s;
	infotype Sisa = 0;
	while(decimal > 0){
		if(decimal != 1){
			Sisa = decimal % 2;
			CreateNodeStack(&s);
			IsiNodeStack(&s, Sisa);
			PushStack(p, s);
			decimal = decimal/2;
		} else {
			Sisa = decimal % 2;
			CreateNodeStack(&s);
			IsiNodeStack(&s, Sisa);
			PushStack(p, s);
			decimal--;
		}
	}
}

void TampilkanBiner(address *p){
//Menampilkan isi dari stack yang merupakan hasil konversi dari Desimal ke Biner
		if(*p == NULL){
		printf ("P sudah NULL\n");
		return;
	}

	infotype X;
	
	while(*p != NULL){
		PopStack(p, &X);
		printf("%d", X);
	}
}
