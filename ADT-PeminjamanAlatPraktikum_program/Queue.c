#ifndef Queue_H
#define Queue_H
#include <stdio.h>
#include <malloc.h>
#include "linked.h"

int isQueueEmpty(address p){
//mengecek apakah queue yang sudah dibuat kosong atau tidak
//jika kosong maka akan mengembalikan NULL
	
	return isEmpty(p);
}



void Create_QNode(address *p){
//Membuat node untuk ditambahkan kedalam queue
//node belum memiliki nilai dan pointer next belum menunjuk apapun

	Create_Node(p);
}


void Fill_QNode(address *p, infotype X, char *nama, char *kualitas){
//Memberikan nilai kepada node yang kosong
//Pointer next pada node menunjuk NULL

	Isi_Node(p, X, nama, kualitas);
}


void Get_inQueue(address *p, address QNew){
//Node masuk kedalam queue
//Node yang baru dimasukan kedalam queue akan menjadi urutan terakhir dalam queue
    if (QNew == NULL) {
        printf("Node tidak valid\n");
        return;
    }
	Ins_Akhir(p, QNew);
}


void Get_outQueue(address *p, infotype *X, char **nama, char **kualitas){
//Memproses node queue paling depan, lalu menyimpan nilai dari node tersebut untuk ditampilkan
//Node yang telah diproses akan dihapus
	
	Del_Awal(p, X, nama, kualitas);
}


void Show_Queue(address p){
//Menampilkan keadaan queue saat ini
	
	Tampil_List(p);
}


int Waiting_inQueue(address p){
//Menghitung jumlah node dalam queue 
	int Jumlah = NbElmt(p);
	return Jumlah;
}

void Destroy_Queue(address p){
//Menghapus seluruh node dalam queue

	Destroy_All(&p);
}


#endif
