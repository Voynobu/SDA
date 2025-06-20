#include <stdio.h>
#include "nbtrees.h"

// Inisialisasi tree (dilakukan secara implisit dalam Create_tree)
void Create_tree(Isi_Tree X, int Jml_Node) {
    // Inisialisasi semua node
    int i  = 1;
    
    while (i <= jml_maks) {
        X[i].info = '\0';   // Menandai node kosong
        X[i].ps_fs = nil;
        X[i].ps_nb = nil;
        X[i].ps_pr = nil;
        i++;
    }

    // Input data untuk setiap node
    printf("Masukkan data untuk %d node:\n", Jml_Node);
    for (i = 1; i <= Jml_Node; i++) {
        printf("Node %d: ", i);
        scanf(" %c", &X[i].info);
    }
}

bool IsEmpty(Isi_Tree P) {
    // Tree kosong jika root (indeks 1) tidak terisi
    return (P[1].info == '\0');
}

// Fungsi rekursif untuk PreOrder
void PreOrderRekursif(Isi_Tree P, address node) {
    if (node == nil) return;
    printf("%c ", P[node].info);  // Cetak node saat ini
    PreOrderRekursif(P, P[node].ps_fs); // Traverse first child
    PreOrderRekursif(P, P[node].ps_nb); // Traverse next sibling
}

void PreOrder(Isi_Tree P) {
    if (IsEmpty(P)) {
        printf("Tree kosong!\n");
        return;
    }
    printf("PreOrder: ");
    PreOrderRekursif(P, 1); // Mulai dari root (indeks 1)
    printf("\n");
}

// Fungsi rekursif untuk InOrder
void InOrderRekursif(Isi_Tree P, address node) {
    if (node == nil) return;
    InOrderRekursif(P, P[node].ps_fs); // Kunjungi anak pertama
    printf("%c ", P[node].info);        // Cetak node saat ini
    
    // Kunjungi saudara berikutnya jika ada
    address sibling = P[node].ps_fs;
    if (sibling != nil) {
        sibling = P[sibling].ps_nb;
        while (sibling != nil) {
            InOrderRekursif(P, sibling);
            sibling = P[sibling].ps_nb;
        }
    }
}

void InOrder(Isi_Tree P) {
    if (IsEmpty(P)) {
        printf("Tree kosong!\n");
        return;
    }
    printf("InOrder: ");
    InOrderRekursif(P, 1); // Mulai dari root
    printf("\n");
}

// Fungsi rekursif untuk PostOrder
void PostOrderRekursif(Isi_Tree P, address node) {
    if (node == nil) return;
    PostOrderRekursif(P, P[node].ps_fs); // Kunjungi anak pertama
    
    // Kunjungi saudara berikutnya jika ada
    address sibling = P[node].ps_fs;
    if (sibling != nil) {
        sibling = P[sibling].ps_nb;
        while (sibling != nil) {
            PostOrderRekursif(P, sibling);
            sibling = P[sibling].ps_nb;
        }
    }
    
    printf("%c ", P[node].info); // Cetak node saat ini
}

void PostOrder(Isi_Tree P) {
    if (IsEmpty(P)) {
        printf("Tree kosong!\n");
        return;
    }
    printf("PostOrder: ");
    PostOrderRekursif(P, 1); // Mulai dari root
    printf("\n");
}

// Fungsi untuk Level Order Traversal
void Level_order(Isi_Tree X, int Maks_node) {
    if (IsEmpty(X)) {
        printf("Tree kosong!\n");
        return;
    }
    
    address queue[jml_maks];
    int front = 0, rear = 0;
    
    // Masukkan root ke queue
    queue[rear++] = 1;
    
    printf("LevelOrder: ");
    while (front < rear) {
        address current = queue[front++];
        printf("%c ", X[current].info);
        
        // Masukkan semua anak node saat ini ke queue
        address child = X[current].ps_fs;
        while (child != nil) {
            queue[rear++] = child;
            child = X[child].ps_nb;
        }
    }
    printf("\n");
}

void PrintTree(Isi_Tree P) {
    if (IsEmpty(P)) {
        printf("Tree kosong!\n");
        return;
    }
    
    printf("Struktur Tree:\n");
    address stack[jml_maks];
    int depth[jml_maks];
    int top = 0;
    
    // Mulai dari root (indeks 1) dengan kedalaman 0
    stack[top] = 1;
    depth[top] = 0;
    
    while (top >= 0) {
        address current = stack[top];
        int current_depth = depth[top];
        top--;
        int i = 0;
        // Cetak indentasi sesuai kedalaman
        while ( i < current_depth) {
            printf("  ");
            i++;
        }
        printf("|-- %c\n", P[current].info);
        
        // Masukkan saudara dan anak ke stack (dalam urutan terbalik)
        address sibling = P[current].ps_nb;
        while (sibling != nil) {
            top++;
            stack[top] = sibling;
            depth[top] = current_depth; // Saudara selevel
            sibling = P[sibling].ps_nb;
        }
        
        address child = P[current].ps_fs;
        if (child != nil) {
            top++;
            stack[top] = child;
            depth[top] = current_depth + 1; // Anak lebih dalam
        }
    }
}

bool Search(Isi_Tree P, infotype X) {
	int i = 1;
    while (i <= jml_maks) {
        if (P[i].info == X) {
            return true;
        }
        i++;
    }
    return false;
}

int nbElmt(Isi_Tree P) {
    int count = 0;
    int i = 1;
    while(i <= jml_maks) {
        if (P[i].info != '\0') {
            count++;
        }
        i++;
    }
    return count;
}

int nbDaun(Isi_Tree P) {
    int count = 0;
    int i = 1;
    while (i <= jml_maks) {
        // Node adalah daun jika tidak memiliki anak
        if (P[i].info != '\0' && P[i].ps_fs == nil) {
            count++;
        }
        i++;
    }
    return count;
}

int Level(Isi_Tree P, infotype X) {
    int level = -1;
    int i = 1;
    while (i <= jml_maks) {
        if (P[i].info == X) {
            level = 0;
            address parent = P[i].ps_pr;
            while (parent != nil) {
                level++;
                parent = P[parent].ps_pr;
            }
            break;
        }
        i++;
    }
    return level;
}

int Depth(Isi_Tree P) {
    int max_level = -1;
    int i = 1;
    while (i <= jml_maks) {
        if (P[i].info != '\0') {
            int node_level = Level(P, P[i].info);
            if (node_level > max_level) {
                max_level = node_level;
            }
        }
        i++;
    }
    return max_level;
}

int Max(infotype Data1, infotype Data2) {
    return (Data1 > Data2) ? Data1 : Data2;
}
