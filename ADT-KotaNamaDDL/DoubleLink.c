#ifndef DoubleLink_H
#define DoubleLink_H
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "linked.h"
#include <ctype.h>

typedef struct ListKota ListKota;
typedef struct ListKota *Nextkota;
struct ListKota {
    address pointer;
    Nextkota next; 
    char *Kota;
};

void CreateNodeKota(Nextkota *k){
	*k = (Nextkota)malloc(sizeof(ListKota));
}

void IsiNodeKota(Nextkota *k, char *Kota){
	(*k)->Kota = (char *)malloc((strlen(Kota) + 1) * sizeof(char));
	if ((*k)->Kota == NULL){
		printf("Memory Allocation nama gagal\n");
		free((*k)->Kota);
		*k = NULL;
		return;
	}
	strcpy((*k)->Kota, Kota);
	(*k)->pointer = NULL;
	(*k)->next = NULL;
}

void InsertKota_Awal(Nextkota *First, Nextkota k){
	
	if (k == NULL){
		printf("New Node is NULL\n");
		return;
	}

	(k)->next = *First;
	*First = k;
}

void InsertKota_Akhir(Nextkota *First, Nextkota k){
	if(*First == NULL){
		InsertKota_Awal(First, k);
	} else{
		Nextkota curr = *First;
		while((curr)->next != NULL){
			curr = (curr)->next;
			}
		(curr)->next = k;
	}
}

void DeleteKota_Awal(Nextkota *First){
	if(*First == NULL){
		printf("There is nothing to delete\n");
		return;
	}
	
	Nextkota temp = *First;
	*First = temp->next;
	Destroy_All(&(temp->pointer));
	free(temp->Kota);
	free(temp);
}

void DeleteKota_Akhir(Nextkota *First){
	if(*First == NULL){
		printf("There is nothing to delete\n");
		return;
	}
	
	Nextkota prev = NULL;
	Nextkota curr = *First;
	while((curr)->next != NULL){
		prev = curr;
		curr = (curr)->next;
	}
	Destroy_All(&(curr->pointer));
	free(curr->Kota);
	free(curr);
	prev->next = NULL;
}

void tambah_nama(Nextkota *k, char *nama){
	address Nama;
	
	Create_Node(&Nama);
	Isi_Node(&Nama, nama);
	
	if((*k)->pointer == NULL){
		Ins_Awal(&((*k)->pointer), Nama);
	} else {
		Ins_Akhir(&((*k)->pointer), Nama);
	}
}

void tambah_namaByUser(Nextkota *k){
	char nama[100];
	printf("\nMasukan nama penduduk: ");
	
	fgets(nama, sizeof(nama), stdin);
    nama[strcspn(nama, "\n")] = '\0';
    if (nama[0] != '\0') {
        nama[0] = toupper(nama[0]);
    }
	
	tambah_nama(k, nama);
    printf("Nama '%s' berhasil ditambahkan ke kota %s\n", nama, (*k)->Kota);
}


void delete_nama(Nextkota *k, char *nama){
	Del_Akhir(&((*k)->pointer));
}

void TampilkanDaftarKota(Nextkota First) {
    int counter = 1;
    printf("\nDaftar Kota:\n");
    while (First != NULL) {
        printf("%d. %s\n", counter++, First->Kota);
        First = First->next;
    }
}

void GetKotabyIndex(Nextkota First, int index, Nextkota *result){
	*result = NULL;
	
	if(index < 1){
		printf("index harus lebih dari 0\n");
		return;
	}
	
	int currIndex = 1;
	while(First != NULL && currIndex != index){
		First = First->next;
		currIndex++;
	}
	
	if (First == NULL){
		printf("Kota yang dicari tidak ada\n");
		return;
	}
	
	*result = First;
	
}

void tampilkota(Nextkota *k){
	printf("\n%s = ", (*k)->Kota);
	Tampil_List((*k)->pointer);
}

void TampilkanSemuaKotaDanPenduduk(Nextkota First) {
    if (First == NULL) {
        printf("Belum ada kota terdaftar!\n");
        return;
    }

    printf("\n=== DAFTAR KOTA DAN PENDUDUK ===\n");
    
    int nomorKota = 1;
    while (First != NULL) {
        // Tampilkan nama kota
        printf("%d. %s:\n", nomorKota++, First->Kota);
        
        // Tampilkan daftar penduduk
        address penduduk = First->pointer;
        if (penduduk == NULL) {
            printf("   - (Belum ada penduduk)\n");
        } else {
            int nomorPenduduk = 1;
            while (penduduk != NULL) {
                printf("   %d. %s\n", nomorPenduduk++, penduduk->name);
                penduduk = penduduk->next;
            }
        }
        
        First = First->next;
        printf("\n"); // Spasi antar kota
    }
}


void NukeKota(Nextkota *k){
	if (*k == NULL){
		printf("Tidak ada kota untuk diledakkan\n");
		return;
	}
	
	Nextkota temp;
	while (*k != NULL){
		temp = *k;
		*k = temp->next;
		Destroy_All(&(temp->pointer));
		free(temp->Kota);
		free(temp);
	}
	
}


#endif
