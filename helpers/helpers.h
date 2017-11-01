#include <math.h>

#define G 667408E-16

/** 
 * Vector:
 *  define um vector no espaco,
 *  com valor x, y, z, modulo do vector (versor) e angulo do vector
**/
typedef struct Vector
{
    double x,y,z;
    double versor;
    double angulo;
} VECTOR;


/**
 * Corpo:
 *  define um corpo estelar,
 *  p = posicao no espaco,
 *  m = massa do corpo
 *  f = forca aplicada no corpo
 *  v = velocidade instantanea do corpo
**/
typedef struct Corpo {
    VECTOR p;
    double m;
    VECTOR f;
    VECTOR v;
} CORPO;

/**
 * read_from_file:
 *  ficheiro para obter a informacao dos corpos, 
 *  apartir de um ficheiro
**/
int read_from_file();

/**
 * write_to_file:
 *  ficheiro para escrever a informacao dos corpos em ficheiro, 
 *  com uma estrutura pre definida
**/
int write_to_file();


/** 
 * Parte redigida por D. Rui Barbosa, primeiro de seu nome
**/

/**
 * #define K= qql merda
**/
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


