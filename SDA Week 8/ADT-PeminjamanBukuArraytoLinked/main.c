#include <stdio.h>
#include <stdlib.h>
#include "Peminjaman.h"

void tampilMenu() {
	printf("\n=== SISTEM PEMINJAMAN BUKU ===\n");
	printf("1. Tampilkan Informasi Buku\n");
	printf("2. Tambah Peminjam Baru\n");
	printf("3. Mulai Peminjaman\n");
	printf("4. Selesaikan Peminjaman\n");
	printf("5. Batalkan Antrian\n");
	printf("6. Hapus Semua Data\n");
	printf("0. Keluar\n");
	printf("Pilihan: ");
}

void tampilInfoBuku(ListBuku *listbuku, int jumlahBuku) {
	printf("\n=== INFORMASI BUKU ===\n");
	printf("Jumlah Elemen Array: %d\n", jumlahBuku);
	
	// Mengubah for loop menjadi while loop
	int i = 0;
	while(i < jumlahBuku) {
		printf("\nBuku ke-%d:\n", i+1);
		tampilkota(&listbuku[i]);
		i++;
	}
}

void inisialisasiTemplateData(ListBuku *listbuku) {
	printf("\n=== MENGINISIALISASI DATA TEMPLATE ===\n");
	// Template data buku
	NamaKota(&listbuku[0], "Buku1", 1);
	NamaKota(&listbuku[1], "Buku2", 1);
	
	// Template data peminjam
	tambah_nama(&listbuku[0], "Anggota1", "", Mahasiswa);
	tambah_nama(&listbuku[0], "Dosen1", "", Dosen);
	tambah_nama(&listbuku[0], "Umum1", "", Umum);
	tambah_nama(&listbuku[1], "Umum1", "", Umum);
	
	printf("Data template berhasil diinisialisasi!\n");
	printf("Tekan Enter untuk melanjutkan...");
	getchar();
}

void tambahPeminjamBaru(ListBuku *listbuku) {
	int pilihBuku, statusPeminjam;
	char nama[50];
	
	printf("\n=== TAMBAH PEMINJAM BARU ===\n");
	printf("Pilih buku (1-2): ");
	scanf("%d", &pilihBuku);
	getchar(); // Membersihkan buffer
	
	if(pilihBuku < 1 || pilihBuku > 2) {
		printf("Nomor buku tidak valid!\n");
		return;
	}
	
	printf("Masukkan nama peminjam: ");
	fgets(nama, 50, stdin);
	nama[strcspn(nama, "\n")] = 0; // Menghapus newline
	
	printf("\nPilih status peminjam:\n");
	printf("1. Mahasiswa\n");
	printf("2. Dosen\n");
	printf("3. Umum\n");
	printf("Pilihan: ");
	scanf("%d", &statusPeminjam);
	
	switch(statusPeminjam) {
		case 1:
			tambah_nama(&listbuku[pilihBuku-1], nama, "", Mahasiswa);
			break;
		case 2:
			tambah_nama(&listbuku[pilihBuku-1], nama, "", Dosen);
			break;
		case 3:
			tambah_nama(&listbuku[pilihBuku-1], nama, "", Umum);
			break;
		default:
			printf("Status peminjam tidak valid!\n");
			return;
	}
	
	printf("Peminjam baru berhasil ditambahkan!\n");
}

int main(int argc, char *argv[]) {
	ListBuku listbuku[2];
	int pilihan;
	const int JUMLAH_BUKU = 2;
	
	// Inisialisasi template data di awal program
	inisialisasiTemplateData(listbuku);
	system("cls");
	
	do {
		tampilMenu();
		scanf("%d", &pilihan);
		getchar(); // Membersihkan buffer
		
		switch(pilihan) {
			case 1:
				tampilInfoBuku(listbuku, JUMLAH_BUKU);
				break;
				
			case 2:
				tambahPeminjamBaru(listbuku);
				break;
				
			case 3:
				printf("\n=== MULAI PEMINJAMAN ===\n");
				printf("Pilih buku (1-2): ");
				int pilihBukuPinjam;
				scanf("%d", &pilihBukuPinjam);
				getchar(); // Membersihkan buffer
				
				if(pilihBukuPinjam < 1 || pilihBukuPinjam > 2) {
					printf("Nomor buku tidak valid!\n");
				} else {
					StartPeminjaman(&listbuku[pilihBukuPinjam-1]);
					printf("Peminjaman dimulai!\n");
				}
				break;
				
			case 4:
				printf("\n=== SELESAIKAN PEMINJAMAN ===\n");
				printf("Pilih buku (1-2): ");
				int pilihBukuSelesai;
				scanf("%d", &pilihBukuSelesai);
				getchar(); // Membersihkan buffer
				
				if(pilihBukuSelesai < 1 || pilihBukuSelesai > 2) {
					printf("Nomor buku tidak valid!\n");
				} else {
					SelesaikanPeminjaman(&listbuku[pilihBukuSelesai-1]);
					printf("Peminjaman selesai!\n");
				}
				break;
				
			case 5:
				printf("\n=== BATALKAN ANTRIAN ===\n");
				printf("Pilih buku (1-2): ");
				int pilihBukuBatal;
				scanf("%d", &pilihBukuBatal);
				getchar(); // Membersihkan buffer
				
				if(pilihBukuBatal < 1 || pilihBukuBatal > 2) {
					printf("Nomor buku tidak valid!\n");
				} else {
					CancelAntrian(&listbuku[pilihBukuBatal-1]);
				}
				break;
				
			case 6:
				printf("\n=== HAPUS SEMUA DATA ===\n");
				// Mengubah for loop menjadi while loop
				int i = 0;
				while(i < JUMLAH_BUKU) {
					NukeKota(&listbuku[i]);
					i++;
				}
				printf("Semua data berhasil dihapus!\n");
				break;
				
			case 0:
				printf("\nTerima kasih telah menggunakan sistem ini!\n");
				break;
				
			default:
				printf("\nPilihan tidak valid!\n");
		}
		
		if(pilihan != 0) {
			printf("\nTekan Enter untuk melanjutkan...");
			getchar();
			system("cls");
		}
		
	} while(pilihan != 0);
	
	return 0;
}
