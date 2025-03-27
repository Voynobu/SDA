#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "linked.h"
#include "Kota.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void display_menu() {
    printf("\n=== MENU MANAJEMEN KOTA ===\n");
    printf("1. Tampilkan semua kota dan penduduk\n");
    printf("2. Tambah penduduk ke kota\n");
    printf("3. Hapus penduduk terakhir dari kota\n");
    printf("4. Keluar\n");
    printf("Pilihan: ");
}

int main(int argc, char *argv[]) {
	ListKota listkota[5];
	int city_count = 5;
	int i = 0;

	NamaKota(&listkota[0], "Jakarta");
	tambah_nama(&listkota[0], "Zaidan");
	tambah_nama(&listkota[0], "Naufal");
	tambah_nama(&listkota[0], "Johan");

	
	NamaKota(&listkota[1], "Bandung");
	tambah_nama(&listkota[1], "Radhit");
	tambah_nama(&listkota[1], "Rangga");
	tambah_nama(&listkota[1], "Praditama");

	
	NamaKota(&listkota[2], "Garut");
	tambah_nama(&listkota[2], "Amalia");
	tambah_nama(&listkota[2], "Aulia");
	tambah_nama(&listkota[2], "Maul");

	
	NamaKota(&listkota[3], "Purwakarta");
	tambah_nama(&listkota[3], "Dimas");
	tambah_nama(&listkota[3], "Wali");
	tambah_nama(&listkota[3], "Quolan");

	
	NamaKota(&listkota[4], "Bogor");
	tambah_nama(&listkota[4], "Gus");
	tambah_nama(&listkota[4], "Javar");
	tambah_nama(&listkota[4], "Akira");

	
 int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        getchar(); // Clear newline
        
        switch(choice) {
            case 1: { // Show all
                printf("\nDaftar Kota dan Penduduk:\n");
                i = 0;
                while(i < city_count) {
                    tampilkota(&listkota[i]);
                    i++;
                }
                break;
            }
                
            case 2: { // Add resident
                printf("\nDaftar Kota:\n");
                i = 0;
                while(i < city_count) {
                    printf("%d. %s\n", i+1, listkota[i].Kota);
                    i++;
                }
                
                int city_choice;
                printf("Pilih kota (1-%d): ", city_count);
                scanf("%d", &city_choice);
                getchar();
                
                if(city_choice < 1 || city_choice > city_count) {
                    printf("Pilihan tidak valid!\n");
                    break;
                }
                
                char nama[100];
                printf("Masukkan nama penduduk: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = '\0';
                
                if(nama[0] != '\0') {
                    nama[0] = toupper(nama[0]);
                    tambah_nama(&listkota[city_choice-1], nama);
                    printf("Nama '%s' berhasil ditambahkan ke kota %s\n", nama, listkota[city_choice-1].Kota);
                }
                break;
            }
                
            case 3: { // Delete last resident
                printf("\nDaftar Kota:\n");
                i = 0;
                while(i < city_count) {
                    printf("%d. %s\n", i+1, listkota[i].Kota);
                    i++;
                }
                
                int city_choice;
                printf("Pilih kota (1-%d): ", city_count);
                scanf("%d", &city_choice);
                getchar();
                
                if(city_choice < 1 || city_choice > city_count) {
                    printf("Pilihan tidak valid!\n");
                    break;
                }
                
                if(listkota[city_choice-1].pointer == NULL) {
                    printf("Tidak ada penduduk di kota %s\n", listkota[city_choice-1].Kota);
                } else {
                    delete_nama(&listkota[city_choice-1], NULL);
                    printf("Penduduk terakhir berhasil dihapus dari kota %s\n", listkota[city_choice-1].Kota);
                }
                break;
            }
                
            case 4:
                printf("Keluar dari program...\n");
                break;
                
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while(choice != 4);

    // Clean up using while
    i = 0;
    while(i < city_count) {
        NukeKota(&listkota[i]);
        i++;
    }
	
	return 0;
}
