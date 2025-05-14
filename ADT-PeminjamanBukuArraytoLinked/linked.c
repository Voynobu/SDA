/* File        : linked.h */
/* Deskripsi   : ADT linked list dengan representasi fisik pointer */
/*		 Representasi address dengan pointer */
/*		 InfoType adalah integer */
/* Dibuat oleh : Ade Chandra Nugraha */

#ifndef linked_H
#define linked_H
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef enum {
	Dosen,
	Mahasiswa,
	Umum
} Level;

typedef struct tElmtList *address;
typedef struct tElmtList {
	address  next;
	char *name;
	char *Pinjaman; 
	Level Status;
	
 } ElmtList;

int isEmpty(address p){
// Tujuan : memeriksa apakah linked masih kosong
// Linked list kosong , jika Head == NULL
	if (p == NULL) {
			return 1;
	} else {
			return 0;
	}
}

void Create_Node (address *p){
// Tujuan : memesan memory dengan alokasi dinamis
// Jika berhasil mengirimkan address, dan jika gagal mengirimkan NULL
// Parameter : P (parameter Output)
	*p = (address)malloc(sizeof(ElmtList));
}

void Isi_Node (address *p , char *name, char *Pinjaman, Level Status){
// Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan
// Periksa keberadaan P, Nilai diisi jika P tidak NULL
//				*p.next diisi NULL
// Parameter : P (parameter Input-Output); Nilai (parameter Input)
	if(*p != NULL){
		(*p)->name = (char *)malloc((strlen(name) + 1) * sizeof(char));
		if ((*p)->name == NULL){
			printf("Memory Allocation nama gagal\n");
			free(*p);
			return;
		}
		strcpy((*p)->name, name);
		(*p)->Pinjaman = (char *)malloc((strlen(Pinjaman) + 1) * sizeof(char));
		if ((*p)->Pinjaman == NULL){
			printf("Memory Allocation nama gagal\n");
			free(*p);
			return;
		}
		(*p)->Status = Status;
		(*p)->Pinjaman = NULL;	
		(*p)->next = NULL;
	} else {
		printf ("Node tidak dapat di isi\n");
	}
}

void Tampil_List (address p){
// Tujuan : Menampilkan seluruh isi Linked List
// Parameter : p (parameter input)
	if(p == NULL){	
		printf("Linked list kosong\n");
		return;
	}

	while(p!= NULL){
		printf("%s -> ", (p)->name);
		p = (p)->next;
	}

	printf("NULL\n");
}

void Ins_Awal (address *p, address PNew){
// Tujuan : Insert 1 node baru (PNew) di awal Linked List
// Parameter : P (input-output)
//             PNew (input)
if (PNew == NULL){
		printf("PNew is NULL\n");
		return;
	}

(PNew)->next = *p;
*p = PNew;
}

void Ins_Akhir (address *p, address PNew){
/* Tujuan : menambahkan elemen list (PNew) di akhir LinkedList */
/* IS : p mungkin Kosong */
/* FS : menyambungkan elemen baru (PNew) di akhir Linked List */
	if (*p == NULL){
		*p = PNew;
	} else {
	address Last = *p;
	while ((Last)->next != NULL)
		{
			Last = (Last)->next;
		}
	(Last)->next = PNew;
	}
}


void InsertAfter (address * pBef, address PNew){
/* Tujuan : Menyambungkan 1 Node baru(PNew) stlah node tertentu(PBef) */
/* IS : pBef sudah dialokasi */
/* FS : Insert PNew sebagai elemen sesudah PBef */
/* Asumsi : pBef adalah posisi insert */
if (PNew != NULL && *pBef != NULL){
		(PNew)->next = (*pBef)->next;
		(*pBef)->next = PNew;
	} else {
		printf ("Node Invalid\n");
	}
}

void Del_Awal(address *p){
    /* IS : P TIDAK Kosong */
    /* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
    /* dan alamat elemen pertama di dealokasi */

    if(*p == NULL){
        printf("Tidak ada yang dapat dihapus\n");
        return;
    }

    address temp = *p;         // Simpan node yang mau dihapus         // Ambil info-nya
    *p = temp->next; 
	free(temp->name);   
	free(temp->Pinjaman);      // Pindahkan head ke node berikutnya
    free(temp);                // Dealokasi node lama
}


void Del_Akhir (address * p){
/* IS : P TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */
	if (*p == NULL){
		printf("Tidak ada node untuk dihapus\n");
		return;
	}

	address prev = NULL;
	address Last = *p;
	
	if(Last->next == NULL){
		free(Last);
		*p = NULL;
	}
	
	while ((Last)->next != NULL){
		prev = Last;
		Last = (Last)->next;
	}
	free(Last->Pinjaman);
	free(Last->name);
	free(Last);
	prev->next=NULL;
	
}

void Del_After (address * pBef){
/* IS : pBef TIDAK Kosong (hasil search posisi node sebelum yang didel)*/
/* FS : menghapus Node setelah pBef */
/*      nilai info node yang dihapus disimpan pada X */
/* 	  dan alamat elemen setelah pBef di dealokasi */
	if (*pBef != NULL && (*pBef)->next != NULL){
		address temp = (*pBef)->next;
		(*pBef)->next = temp->next;
		free(temp->Pinjaman);
		free(temp->name);
		free(temp);
	} else {
		printf ("Node Invalid\n");
	}

}

void Del_Middle(address *pT, char *name) {
    if (*pT == NULL) {
        printf("List kosong\n");
        return;
    }

    address curr = *pT;
    address prev = NULL;

    while (curr != NULL) {
        if (curr->Pinjaman != NULL && strcmp(curr->Pinjaman, name) == 0) {
            if (prev == NULL) {
                *pT = curr->next; 
            } else {
                prev->next = curr->next;
            }
            free(curr->Pinjaman);
            free(curr->name);
            free(curr);
            printf("Peminjaman selesai\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Peminjam tidak ditemukan\n");
}


void DeAlokasi (address * p){
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
	if(*p == NULL){
		printf ("P sudah NULL\n");
		return;
	}
	free((*p)->Pinjaman);
	free((*p)->name);
	free(*p);
	*p = NULL;
}

int NbElmt (address p){
/* Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong */
// Recursif Mode
	int Jumlah = 0;
	address curr = p;

	if (p == NULL){
		return 0;
	}

	while (curr != NULL){
		Jumlah++;
		curr = (curr)->next;
	}
	
	return Jumlah;
}





/* IS : p sembarang */
/* FS : Elemen List dibalik : elemen terakhir menjadi elemen pertama, dst */
address BalikList(address p) {
    address prev = NULL;    
    address current = p;   
    address next = NULL;

    while (current != NULL) {
        next = (current)->next; 
        (current)->next = prev; 
        prev = current;       
        current = next;       
    }

    return prev;
}

void Destroy_All(address *p){

	if(*p == NULL){
		printf ("\nP sudah NULL\n");
		return;
	}

	address temp = *p;

	while(*p != NULL){
	
		temp = *p;
		*p = (*p)->next;
		free(temp->Pinjaman);
		free(temp->name);
		free(temp);
	}


}



#endif

