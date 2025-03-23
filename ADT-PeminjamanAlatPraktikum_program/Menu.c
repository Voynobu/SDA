#ifndef Menu_H
#define Menu_H
#include <stdio.h>
#include <stdlib.h>
#include "Praktikum.h"



void MenuProsesPeminjaman(address *queuePeminjaman, address *queueKualitas, address *alatList, address *alatStack) {
    int loop = 1;
    while (loop) {
        printf("\n+---------------------------------------------+\n");
        printf("|                                               |\n");
        printf("|   Proses Peminjaman:                          |\n");
        printf("|                                               |\n");
        printf("|   1. Tampilkan List Peminjaman                |\n");
        printf("|   2. Selesaikan Peminjaman                    |\n");
        printf("|   3. Keluar                                   |\n");
        printf("|                                               |\n");
        printf("+-----------------------------------------------+\n");

        int pilihan;
        printf("\n>> Masukkan pilihan Anda (1-3): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                // Tampilkan list peminjaman
                printf("\nDaftar Peminjaman:\n");
                ShowBorrowProcess(*queuePeminjaman);
                break;
            case 2:
                // Selesaikan peminjaman
                EndBorrowProcess(*queuePeminjaman, *queueKualitas, alatList, alatStack);
                break;
            case 3:
                // Keluar dari menu proses peminjaman
                printf("Keluar dari proses peminjaman.\n");
                loop = 0;
                break;
            default:
                printf("Pilihan tidak valid!\n");
                break;
        }
    }
}


void cekStatusAlat(address alatList) {
    printf("\nStatus Alat Tersedia:\n");
    Display_Stock(alatList);
}

#endif
