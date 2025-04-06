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

void CreateNodeKota(Nextkota *k);
void IsiNodeKota(Nextkota *k, char *Kota);
void InsertKota_Awal(Nextkota *First, Nextkota k);
void InsertKota_Akhir(Nextkota *First, Nextkota k);
void DeleteKota_Awal(Nextkota *First);
void DeleteKota_Akhir(Nextkota *First);
void tambah_nama(Nextkota *k, char *nama);
void tambah_namaByUser(Nextkota *k);
void delete_nama(Nextkota *k, char *nama);
void tampilkota(Nextkota *k);
void NukeKota(Nextkota *k);
void TampilkanDaftarKota(Nextkota First);
void GetKotabyIndex(Nextkota First, int index, Nextkota *result);
void TampilkanSemuaKotaDanPenduduk(Nextkota First);

#endif
