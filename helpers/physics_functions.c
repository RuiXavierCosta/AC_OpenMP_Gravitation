#include "helpers.h"

VECTOR forca(CORPO i, CORPO j){
    VECTOR resultado;

    VECTOR diferenca;
    
    diferenca = sub_versor(i, j);
/**
    resultado =((G*i.m*j.m)/(pow(diferenca.versor, 2.00))*(()/(diferenca.versor)) ;
**/
return resultado;
}

VECTOR aceleracao(CORPO i){
    VECTOR soma;
    VECTOR aceleracao;
    soma= sum(i);
    
    i.a.x= soma.x / i.m;
    i.a.y= soma.y / i.m;
    i.a.z= soma.z / i.m;

    return aceleracao;
};

VECTOR velocidade(CORPO i, int TEMPO){
    VECTOR velocidade;

    velocidade.x=(i.v.x)+(i.a.x)*TEMPO;
    velocidade.y=(i.v.y)+(i.a.y)*TEMPO;
    velocidade.z=(i.v.z)+(i.a.z)*TEMPO;

    return velocidade;
};

VECTOR posicao(CORPO i, int TEMPO){
    VECTOR posicao;

    posicao.x=(i.p.x)+(i.v.x)*TEMPO;
    posicao.y=(i.p.y)+(i.v.y)*TEMPO;
    posicao.z=(i.p.z)+(i.v.z)*TEMPO;

    return posicao;
};