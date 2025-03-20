#define StackBiner_H
#include <stdio.h>
#include <malloc.h>
#include "linked.h"

int StackisEmpty(address p);
//Mengecek apakah Stack yang digunakan = NULL

void CreateNodeStack(address *p);
//Membuat node baru yang akan digunakan untuk stack

void IsiNodeStack(address *p, infotype nilai);
//Memberi node yang baru dibuat sebuah nilai dan pointer next

void PushStack(address *p, address SNew);
//Menambahkan node baru kedalam stack

int PopStack(address *p, infotype *X);
//Menghapus satu node dalam stack (node yang dihapus adalah node yang terakhir kali dimasukkan
//Menyimpan nilai dari node yang dihapus kedalam sebuah variabel

void TampilkanNode(infotype *X);
//Menampilkan satu node yang telah dikeluarkan oleh stack

void KonversiDecimaltoBiner(infotype decimal, address *p);
//Mengkonversi suatu nilai desimal menjadi biner dengan metode stack

void TampilkanBiner(address *p);
//Menampilkan isi dari stack yang merupakan hasil konversi dari Desimal ke Biner
