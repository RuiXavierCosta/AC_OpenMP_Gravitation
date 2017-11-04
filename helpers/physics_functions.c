#include "helpers.h"

VECTOR forca(CORPO i, CORPO j){
    double eq1;
    VECTOR eq2;
    VECTOR dif_vector;
    double aux =0.0, dif_versor =0.0;

    dif_vector = sub_vector(i.p, j.p);
    dif_versor = get_versor(dif_vector.x, dif_vector.y, dif_vector.z);

    eq1 = (G*i.m*j.m)/pow(dif_versor, 2.0);
    // relembro que aux e um escalar
    aux = pow(dif_versor, -1.0);

    eq2 = mult_vector_with_scalar(dif_vector, aux);
    return mult_vector_with_scalar(eq2, eq1);
}

VECTOR aceleracao(CORPO i){
    return mult_vector_with_scalar(i.f, i.m);
};

VECTOR velocidade(VECTOR v_anterior, VECTOR a, int tempo_delta){
    return sum_vector(v_anterior, mult_vector_with_scalar(a, tempo_delta));
};

VECTOR posicao(VECTOR p_anterior, VECTOR v, int tempo_delta){
    return sum_vector(p_anterior, mult_vector_with_scalar(v, tempo_delta));
};