#ifndef Kota_H
#define Kota_H
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "linked.h"

typedef struct {
	address pointer;
	char *Buku;
	int stock;
}ListBuku;

void NamaKota(ListBuku *k, char *Buku, int stock){
	k->Buku = (char *)malloc((strlen(Buku) + 1) * sizeof(char));
	if (k->Buku == NULL){
		printf("Memory Allocation nama gagal\n");
		free(k->Buku);
		return;
	}
	strcpy(k->Buku, Buku);
	k->stock = stock;
	k->pointer = NULL;
}

void tambah_nama(ListBuku *k, char *nama, char* Pinjaman, Level Status){
	address Nama;
	
	Create_Node(&Nama);
	Isi_Node(&Nama, nama, Pinjaman, Status);
	
	if(k->pointer == NULL){
		Ins_Awal(&(k->pointer), Nama);
	} else {
		Ins_Akhir(&(k->pointer), Nama);
	}
	
}

void tambah_namaByUser(ListBuku *k){
	char nama[100];
	printf("\nMasukan nama Peminjam: ");
	
	fgets(nama, sizeof(nama), stdin);
    nama[strcspn(nama, "\n")] = '\0';
    if (nama[0] != '\0') {
        nama[0] = toupper(nama[0]);
    }
	
	int Pilihan = 0;
	Level level;
	
	printf("Pilih Status dari peminjam :\n");
	printf("1. Dosen\n");
	printf("2. Mahasiswa\n");
	printf("3. Umum\n");
	
	scanf("%d", &Pilihan);
	getchar();
	
    switch (Pilihan) {
        case 1:
            level = Dosen;
            break;
        case 2:
            level = Mahasiswa;
            break;
        case 3:
            level = Umum;
            break;
        default:
            printf("Pilihan tidak valid. Menggunakan default (Public).\n");
            level = Umum;
            break;
    }
	
	tambah_nama(k, nama, NULL, level);
    printf("Nama '%s' berhasil ditambahkan ke antrian peminjaman buku %s\n", nama, k->Buku);
}

void delete_nama(ListBuku *k, char *nama){
	Del_Akhir(&(k->pointer));
}

void tampilkota(ListBuku *k){
	printf("\n%s = ", k->Buku);
	Tampil_List(k->pointer);
}

void NukeKota(ListBuku *k){
	Destroy_All(&(k->pointer));
	free(k->Buku);
	k->pointer = NULL;
}

#endif
