#include <stdio.h>
#include <stdlib.h>
#include "Peminjaman.h"
#include "Kota.h"
#include "linked.h"

void displayMenu() {
	printf("\n=== MENU PERPUSTAKAAN ===\n");
	printf("1. Tambah Buku\n");
	printf("2. Pilih Buku Aktif\n");
	printf("3. Kelola Peminjam Buku Aktif\n");
	printf("4. Proses Peminjaman Buku Aktif\n");
	printf("5. Proses Pengembalian Buku Aktif\n");
	printf("6. Batalkan Antrian Buku Aktif\n");
	printf("7. Tampilkan Semua Buku & Peminjam\n");
	printf("0. Keluar\n");
	printf("Pilih menu: ");
}

void menuKelolaPeminjam(NextBuku bukuAktif) {
	int choice;
	char nama[100];
	if (bukuAktif == NULL) {
		printf("Belum ada buku aktif!\n");
		return;
	}
	do {
		printf("\n=== KELOLA PEMINJAM BUKU: %s ===\n", bukuAktif->Buku);
		printf("1. Tambah Peminjam\n");
		printf("2. Hapus Peminjam\n");
		printf("3. Tampilkan Daftar Peminjam\n");
		printf("0. Kembali\n");
		printf("Pilih menu: ");
		scanf("%d", &choice);
		while (getchar() != '\n'); // Bersihkan buffer
		switch(choice) {
			case 1:
				tambah_namaByUser(&bukuAktif);
				break;
			case 2:
				printf("Masukkan nama peminjam yang akan dihapus: ");
				fgets(nama, sizeof(nama), stdin);
				nama[strcspn(nama, "\n")] = '\0';
				delete_nama(&bukuAktif, nama);
				break;
			case 3:
				tampilkota(&bukuAktif);
				break;
		}
	} while(choice != 0);
}

int main(int argc, char *argv[]) {
	NextBuku listBuku = NULL;
	NextBuku bukuAktif = NULL;
	int choice;
	char nama[100];
	int stock;
	int idx;
	do {
		displayMenu();
		scanf("%d", &choice);
		while (getchar() != '\n'); // Bersihkan buffer
		switch(choice) {
			case 1:
				printf("Masukkan nama buku: ");
				fgets(nama, sizeof(nama), stdin);
				nama[strcspn(nama, "\n")] = '\0';
				printf("Masukkan stok: ");
				scanf("%d", &stock);
				while (getchar() != '\n');
				NextBuku newBuku;
				CreateNodeBuku(&newBuku);
				IsiNodeBuku(&newBuku, nama, stock);
				InsertBuku_Akhir(&listBuku, newBuku);
				printf("Buku berhasil ditambahkan!\n");
				break;
			case 2:
				printf("Daftar Buku:\n");
				TampilkanDaftarKota(listBuku);
				printf("\nPilih nomor buku: ");
				scanf("%d", &idx);
				while (getchar() != '\n');
				GetKotabyIndex(listBuku, idx, &bukuAktif);
				if (bukuAktif != NULL) {
					printf("Buku aktif: %s\n", bukuAktif->Buku);
				}
				break;
			case 3:
				menuKelolaPeminjam(bukuAktif);
				break;
			case 4:
				if (bukuAktif == NULL) {
					printf("Belum ada buku aktif!\n");
				} else {
					StartPeminjaman(bukuAktif);
				}
				break;
			case 5:
				if (bukuAktif == NULL) {
					printf("Belum ada buku aktif!\n");
				} else {
					SelesaikanPeminjaman(bukuAktif);
				}
				break;
			case 6:
				if (bukuAktif == NULL) {
					printf("Belum ada buku aktif!\n");
				} else {
					CancelAntrian(bukuAktif);
				}
				break;
			case 7:
				TampilkanSemuaKotaDanPenduduk(listBuku);
				break;
			case 0:
				printf("Terima kasih telah menggunakan sistem perpustakaan!\n");
				break;
			default:
				printf("Pilihan tidak valid!\n");
		}
	} while(choice != 0);
	return 0;
}
