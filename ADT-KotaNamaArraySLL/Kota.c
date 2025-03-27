#ifndef Kota_H
#define Kota_H
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "linked.h"

typedef struct {
	address pointer;
	char *Kota;
}ListKota;

void NamaKota(ListKota *k, char *Kota){
	k->Kota = (char *)malloc((strlen(Kota) + 1) * sizeof(char));
	if (k->Kota == NULL){
		printf("Memory Allocation nama gagal\n");
		free(k->Kota);
		return;
	}
	strcpy(k->Kota, Kota);
	k->pointer = NULL;
}

void tambah_nama(ListKota *k, char *nama){
	address Nama;
	
	Create_Node(&Nama);
	Isi_Node(&Nama, nama);
	
	if(k->pointer == NULL){
		Ins_Awal(&(k->pointer), Nama);
	} else {
		Ins_Akhir(&(k->pointer), Nama);
	}
	
}

void tambah_namaByUser(ListKota *k){
	char nama[100];
	printf("\nMasukan nama penduduk: ");
	
	fgets(nama, sizeof(nama), stdin);
    nama[strcspn(nama, "\n")] = '\0';
    if (nama[0] != '\0') {
        nama[0] = toupper(nama[0]);
    }
	
	tambah_nama(k, nama);
    printf("Nama '%s' berhasil ditambahkan ke kota %s\n", nama, k->Kota);
}

void delete_nama(ListKota *k, char *nama){
	Del_Akhir(&(k->pointer));
}

void tampilkota(ListKota *k){
	printf("\n%s = ", k->pointer);
	Tampil_List(k->pointer);
}

void NukeKota(ListKota *k){
	Destroy_All(&(k->pointer));
	free(k->Kota);
	k->pointer = NULL;
}

#endif
