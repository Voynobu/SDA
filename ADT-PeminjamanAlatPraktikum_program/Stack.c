#define StackBiner_H
#include <stdio.h>
#include <malloc.h>
#include "linked.h"

int StackisEmpty(address p){
//Mengecek apakah Stack yang digunakan = NULL
	return isEmpty(p);
}

void CreateNodeStack(address *p){
//Membuat node baru yang akan digunakan untuk stack
	Create_Node(p);
}


void IsiNodeStack(address *p, infotype X, char *nama, char *kualitas){
//Memberi node yang baru dibuat sebuah nilai dan pointer next
	Isi_Node(p, X, nama, kualitas);
}

void PushStack(address *p, address SNew){
//Menambahkan node baru kedalam stack
	Ins_Awal(p, SNew);
}

int PopStack(address *p, infotype *X, char **nama, char **kualitas){
	//Menghapus satu node dalam stack (node yang dihapus adalah node yang terakhir kali dimasukkan
	//Menyimpan nilai dari node yang dihapus kedalam sebuah variabel
	Del_Awal(p, X, nama, kualitas);
}

void TampilkanNode(address *p, infotype *X, char **nama, char **kualitas){
//Menampilkan satu node yang telah dikeluarkan oleh stack
	PopStack(p, X, nama, kualitas);
	printf("%d", X);
}



