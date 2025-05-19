#ifndef Peminjaman_H
#define Peminjaman_H
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "Kota.h"

address findDosen(address p){
//Digunakan untuk mencari peminjam dengan status dosen dilist peminjam
	
	while(p != NULL){
		if(p->Status == Dosen){
			return p;
		}
		p = p->next;
	}
	return NULL;
	
}

address findMahasiswa(address p){
//Digunakan untuk mencari peminjam dengan status mahasiswa dilist peminjam

	while(p != NULL){
		if(p->Status == Mahasiswa){
			return p;
		}
		p = p->next;
	}
	return NULL;

}

address findUmum(address p){
//Digunakan untuk mencari peminjam dengan status umum dilist peminjam

	while(p != NULL){
		if(p->Status == Umum){
			return p;
		}
		p = p->next;
	}
	return NULL;

}


void StartPeminjaman(ListBuku *k){
//1. Cek apakah stok peminjaman kurang dari stok buku (jika kurang jalankan)
//2. Mencari dalam linked list peminjam mulai dari Dokter - Mahasiswa - Umum
//3. Mengambil informasi buku dari list buku lalu copy ke pinjaman dari peminjam yang sudah ditentukan dari proses mencari
//4. Menambahkan stok peminjaman setelah proses diatas dilakukan.

	if(k->stock == 0){
		printf("stock buku penuh\n");
		return;
	}

	address peminjam = NULL;
	
	peminjam = findDosen(k->pointer);
	if(peminjam == NULL){
		peminjam = findMahasiswa(k->pointer);
	}
	if(peminjam == NULL){
		peminjam = findUmum(k->pointer);
	}
	if(peminjam != NULL){
		peminjam->Pinjaman = (char *)malloc((strlen(k->Buku) + 1) * sizeof(char));
		strcpy(peminjam->Pinjaman, k->Buku);
		printf("%s sedang meminjam %s\n", peminjam->name, k->Buku);
		
		k->stock--;
		printf("Stock %s saat ini: %d\n", k->Buku, k->stock);
	}else{
		printf("Tidak dapat menemukan calon peminjam\n");
	}
}

void SelesaikanPeminjaman(ListBuku *k){
	Del_Middle(&k->pointer, k->Buku);
	k->stock++;
	printf("Stock %s saat ini: %d\n", k->Buku, k->stock);
}

void CancelAntrian(ListBuku *k) {
    char input[100];  // Fixed: Use array instead of uninitialized pointer
    
    printf("Masukan nama yang ingin dibatalkan: ");
    if (scanf("%99s", input) != 1) {  // Limit input to prevent overflow
        printf("Input tidak valid\n");
        while (getchar() != '\n');  // Clear input buffer
        return;
    }

    if (k->pointer == NULL) {
        printf("Antrian kosong\n");
        return;
    }

    address curr = k->pointer;
    address prev = NULL;

    while (curr != NULL) {
        if (curr->name != NULL && strcmp(curr->name, input) == 0) {
            if (prev == NULL) {
                k->pointer = curr->next;  // Update head if deleting first node
            } else {
                prev->next = curr->next;
            }

            // Free memory
            if (curr->Pinjaman != NULL) {
                free(curr->Pinjaman);
            }
            free(curr->name);
            free(curr);

            printf("Peminjaman %s dibatalkan pada %s.\n", input, k->Buku);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Peminjam tidak ditemukan\n");
	
}

#endif
