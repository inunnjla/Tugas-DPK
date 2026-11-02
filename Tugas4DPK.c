#include <stdio.h>
 
#define N 4  // membuat konstanta N bernilai 4. Setiap N di program diganti 4 saat kompilasi. Kalau ukuran matriks mau diubah, cukup ubah angka ini (dan isi array-nya).
 
int main(void) {
    /* matriks A (4x4) */
    int a[N][N] = {  // array 2 dimensi 4×4 untuk matriks A dan nilainya langsung diisi.
        {2, 1, 3, 1},
        {1, 4, 2, 3},
        {3, 2, 1, 4},
        {4, 3, 2, 1}
    };
 
    /* vektor x (4x1) */
    int x[N] = {1, 2, 3, 4};  // array 1 dimensi untuk vektor x, diisi 1, 2, 3, 4.
 
    /* hasil A * x */
    int hasil[N];  // array untuk menyimpan hasil A × x. Tidak diisi di awal karena nilainya dihitung kemudian. Hasil disimpan terpisah supaya x yang lama tidak tertimpa sebelum semua baris selesai dihitung.
 
    /* hasil[i] = a[i][0]*x[0] + a[i][1]*x[1] + a[i][2]*x[2] + a[i][3]*x[3] */
    for (int i = 0; i < N; i++) {  // i menunjuk baris matriks (0 sampai 3), dan j menunjuk kolom (0 sampai 3).
        hasil[i] = 0;  // mengosongkan penampung sebelum dijumlahkan.
        for (int j = 0; j < N; j++)
            hasil[i] += a[i][j] * x[j];  // elemen baris i dikalikan elemen vektor yang sesuai.
    }
 
    /* tampilkan matriks A, vektor x, dan hasil */
    printf("    Matriks A    | Vektor x |   Hasil\n");
    printf("---------------------------------------\n");
    for (int i = 0; i < N; i++) {
        printf("[");
        for (int j = 0; j < N; j++)
            printf("%3d", a[i][j]);
        printf("  ]   [%3d  ]  =  [%4d  ]\n", x[i], hasil[i]);
    }
 
    printf("\nRincian perhitungan:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = ", i);
        for (int j = 0; j < N; j++) {
            printf("(%d*%d)", a[i][j], x[j]);
            if (j < N - 1) printf(" + ");  // mencetak tanda + di antara suku, kecuali setelah suku terakhir.
        }
        printf(" = %d\n", hasil[i]);
    }
 
    return 0;
}