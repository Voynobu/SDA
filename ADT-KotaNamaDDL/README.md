Tujuan program: Membuat sebuah program yang bertujuan untuk menyambungkan 2 linked list dimana linked list pertama (Listkota)
merupakan sebuah typedef struct dengan 3 isi yaitu: 1. address pointer (pointer menuju linkedlist yang berbeda), 2. Nextkota next
(pointer untuk Listkota lainnya(linkedlist utama)), dan 3. char *Kota (untuk string). Lalu linked list yang berbeda ini akan menyimpan
string - string nama sebagai penduduk dari kota tersebut.

Lesson learned: Selalu check kita kita melakukan dealokasi didalam sebuah modul dan if - else (hal ini jika tidak diperhatikan, khusus
nya ketika melakukan dealokasi akan beresiko untuk terjadinya memoryleak dan juga undifined loop).

Permasalahan yang dihadapi: Kebingungan ketika terjadi undifined loop saat menghapus kota.
Penyelesaian masalah : Mengecek modul delete_akhir, lalu ditemukan bahwa pointer prev->next belum di set ke NULL(dimana ini akan conflict
dengan loop di modul lainnya).

Referensi: (tidak ada)
