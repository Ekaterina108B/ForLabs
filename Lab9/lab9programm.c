
#include <stdio.h>

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)


int main() {
    const int I = -22, J = 14, L = -14;
    int ik = I, jk = J, lk = L;
    int i0, j0, l0;
    int stipulation;
    for(int k = 1; k < 51; k++){
	i0 = ik;
        j0 = jk;
        l0 = lk;
        ik = (i0 * MIN(j0, l0) + j0 * MIN(i0, l0) + k * k) % 20;
        jk = (i0 % 10 - k) * (j0 % 10 + k) * (l0 % 10 - k) % 25;
        lk = MAX(MIN(i0 + j0, i0 + l0) % 25, MAX(i0 + l0, j0 + k) % 20) + 10;
        stipulation = ik + jk;
        if((stipulation + 10 <= 0) && (stipulation + 20 >= 10)){
            printf("Точка попала в заданную область плоскости н %d шаге.\n", k);
            printf("Время попадания: %d шагов.\n", k);
            printf("Координаты точки: (%d, %d).\n", ik, jk);
            printf("Значение динамического параметра движения: %d.\n", lk);
            return 0;
        }
        
    }
    printf("ПРОМАХ! Точка не попала в заданную область плоскости не более, чем за 50 шагов.\n");
    printf("Время окончания движения: 50 шагов.\n");
    printf("Координаты точки: (i = %d, j = %d).\n", ik, jk);
    printf("Значение динамического параметра движения: l = %d.\n", lk);
    return 0;
}

