#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"

double TEMPO;


double *Norma(struct Corpo i, struct Corpo j){
    double componentes [4];
    componentes[0]=((j.p.x - i.p.x)^2);
    componentes[1]=((j.p.y - i.p.y)^2);
    componentes[2]=((j.p.z - i.p.z)^2);
    componentes[3]=sqrt(componentes[0] + componentes[1] + componentes[2]);
    return componentes;
    /** 
     * Com a norma organizada desta maneira podemos usar o valor 
     * do vetor da maneira que melhor servir as nossas necessidades
     * Ccomponentes[0]=Xx; componentes[1]=Yy; componentes[2]=Zz; componentes[3]=Modulo das componentes;
    **/
};
 
double *forca_componentes(struct Corpo i, struct Corpo j){
    double *normalizado;
    normalizado = Norma(i, j);
    double componentes [4];

    componentes[0]=((G*i.m*j.m)/(normalizado[0])^2)*((j.p.x - i.p.x)/normalizado[0]);
    componentes[1]=((G*i.m*j.m)/(normalizado[1])^2)*((j.p.x - i.p.x)/normalizado[1]);
    componentes[2]=((G*i.m*j.m)/(normalizado[2])^2)*((j.p.x - i.p.x)/normalizado[2]);
    componentes[3]=((G*i.m*j.m)/(normalizado[3])^2)*((j.p.x - i.p.x)/normalizado[3]);

    return componentes;
}

double *sum(){
    int componentes[4];

    // TODO: Fazer isto

    return componentes;
}

double *aceleracao_componentes(struct Corpo i){
    double *SOMATORIO;
    SOMATORIO= sum(i);
    double componentes[4];

    componentes[0]=SOMATORIO[0]/i.m;
    componentes[1]=SOMATORIO[1]/i.m;
    componentes[2]=SOMATORIO[2]/i.m;
    componentes[3]=SOMATORIO[3]/i.m;

    return componentes;
};


double *velocidade_componentes(struct Corpo i){
    double componentes[4];

    componentes[0]=(i.v[0])+(i.a[0])*TEMPO;
    componentes[1]=(i.v[1])+(i.a[1])*TEMPO;
    componentes[2]=(i.v[2])+(i.a[2])*TEMPO;
    componentes[3]=(i.v[3])+(i.a[3])*TEMPO;

    return componentes;
};

double *posicao_componentes(struct Corpo i){
    double componentes[4];

    componentes[0]=(i.p[0])+(i.v[0])*TEMPO;
    componentes[1]=(i.p[1])+(i.v[1])*TEMPO;
    componentes[2]=(i.p[2])+(i.v[2])*TEMPO;
    componentes[3]=(i.p[3])+(i.v[3])*TEMPO;

    return componentes;
};