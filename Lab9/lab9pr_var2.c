#include <stdio.h>

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

int MOD(int a, int b){
    int res;
    if((a > 0) && (b > 0)){
	    res = a % b;
    }
    if((a < 0) && (b > 0)){
            res = a % b + a;
    }
    if((a > 0) && (b < 0)){
            res = a % b + b;
    }
    if((a < 0) && (b < 0)){
            res = a % b;
    }
    return res;
}

int main() {
    const int I = -22, J = 14, L = -14;
    int ik = I, jk = J, lk = L;
    int i0, j0, l0, auxiliary_ik, auxiliary_jk, auxiliary_lk_1, auxiliary_lk_2;
    int stipulation;
    for(int k = 1; k < 51; k++){

        j0 = jk;
        l0 = lk;
	auxiliary_ik = i0 * MIN(j0, l0) + j0 * MIN(i0, l0) + k * k;
        ik = MOD(auxiliary_ik, 20);
	auxiliary_jk = (MOD(i0, 10) - k) * (MOD(j0, 10) + k) * (MOD(l0, 10) - k);
        jk = MOD(auxiliary_jk, 25);
	auxiliary_lk_1 = MIN(i0 + j0, i0 + l0);
	auxiliary_lk_2 = MAX(i0 + l0, j0 + k);
        auxiliary_lk_1 = MOD(auxiliary_lk_1, 25);
        auxiliary_lk_2 = MOD(auxiliary_lk_2, 20);
        lk = MAX(auxiliary_lk_1, auxiliary_lk_2) + 10;
        
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
