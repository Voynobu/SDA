#ifndef Peminjaman_H
#define Peminjaman_H
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "Kota.h"

address findDosen(address p);
//Digunakan untuk mencari peminjam dengan status dosen dilist peminjam

address findMahasiswa(address p);
//Digunakan untuk mencari peminjam dengan status mahasiswa dilist peminjam

address findUmum(address p);
//Digunakan untuk mencari peminjam dengan status umum dilist peminjam

void StartPeminjaman(ListBuku *k);
//1. Cek apakah stok peminjaman kurang dari stok buku (jika kurang jalankan)
//2. Mencari dalam linked list peminjam mulai dari Dokter - Mahasiswa - Umum
//3. Mengambil informasi buku dari list buku lalu copy ke pinjaman dari peminjam yang sudah ditentukan dari proses mencari
//4. Menambahkan stok peminjaman setelah proses diatas dilakukan.

void SelesaikanPeminjaman(ListBuku *k);

void CancelAntrian(ListBuku *pT);
#endif
