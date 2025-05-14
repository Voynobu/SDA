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

void NamaKota(ListBuku *k, char *Buku, int stock);
void tambah_nama(ListBuku *k, char *nama, char* Pinjaman, Level Status);
void tambah_namaByUser(ListBuku *k);
void delete_nama(ListBuku *k, char *nama);
void tampilkota(ListBuku *k);
void NukeKota(ListBuku *k);

#endif
