#include <stdio.h>
#include <stdlib.h>
#include "Praktikum.h"
#include "Queue.h"
#include "Stack.h"
#include "linked.h"
#include "Menu.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int pilihan;
	address MList = NULL;
	address AList = NULL;
	address PList = NULL;
	address StackAlat = NULL;
	address KList = NULL;
	printf("Program dimulai\n");
	address MNew = NULL;
  	printf("Menambahkan Alat1...\n");  // Debugging
    Create_Alat(&AList, MNew, "Alat1", "Excellent");
    printf("Alat1 berhasil ditambahkan.\n");  // Debugging
	Tampil_List(AList);

    printf("Menambahkan Alat2...\n");  // Debugging
    Create_Alat(&AList, MNew, "Alat2", "Excellent");
    printf("Alat2 berhasil ditambahkan.\n");  // Debugging
	Tampil_List(AList);

    printf("Menambahkan Alat3...\n");  // Debugging
    Create_Alat(&AList, MNew, "Alat3", "Good");
    printf("Alat3 berhasil ditambahkan.\n");  // Debugging
	Tampil_List(AList);

    printf("Menambahkan Alat4...\n");  // Debugging
    Create_Alat(&AList, MNew, "Alat4", "Good");
    printf("Alat4 berhasil ditambahkan.\n");
	printf("Alat berhasilkan ditambahkan\n");
	Tampil_List(AList);
	
	MNew = NULL;
	char nama[100];
	int loop = 1;
		while (loop){
			int Opsi;
			printf("==============================================\n");
			printf("||                                          ||\n");
			printf("|| +--------------------------------------+ ||\n");
			printf("||  S I M U L A S I    P E M I N J A M A N  ||\n");
			printf("|| +--------------------------------------+ ||\n");
			printf("||                                          ||\n");
			printf("==============================================\n\n\n");
			
			printf("+--------------------------------------+\n");
			printf("|                                      |\n"); 
			printf("|   1. [>>] Memulai Queue              |\n"); 
			printf("|   2. [>>] Memproses Peminjaman       |\n"); 
			printf("|   3. [>>] Cek Status Alat            |\n"); 
			printf("|   4. [X]  Keluar                     |\n"); 
			printf("|                                      |\n"); 
			printf("+--------------------------------------+\n\n\n");
			printf(">> Masukkan pilihan anda (1-4) =  ");			
			scanf("%d", &Opsi);
			getchar();
		
			switch(Opsi){
				case 1:
	                printf("\n>> Masukkan nama orang yang akan masuk ke queue: ");
	                fgets(nama, sizeof(nama), stdin);
	                nama[strcspn(nama, "\n")] = '\0';
	
	                Create_Mahasiswa(&MList, MNew, nama);
	
	                if (MList == NULL) {
	                    printf("Gagal menambahkan mahasiswa ke queue.\n");
	                } else {
	                    printf("Mahasiswa %s telah ditambahkan ke dalam queue.\n", nama);
	                }
					Tampil_List(MList);
					break;
				case 2:
	                printf("\n+---------------------------------------------+\n");
	                printf("|                                             |\n");
	                printf("|   Pilih metode peminjaman alat:            |\n");
	                printf("|                                             |\n");
	                printf("|   1. Pinjamkan alat menurut Kualitas       |\n");
	                printf("|   2. Pinjamkan alat menurut terakhir kali  |\n");
	                printf("|      digunakan                             |\n");
	                printf("|                                             |\n");
	                printf("+---------------------------------------------+\n");
	
	                printf("\n>> Masukkan pilihan Anda (1-2): ");
	                scanf("%d", &pilihan);
	
	                infotype X;
	                char *namaMahasiswa;
	                char *namaAlat;
	                char *kualitas;
	
	                StartQueue(&MList, &X, &namaMahasiswa, &kualitas);
	
	                if (pilihan == 1) {
	                    Search_QualityAlat(&AList, X, &namaAlat, &kualitas);
	                } else if (pilihan == 2) {
	                    RecentUsed(&StackAlat, &X, &namaAlat, &kualitas);
	                } else {
	                    printf("Pilihan tidak valid!\n");
	                    break;
	                }
	
	                AddToBorrowProcess(&PList, &KList, NULL, namaMahasiswa, namaAlat, kualitas);
	                printf("Peminjaman berhasil diproses untuk %s dengan alat %s.\n", namaMahasiswa, namaAlat);
				    // Tampilkan menu proses peminjaman
				    MenuProsesPeminjaman(&PList, &KList, &AList, &StackAlat);
					break;
				case 3:
					cekStatusAlat(AList);
					break;
				case 4:
					printf("Keluar dari program.\n");
                	loop = 0;
                	break;
                default:
                	printf("Pilihan tidak valid!\n");
                	break;
				}
			}
			
	Destroy_All(&MList);
	Destroy_All(&AList);
	Destroy_All(&PList);
	Destroy_All(&StackAlat);
	Destroy_All(&KList);		
	return 0;
}
