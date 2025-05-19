#ifndef Kota_H
#define Kota_H
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "linked.h"

typedef struct tListBuku *NextBuku;
typedef struct tListBuku{
	address pointer;
	NextBuku Next;
	char *Buku;
	int stock;
}ListBuku;

void CreateNodeBuku(NextBuku *k){
	
	*k = (NextBuku)malloc(sizeof(ListBuku));
}

void IsiNodeBuku(NextBuku *k, char *Buku, int stock){
	
		if(*k != NULL){
		(*k)->Buku = (char *)malloc((strlen(Buku) + 1) * sizeof(char));
		if ((*k)->Buku == NULL){
			printf("Memory Allocation nama gagal\n");
			free(*k);
			return;
		}
		strcpy((*k)->Buku,Buku);
		(*k)->stock = stock;
		(*k)->Next = NULL;	
		(*k)->pointer = NULL;
	} else {
		printf ("Node tidak dapat di isi\n");
	}
}

void InsertBuku_Awal(NextBuku *First, NextBuku k){
	
	if (k == NULL){
		printf("New Node is NULL\n");
		return;
	}

	(k)->Next = *First;
	*First = k;
}

void InsertBuku_Akhir(NextBuku *First, NextBuku k){
	if(*First == NULL){
		InsertBuku_Awal(First, k);
	} else{
		NextBuku curr = *First;
		while((curr)->Next != NULL){
			curr = (curr)->Next;
			}
		(curr)->Next = k;
	}
}

void DeleteBuku_Awal(NextBuku *First){
	if(*First == NULL){
		printf("There is nothing to delete\n");
		return;
	}
	
	NextBuku temp = *First;
	*First = temp->Next;
	Destroy_All(&(temp->pointer));
	free(temp->Buku);
	free(temp);
}

void DeleteBuku_Akhir(NextBuku *First){
	if(*First == NULL){
		printf("There is nothing to delete\n");
		return;
	}
	
	NextBuku prev = NULL;
	NextBuku curr = *First;
	while((curr)->Next != NULL){
		prev = curr;
		curr = (curr)->Next;
	}
	Destroy_All(&(curr->pointer));
	free(curr->Buku);
	free(curr);
	prev->Next = NULL;
}

void tambah_nama(NextBuku *k, char *nama, char* Pinjaman, Level Status){
	address Nama;
	
	Isi_Node(&Nama, nama, "", Status);
	if((*k)->pointer == NULL){
		Ins_Awal(&((*k)->pointer), Nama);
	} else {
		Ins_Akhir(&((*k)->pointer), Nama);
	}
}

void tambah_namaByUser(NextBuku *k){
	char nama[100];
	int Pilihan = 0;
	Level level;

	// Input nama
	printf("\nMasukan nama Peminjam: ");
	while (getchar() != '\n'); // Bersihkan buffer sebelum fgets
	fgets(nama, sizeof(nama), stdin);
	nama[strcspn(nama, "\n")] = '\0';

	if (strlen(nama) == 0) {
		printf("Nama tidak boleh kosong!\n");
		return;
	}
	nama[0] = toupper(nama[0]);

	// Input status
	printf("Pilih Status dari peminjam :\n");
	printf("1. Dosen\n");
	printf("2. Mahasiswa\n");
	printf("3. Umum\n");
	printf("Pilihan: ");
	scanf("%d", &Pilihan);
    //getchar(); // Bersihkan buffer setelah scanf

	switch (Pilihan) {
		case 1: level = Dosen; break;
		case 2: level = Mahasiswa; break;
		case 3: level = Umum; break;
		default:
			printf("Pilihan tidak valid. Menggunakan default (Umum).\n");
			level = Umum;
			break;
	}

	tambah_nama(k, nama, "", level);
	printf("Nama '%s' berhasil ditambahkan ke antrian peminjaman buku %s\n", nama, (*k)->Buku);
}

void delete_nama(NextBuku *k, char *nama){
    if (*k == NULL || (*k)->pointer == NULL) {
        printf("Tidak ada peminjam\n");
        return;
    }
    
    address prev = NULL;
    address curr = (*k)->pointer;
    
    while (curr != NULL) {
        if (strcmp(curr->name, nama) == 0) {
            if (prev == NULL) {
                (*k)->pointer = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr->name);
            free(curr->Pinjaman);
            free(curr);
            printf("Peminjam %s dihapus\n", nama);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Peminjam %s tidak ditemukan\n", nama);
}

void tampilkota(NextBuku *k){
	printf("\n%s = ", (*k)->Buku);
	Tampil_List((*k)->pointer);
}

void NukeKota(NextBuku *k){
	Destroy_All(&((*k)->pointer));
	free((*k)->Buku);
	(*k)->pointer = NULL;
}

void TampilkanDaftarKota(NextBuku First){
	NextBuku curr = First;
	if (curr == NULL){
		printf("Tidak ada buku untuk ditampilkan ke terminal\n");
		return;
	}
	
	int nomorBuku = 1;
	while (curr != NULL){
		printf("\n%d.%s",nomorBuku,curr->Buku);
		curr = curr->Next;
		nomorBuku++;
	}
	
}

void GetKotabyIndex(NextBuku First, int index, NextBuku *result){
	*result = NULL;
	
	if (index < 1){
		printf("index harus lebih besar dari 0\n");
		return;
	}

	int curr_index = 1;
	NextBuku curr = First;
	while(curr != NULL && curr_index != index){
		curr = curr->Next;
		curr_index++; 
	}
	
	if (curr == NULL){
		printf("Buku tidak ditemukan\n");
	} else {
		*result = curr;
	}

}

void TampilkanSemuaKotaDanPenduduk(NextBuku First){
	NextBuku curr = First;
	if (curr == NULL){
		printf("Tidak ada buku untuk ditampilkan ke terminal\n");
		return;
	}
	
	int nomorBuku = 1;
	while (curr != NULL){
    	printf("\n%d.%s = ",nomorBuku,curr->Buku);
    	Tampil_List(curr->pointer);
    	curr = curr->Next;
    	nomorBuku++;
	}
}

#endif
