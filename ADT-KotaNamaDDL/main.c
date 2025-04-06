#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "linked.h"
#include "DoubleLink.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void display_menu() {
    printf("\n=== MENU MANAJEMEN KOTA 2.0 ===\n");
    printf("1. Tampilkan semua kota dan penduduk\n");
    printf("2. Manage Kota\n");
    printf("3. Tambah Kota\n");
    printf("4. Hapus Kota\n");
    printf("5. Keluar\n");
    printf("Pilihan: ");
}

void display_menu_kota(Nextkota kota) {
    printf("\n=== MENU KOTA: %s ===\n", kota->Kota);
    printf("1. Tambah penduduk\n");
    printf("2. Hapus penduduk terakhir\n");
    printf("3. Tampilkan daftar penduduk\n");
    printf("4. Kembali ke menu utama\n");
    printf("Pilihan: ");
}

void pilihkota(Nextkota First){
	int index;
	Nextkota kotaTerpilih;
	
	TampilkanDaftarKota(First);
	printf("\n=== PILIH KOTA YANG AKAN DI MANAGE\n");
	printf("Pilihan: ");
	scanf("%d", &index);
	getchar();
	
	GetKotabyIndex(First, index, &kotaTerpilih);
	
	if (kotaTerpilih != NULL) {
        int pilihan;
        do {
            display_menu_kota(kotaTerpilih);
            scanf("%d", &pilihan);
            getchar(); 
            
            switch(pilihan) {
                case 1:
                    tambah_namaByUser(&kotaTerpilih);
                    break;
                case 2:
                    delete_nama(&kotaTerpilih, NULL);
                    printf("Penduduk terakhir telah dihapus\n");
                    break;
                case 3:
                    tampilkota(&kotaTerpilih);
                    break;
                case 4:
                    printf("Kembali ke menu utama...\n");
                    break;
                default:
                    printf("Pilihan tidak valid!\n");
            }
        } while (pilihan != 4);
    }
}

int main(int argc, char *argv[]) {
	Nextkota Listkota = NULL;
	Nextkota kotaBaru = NULL;
	char namaKota[100];
	int pilihan;
	
	do{
		display_menu();
		scanf("%d", &pilihan);
		getchar();
		switch(pilihan){
			case 1:
				TampilkanSemuaKotaDanPenduduk(Listkota);
				break;
			case 2:
				pilihkota(Listkota);
				break;	
			case 3:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0';
                
                CreateNodeKota(&kotaBaru);
                IsiNodeKota(&kotaBaru, namaKota);
                InsertKota_Akhir(&Listkota, kotaBaru);
                printf("Kota %s ditambahkan!\n", namaKota);
                break;
            case 4:
            	if (Listkota == NULL) {
                    printf("Belum ada kota!\n");
                    break;
                }
                
                int metode;
                printf("Hapus dari:\n1. Awal\n2. Akhir\nPilihan: ");
                scanf("%d", &metode);
                
                if (metode == 1) DeleteKota_Awal(&Listkota);
                else if (metode == 2) DeleteKota_Akhir(&Listkota);
                else printf("Input salah!\n");
                break;
            case 5:
                printf("Program selesai.\n");
                break;
    
            default:
                printf("Pilihan tidak valid!\n");
		}
	} while (pilihan != 5);

    NukeKota(&Listkota);
	return 0;
}
