#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "nbtrees.h"

void display_menu() {
    printf("\nADT Non Binary Tree Menu:\n");
    printf("1. Traversal PreOrder\n");
    printf("2. Traversal InOrder\n");
    printf("3. Traversal PostOrder\n");
    printf("4. Traversal Level Order\n");
    printf("5. Print Tree\n");
    printf("6. Search node Tree\n");
    printf("7. Jumlah Daun/Leaf\n");
    printf("8. Mencari Level node Tree\n");
    printf("9. Kedalaman Tree\n");
    printf("10. Membandingkan 2 node Tree\n");
    printf("11. Exit\n");
    printf("Pilih Menu: ");
}

void initialize_tree(Isi_Tree *tree) {
	int i = 1;	
    // Clear all nodes
    while(i <= jml_maks) {
        (*tree)[i].info = '\0';
        (*tree)[i].ps_fs = nil;
        (*tree)[i].ps_nb = nil;
        (*tree)[i].ps_pr = nil;
        i++;
    }

    // Set node values
    (*tree)[1].info = 'A';
    (*tree)[2].info = 'B';
    (*tree)[3].info = 'C';
    (*tree)[4].info = 'D';
    (*tree)[5].info = 'E';
    (*tree)[6].info = 'F';
    (*tree)[7].info = 'G';
    (*tree)[8].info = 'H';

    // Set relationships
    // Level 1 (Root)
    (*tree)[1].ps_fs = 2;  // A -> B
    
    // Level 2
    (*tree)[2].ps_nb = 3;  // B -> C
    (*tree)[3].ps_nb = 4;  // C -> D
    (*tree)[2].ps_pr = 1;
    (*tree)[3].ps_pr = 1;
    (*tree)[4].ps_pr = 1;
    
    // Level 3 (Children of B)
    (*tree)[2].ps_fs = 5;  // B -> E
    (*tree)[5].ps_nb = 6;  // E -> F
    (*tree)[5].ps_pr = 2;
    (*tree)[6].ps_pr = 2;
    
    // Level 3 (Children of D)
    (*tree)[4].ps_fs = 7;  // D -> G
    (*tree)[7].ps_nb = 8;  // G -> H
    (*tree)[7].ps_pr = 4;
    (*tree)[8].ps_pr = 4;
}

void print_detailed_tree(Isi_Tree tree) {
	int i = 1;
    printf("\nSeluruh Node pada Non Binary Tree:\n");
    while (i <= 8) {  // Hanya print node yang terisi
        printf("______________________\n");
        printf("Index ke-%d\n", i);
        printf("info array ke %d    : %c\n", i, tree[i].info);
        printf("first son array ke %d    : %d\n", i, tree[i].ps_fs);
        printf("next brother array ke %d : %d\n", i, tree[i].ps_nb);
        printf("parent array ke %d    : %d\n", i, tree[i].ps_pr);
        i++;
    }
    printf("______________________\n");
    printf("Klik apapun untuk melanjutkan!\n");
    getchar(); getchar();  // Wait for user input
}

int main() {
    Isi_Tree myTree;
    initialize_tree(&myTree);
    int choice;
    char search_char;
    int node1, node2;

    do {
        display_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nPreOrder Traversal:\n");
                PreOrder(myTree);
                break;
            case 2:
                printf("\nInOrder Traversal:\n");
                InOrder(myTree);
                break;
            case 3:
                printf("\nPostOrder Traversal:\n");
                PostOrder(myTree);
                break;
            case 4:
                printf("\nLevelOrder Traversal:\n");
                Level_order(myTree, 8);
                break;
            case 5:
                print_detailed_tree(myTree);
                break;
            case 6:
                printf("\nMasukkan karakter yang dicari: ");
                scanf(" %c", &search_char);
                if (Search(myTree, search_char)) {
                    printf("Node '%c' ditemukan dalam tree.\n", search_char);
                } else {
                    printf("Node '%c' tidak ditemukan dalam tree.\n", search_char);
                }
                break;
            case 7:
                printf("\nJumlah Daun: %d\n", nbDaun(myTree));
                break;
            case 8:
                printf("\nMasukkan karakter node: ");
                scanf(" %c", &search_char);
                printf("Level node '%c': %d\n", search_char, Level(myTree, search_char));
                break;
            case 9:
                printf("\nKedalaman Tree: %d\n", Depth(myTree));
                break;
            case 10:
                printf("\nMasukkan indeks node pertama: ");
                scanf("%d", &node1);
                printf("Masukkan indeks node kedua: ");
                scanf("%d", &node2);
                // Simple comparison - in real case you might want to compare subtrees
                if (myTree[node1].info == myTree[node2].info) {
                    printf("Node %d dan %d memiliki nilai yang sama.\n", node1, node2);
                } else {
                    printf("Node %d dan %d memiliki nilai berbeda.\n", node1, node2);
                }
                break;
            case 11:
                printf("\nKeluar dari program.\n");
                break;
            default:
                printf("\nPilihan tidak valid!\n");
        }
    } while (choice != 11);

    return 0;
}
