#ifndef Praktikum_H
#define Praktikum_H
#include <stdio.h>
#include <malloc.h>
#include "Queue.h"
#include "Stack.h"

void Create_Mahasiswa(address *p, address MNew, char *nama);

void Create_Alat(address *p, address MNew, char *nama, char *kualitas);

void Create_Peminjaman(address *p, address MNew, char *NamaMahasiswa, char *NamaAlat);

void AddStackAlat(address *p, address MNew, char *nama, char *kualitas);

void AddListKualitas(address *p, address MNew, char *nama, char *kualitas);


void Search_QualityAlat(address p, infotype X, char **nama, char **kualitas);
//Akan berjalan ketika kita memberikan alat kepada mahasiswa berdasarkan kualitas
//Program akan mencari kualitas terbaik dari linkedlist alat praktikum lalu memberikannya ke mahasiswa
//untuk mempermudah akan digunakan sorting dan setelah sort node terdepan akan diambil
//Informasi dari node depan akan diambil lalu node didealokasi
//Informasi yang diambil akan dipakai untuk node proses peminjaman baru

void Display_Stock(address p);
//Menampilkan stock alat beserta kualitasnya 

void updateQuality(char *kualitas);//parameter belum ditentukan
//mengubah kualitas alat setelah dipinjam

void Trash_Stock(address p);
//Mengdealokasi linkedlist dari alat praktikum
//Digunakan setelah keluar dari program (menggunakan opsi exit)

void addQueue(address *p, address MNew);
//Menambahkan Mahasiswa kedalam antrian untuk meminjam alat praktikum lalu menampilkan keadaan queue

void StartQueue(address p, infotype X, char **nama, char **kualitas);//Parameter belum ditentukan
//Melayani mahasiswa dengan pertama mendealokasi mashasiwa yang dilayani (First served) lalu mengambil inforamsinya untuk dimasukkan kedalam proses peminjaman
//Dimana kita akan memilih untuk memberikan alat praktikum secara kualitas atau secara terakhir digunakan 
//Sesuai dengan opsi program akan mengdealokasi antara Stack alat atau linked list alat lalu menyalin informasinya untuk dimasukkan kedalam proses peminjaman

void AddToBorrowProcess(address *p, address *p2, address MNew, char *NamaMahasiswa, char *NamaAlat, char *kualitas);//parameter belum ditentukan
//Membuat node baru menggunakan inforamsi yang telah diambil dari Mahasiswa dan Alat
//Memasukan node tersebut kesebuah queue baru

void ShowBorrowProcess(address p);
//Menunjukkan queue dari proses peminjaman

void EndBorrowProcess(address p, address p2,address *alatList, address *alatStack);
//untuk setiap node yang didealokasi nama dan kualitas dari alat akan disimpan 
//Kualitas alat akan diturunkan, lalu jika kualitas alat sebelum diubah bukan poor maka dia akan dimasukkan kembail ke linked list alat
//Alat tersebut juga akan dimasukkan kedalam stack untuk opsi pinjam menurut terakhir digunakan

void RecentUsed(address *p, infotype *X, char **nama, char **kualitas);//parameter belum ditentukan
//Bekerja seperti stack
//Mengambil informasi dari node terakhir lalu mengdealokasi node tersebut
//informasi yang diambil akan dipakai untuk node proses peminjaman baru

void AddRecent(address *p, infotype *X, char **nama, char **kualitas);//parameter belum ditentukan
//Membuat node baru dengan informasi dari alat dan kualitasnya yang baru saja dipinjam (setelah selesai dipinjam)



#endif
