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

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
	infotype info;
	address  next;
	char *name;
	char *kualitas;	
		
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
    if (*p == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    (*p)->next = NULL;
}

void Isi_Node (address *p , infotype nilai, char *name, char *kualitas){
// Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan
// Periksa keberadaan P, Nilai diisi jika P tidak NULL
//				*p.next diisi NULL
// Parameter : P (parameter Input-Output); Nilai (parameter Input)
    if (*p != NULL) {
        (*p)->name = (char *)malloc((strlen(name) + 1) * sizeof(char));
        if ((*p)->name == NULL) {
            printf("Memory Allocation nama gagal\n");
            free(*p);
            return;
        }
        strcpy((*p)->name, name);

        (*p)->kualitas = (char *)malloc((strlen(kualitas) + 1) * sizeof(char));
        if ((*p)->kualitas == NULL) {
            printf("Memory Allocation kualitas gagal\n");
            free((*p)->name);
            free(*p);
            return;
        }
        strcpy((*p)->kualitas, kualitas);

        (*p)->info = nilai;
        (*p)->next = NULL; 
    } else {
        printf("Node tidak dapat diisi\n");
    }
}

void Tampil_List (address p){
// Tujuan : Menampilkan seluruh isi Linked List
// Parameter : p (parameter input)
    if (p == NULL) {
        printf("Linked list kosong\n");
        return;
    }

    while (p != NULL) {
        printf("Nama: %s, Kualitas: %s =>", p->name, p->kualitas);
        p = p->next;
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
    if (PNew == NULL) {
        printf("Node tidak valid\n");
        return;
    }
    if (*p == NULL) {
        *p = PNew; // Jika linked list kosong, set head ke PNew
    } else {
        address temp = *p;
        while (temp->next != NULL) {
            temp = temp->next; // Cari node terakhir
        }
        temp->next = PNew; // Tambahkan node baru di akhir
    }
}

address Search(address p, infotype nilai, int *position){
    // Mencari apakah ada elemen list dengan Info(P) = nilai
    // Jika ada, mengembalikan address elemen tsb.
    // Jika tidak ada, mengembalikan Nil
    // Menggunakan variabel bertipe boolean

    address curr = p;
    *position = 0;

    while(curr != NULL){
        if(curr->info == nilai){
            return curr;
        }
        curr = curr->next;
        (*position)++;
    }
    return NULL; // Nil
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


void Del_Awal(address *p, infotype *X, char **nama, char **kualitas) {
    if (*p == NULL) {
        printf("Tidak ada yang dapat dihapus\n");
        return;
    }

    address temp = *p; // Simpan node pertama ke variabel sementara
    *X = temp->info;

    *nama = (char *)malloc((strlen(temp->name) + 1) * sizeof(char));
    if (*nama == NULL) {
        printf("Memory Allocation untuk nama gagal\n");
        return;
    }
    strcpy(*nama, temp->name);

    *kualitas = (char *)malloc((strlen(temp->kualitas) + 1) * sizeof(char));
    if (*kualitas == NULL) {
        printf("Memory Allocation untuk kualitas gagal\n");
        free(*nama); // Bebaskan memori yang sudah dialokasikan
        return;
    }
    strcpy(*kualitas, temp->kualitas);

    *p = temp->next; // Pindahkan head ke node berikutnya

    // Dealokasi memori node yang dihapus
    free(temp->name);
    free(temp->kualitas);
    free(temp);

    // Atur pointer temp ke NULL setelah dealokasi
    temp = NULL;

    printf("Debug: Node pertama (%s, %s) telah dihapus.\n", *nama, *kualitas);
}

void Del_Akhir (address * p, infotype * X){
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
		*X = Last->info;
		free(Last);
		*p = NULL;
	}
	
	while ((Last)->next != NULL){
		prev = Last;
		Last = (Last)->next;
	}
	*X = Last->info;
	free(Last->name);
	free(Last);
	prev->next=NULL;
	
}

void Del_After (address * pBef, infotype * X){
/* IS : pBef TIDAK Kosong (hasil search posisi node sebelum yang didel)*/
/* FS : menghapus Node setelah pBef */
/*      nilai info node yang dihapus disimpan pada X */
/* 	  dan alamat elemen setelah pBef di dealokasi */
	if (*pBef != NULL && (*pBef)->next != NULL){
		address temp = (*pBef)->next;
		*X = temp->info;
		(*pBef)->next = temp->next;
		free(temp->name);
		free(temp);
	} else {
		printf ("Node Invalid\n");
	}

}

void DeAlokasi (address * p){
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
	if(*p == NULL){
		printf ("P sudah NULL\n");
		return;
	}
	
	free((*p)->name);
	free(*p);
	*p = NULL;
}

int NbElmt (address p){
/* Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong */
// Recursif Mode
	infotype Jumlah = 0;
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

infotype Min (address p){
/* Mengirimkan nilai Info(P) yang minimum */
	if (p == NULL){
		printf("Node tidak ada\n");
		return 0;
	}
	
	int Min = (p)->info;
	address curr = (p)->next;

	while(curr != NULL){
		if ((curr)->info < Min){
			Min = (curr)->info;
		}
		curr = (curr)->next;
	}

	return Min;
}

infotype Rerata (address p){
/* Mengirimkan nilai rata-rata Info(P) */
	if(p == NULL){
		printf("Node tidak ada, rerata = 0.0\n");
		return 0;
	}
	
	address curr = p;
	int Total = 0;
	int JumlahNode = 0;
	float Rerata;

	while (curr != NULL){
		Total += (curr)->info;
		JumlahNode++;
		curr = (curr)->next;
	}

	Rerata = Total / JumlahNode;
	return Rerata;
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
		printf ("P sudah NULL\n");
		return;
	}

	address temp = *p;

	while(*p != NULL){
	
		temp = *p;
		*p = (*p)->next;
		free(temp->name);
		free(temp);
	}

}

void Modify_First(address *p, infotype *X){
	if(*p == NULL){
		printf("Node tidak terdeteksi\n");
		return;
	}
	
	(*p)->info = *X;
}



void Modify_Between(address *p, infotype *X, int position){
	if(*p != NULL){
		address curr = *p;
		int i = 0;
		while(curr != NULL && i <= position){
			curr = curr->next;
			i++;
		}
		curr->info = *X;
	}
	
	printf("Node tidak terdeteksi\n");
	return;
}
void Modify_Last(address *p, infotype *X){
	if(*p != NULL){
		address curr = *p;
		while(curr != NULL){
			curr = curr->next;
		}
		curr->info = *X;
	}
	
	printf("Node tidak terdeteksi\n");
	return;
}

void SortByKualitas(address p) {
    if (p == NULL || p->next == NULL) {
        return; 
    }

    int swapped;
    address ptr1;
    address lptr = NULL;

    do {
        swapped = 0;
        ptr1 = p;

        while (ptr1->next != lptr) {
            if (strcmp(ptr1->kualitas, ptr1->next->kualitas) > 0) {
                
                char *tempKualitas = ptr1->kualitas;
                ptr1->kualitas = ptr1->next->kualitas;
                ptr1->next->kualitas = tempKualitas;
                
                char *tempName = ptr1->name;
                ptr1->name = ptr1->next->name;
                ptr1->next->name = tempName;

               
                infotype tempInfo = ptr1->info;
                ptr1->info = ptr1->next->info;
                ptr1->next->info = tempInfo;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    printf("\nHasil sorting secara nama (ascending):\n");
}


#endif

