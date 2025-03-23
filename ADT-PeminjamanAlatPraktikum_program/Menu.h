#ifndef Menu_H
#define Menu_H
#include <stdio.h>
#include <stdlib.h>
#include "Praktikum.h"

void menuProsesPeminjaman(address *queuePeminjaman, address *queueKualitas, address *alatList, address *alatStack);
void ProsesPeminjaman(address *queueMahasiswa, address *alatList, address *alatStack, address *queuePeminjaman,  address *queueKualitas);
void cekStatusAlat(address alatList);

#endif
