#ifndef Kota_H
#define Kota_H
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "linked.h"

typedef struct {
	address pointer;
	char *Kota;
}ListKota;

void NamaKota(ListKota *k, char *Kota);
void tambah_nama(ListKota *k, char *nama);
void tambah_namaByUser(ListKota *k);
void delete_nama(ListKota *k, char *nama);
void tampilkota(ListKota *k);
void NukeKota(ListKota *k);

#endif
