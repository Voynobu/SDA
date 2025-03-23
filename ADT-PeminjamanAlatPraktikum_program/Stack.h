#define StackBiner_H
#include <stdio.h>
#include <malloc.h>
#include "linked.h"

int StackisEmpty(address p);
//Mengecek apakah Stack yang digunakan = NULL

void CreateNodeStack(address *p);
//Membuat node baru yang akan digunakan untuk stack

void IsiNodeStack(address *p, infotype X, char *nama, char *kualitas);
//Memberi node yang baru dibuat sebuah nilai dan pointer next

void PushStack(address *p, address SNew);
//Menambahkan node baru kedalam stack

int PopStack(address *p, infotype *X, char **nama, char **kualitas);
//Menghapus satu node dalam stack (node yang dihapus adalah node yang terakhir kali dimasukkan
//Menyimpan nilai dari node yang dihapus kedalam sebuah variabel

void TampilkanNode(address *p, infotype *X, char **nama, char **kualitas);
//Menampilkan satu node yang telah dikeluarkan oleh stack


