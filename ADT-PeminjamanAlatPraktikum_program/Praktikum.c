#ifndef Praktikum_H
#define Praktikum_H
#include <stdio.h>
#include <malloc.h>
#include "Queue.h"
#include "Stack.h"


void Create_Mahasiswa(address *p, address MNew, char *nama){
    MNew = NULL; 
    Create_QNode(&MNew);
    if (MNew == NULL) {
        printf("Gagal membuat node mahasiswa\n");
        return;
    }
    Fill_QNode(&MNew, 0, nama, "");
    Get_inQueue(p, MNew);
    printf("Mahasiswa %s berhasil ditambahkan ke queue.\n", nama);
}

void Create_Peminjaman(address *p, address MNew, char *NamaMahasiswa, char *NamaAlat){
	Create_QNode(&MNew);
	Fill_QNode(&MNew, 0, NamaMahasiswa, NamaAlat);
	Get_inQueue(p, MNew);
}

void Create_Alat(address *p, address MNew, char *nama, char *kualitas){
	Create_QNode(&MNew);
	printf("Alokasi node berhasil\n");
	Fill_QNode(&MNew, 0, nama, kualitas);
	printf("Isi informasi node berhasil\n");
	Get_inQueue(p, MNew);
	printf("Node berhasil dimasukan kedalam queue\n");
}

void AddStackAlat(address *p, address MNew, char *nama, char *kualitas){
	CreateNodeStack(&MNew);
	IsiNodeStack(&MNew, 0, nama, kualitas);
	PushStack(p, MNew);
}

void AddListKualitas(address *p, address MNew, char *nama, char *kualitas){
	Create_QNode(&MNew);
	Fill_QNode(&MNew, 0, nama, kualitas);
	Get_inQueue(p, MNew);
}

void Search_QualityAlat(address *p, infotype *X, char **nama, char **kualitas) {
    // Jika linked list kosong, kembalikan
    if (*p == NULL) {
        printf("Linked list alat kosong.\n");
        *nama = NULL;
        *kualitas = NULL;
        return;
    }

    // Simpan informasi dari node pertama
    *nama = (char *)malloc((strlen((*p)->name) + 1) * sizeof(char));
    if (*nama == NULL) {
        printf("Memory Allocation untuk nama gagal\n");
        return;
    }
    strcpy(*nama, (*p)->name);

    *kualitas = (char *)malloc((strlen((*p)->kualitas) + 1) * sizeof(char));
    if (*kualitas == NULL) {
        printf("Memory Allocation untuk kualitas gagal\n");
        free(*nama); // Bebaskan memori yang sudah dialokasikan
        return;
    }
    strcpy(*kualitas, (*p)->kualitas);

    // Hapus node pertama dari linked list
    address temp = *p; // Simpan node pertama ke variabel sementara
    *p = (*p)->next;   // Pindahkan head ke node berikutnya

    // Dealokasi memori node yang dihapus
    free(temp->name);
    free(temp->kualitas);
    free(temp);

    printf("Alat pertama (%s, %s) telah dihapus.\n", *nama, *kualitas);
}

void Display_Stock(address p){
//Menampilkan stock alat beserta kualitasnya 
	
	Tampil_List(p);
}

void updateQuality(char *kualitas) {
    // Mengubah kualitas alat setelah dipinjam
    if (strcmp(kualitas, "Excellent") == 0) {
        strcpy(kualitas, "Good");
    } else if (strcmp(kualitas, "Good") == 0) {
        strcpy(kualitas, "Poor");
    }
}

void Trash_Stock(address p){
//Mengdealokasi linkedlist dari alat praktikum
//Digunakan setelah keluar dari program (menggunakan opsi exit)

	Destroy_All(&p);
	Tampil_List(p);
}

void addQueue(address *p, address MNew, char *nama){
//Menambahkan Mahasiswa kedalam antrian untuk meminjam alat praktikum lalu menampilkan keadaan queue

	Create_Mahasiswa(p, MNew, nama);
}

void StartQueue(address *p, infotype *X, char **nama, char **kualitas){
//Melayani mahasiswa dengan pertama mendealokasi mashasiwa yang dilayani (First served) lalu mengambil inforamsinya untuk dimasukkan kedalam proses peminjaman
//Dimana kita akan memilih untuk memberikan alat praktikum secara kualitas atau secara terakhir digunakan 
//Sesuai dengan opsi program akan mengdealokasi antara Stack alat atau linked list alat lalu menyalin informasinya untuk dimasukkan kedalam proses peminjaman

	Get_outQueue(p, X, nama, kualitas);
}

void AddToBorrowProcess(address *p, address *p2, address MNew, char *NamaMahasiswa, char *NamaAlat, char *kualitas){//parameter belum ditentukan
//Membuat node baru menggunakan inforamsi yang telah diambil dari Mahasiswa dan Alat
//Memasukan node tersebut kesebuah queue baru
	
	Create_Peminjaman(p, MNew, NamaMahasiswa, NamaAlat);
	AddListKualitas(p2, MNew, NamaAlat, kualitas);
}

void ShowBorrowProcess(address p){
//Menunjukkan queue dari proses peminjaman
	Tampil_List(p);
}

void EndBorrowProcess(address p, address p2, address *alatList, address *alatStack){//parameter belum dtentukan
//Menyelesaikan proses peminjaman (queue didealokasi)
//untuk setiap node yang didealokasi nama dan kualitas dari alat akan disimpan 
//Kualitas alat akan diturunkan, lalu jika kualitas alat sebelum diubah bukan poor maka dia akan dimasukkan kembail ke linked list alat
//Alat tersebut juga akan dimasukkan kedalam stack untuk opsi pinjam menurut terakhir digunakan
	
	infotype X;
    char *nama, *namaalat, *kualitas;

    // Hapus node pertama dari queue peminjaman
	Get_outQueue(&p, &X, &nama, &namaalat);
	Get_outQueue(&p2, &X, &namaalat, &kualitas);
    // Update kualitas alat menggunakan fungsi updateQuality
    updateQuality(kualitas);

    // Jika kualitas bukan "Poor", masukkan kembali ke linked list alat dan stack
    if (strcmp(kualitas, "Poor") != 0) {
        // Tambahkan ke linked list alat
        address newAlat;
        Create_Node(&newAlat);
        Isi_Node(&newAlat, 0, namaalat, kualitas);
        Ins_Akhir(alatList, newAlat);

        // Tambahkan ke stack alat
        address stackAlat;
        Create_Node(&stackAlat);
        Isi_Node(&stackAlat, 0, namaalat, kualitas);
        PushStack(alatStack, stackAlat);
        
        printf("%s dengan kualitas %s dimasukkan kembali ke linked list dan stack.\n", namaalat, kualitas);
    } else {
    	printf("Alat sudah rusak dan tidak dapat digunakan kembali\n");
	}

    // Dealokasi memori
    free(nama);
    free(kualitas);
    free(namaalat);
}

void RecentUsed(address *p, infotype *X, char **nama, char **kualitas){
//Bekerja seperti stack
//Mengambil informasi dari node terakhir lalu mengdealokasi node tersebut
//informasi yang diambil akan dipakai untuk node proses peminjaman baru
	
	PopStack(p, X, nama, kualitas);
}

void AddRecent(address *p, address MNew, char *nama, char *kualitas){
//Membuat node baru dengan informasi dari alat dan kualitasnya yang baru saja dipinjam (setelah selesai dipinjam)

	AddStackAlat(p, MNew, nama, kualitas);
}



#endif








