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

void CreateNodeBuku(NextBuku *k);
void IsiNodeBuku(NextBuku *k, char *Buku, int stock);
void InsertBuku_Awal(NextBuku *First, NextBuku k);
void InsertBuku_Akhir(NextBuku *First, NextBuku k);
void DeleteBuku_Awal(NextBuku *First);
void DeleteBuku_Akhir(NextBuku *First);
void tambah_nama(NextBuku *k, char *nama, char* Pinjaman, Level Status);
void tambah_namaByUser(NextBuku *k);
void delete_nama(NextBuku *k, char *nama);
void tampilkota(NextBuku *k);
void NukeKota(NextBuku *k);
void TampilkanDaftarKota(NextBuku First);
void GetKotabyIndex(NextBuku First, int index, NextBuku *result);
void TampilkanSemuaKotaDanPenduduk(NextBuku First);

#endif
