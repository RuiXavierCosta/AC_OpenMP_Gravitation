#include <math.h>
#include <stdlib.h>
#include <stdio.h>

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
    double theta, phi;
} VECTOR;


/**
 * Corpo:
 *  define um corpo estelar,
 *  p = posicao no espaco,
 *  m = massa do corpo
 *  f = forca aplicada no corpo
 *  v = velocidade instantanea do corpo
**/
typedef struct Corpo{
    VECTOR p;
    double m;
    VECTOR f;
    VECTOR v;
} CORPO;

/**
 * get_vector_cartesian:
 *  devolve uma struct VECTOR com as coordenadas x,y e z iguais aos
 *  parametros de entrada, e calcula e atribui as coordenadas polares
**/
VECTOR get_vector_cartesian(double x, double y, double z);

/**
 * get_vector_polar:
 *  devolve uma struct VECTOR com os campos versor, alpha, beta e theta iguais aos
 *  parametros de entrada, e calcula e atribui as coordenadas cartesianas
**/
VECTOR get_vector_polar(double versor, double theta, double phi);

/**
 * get_versor:
 *  devolve o versor equivalente as coordenadas introduzidas
**/
double get_versor(double x, double y, double z);

/**
 * get_angles:
 *  devolve os angulos equivalente as coordenadas introduzidas,
 *  num referencial polar;
**/
double *get_angles(double x, double y, double z);

/**
 * read_from_file:
 *  ficheiro para obter a informacao dos corpos, 
 *  apartir de um ficheiro
**/
struct Corpo *read_from_file(int *total_time, int *time_delta);


/**
 * write_to_file:
 *  ficheiro para escrever a informacao dos corpos em ficheiro, 
 *  com uma estrutura pre definida
**/
<<<<<<< HEAD
<<<<<<< HEAD
int write_to_file();


/** 
 * Parte redigida por D. Rui Barbosa, primeiro de seu nome
**/

#define Grv = (6.67408*10^(-11));
/**
 * #define K= qql merda
**/
double TEMPO;


double Norma(Corpo i, Corpo j){
double componentes [4];
componentes[0]=((Corpo.j.p.x - Corpo.i.p.x)²;
componentes[1]=((Corpo.j.p.y - Corpo.i.p.y)²;
componentes[2]=((Corpo.j.p.z - Corpo.i.p.z)²;
componentes[3]=sqrt(componentes[0] + componentes[1] + componentes[2]);
retun componentes[4];
/** 
 * Com a norma organizada desta maneira podemos usar o valor 
 * do vetor da maneira que melhor servir as nossas necessidades
**/
};
 
double Força_componentes(Corpo i, Corpo j){
double Normalizado;
Normalizado= Norma(Corpo i, Corpo j);
double componentes [4];

componentes[0]=((Grv*Corpo.i.m*Corpo.j.m)/(Normalizado[0])^2]*[(Corpo.j.p.x - Corpo.i.p.x)/Normalizado[0]);
componentes[1]=((Grv*Corpo.i.m*Corpo.j.m)/(Normalizado[1])^2]*[(Corpo.j.p.x - Corpo.i.p.x)/Normalizado[1]);
componentes[2]=((Grv*Corpo.i.m*Corpo.j.m)/(Normalizado[2])^2]*[(Corpo.j.p.x - Corpo.i.p.x)/Normalizado[2]);
componentes[3]=((Grv*Corpo.i.m*Corpo.j.m)/(Normalizado[3])^2]*[(Corpo.j.p.x - Corpo.i.p.x)/Normalizado[3]);

return componentes[4];
};

double sum{
int componentes[4];

/**
* bla bla bla
**/

return componentes[4];
};

double Aceleracao_Componentes(Corpo i){
double SOMATORIO[4];
SOMATORIO= sum(Corpo i);
double componentes[4];

componentes[0]=SOMATORIO[0]/Corpo.i.m;
componentes[1]=SOMATORIO[1]/Corpo.i.m;
componentes[2]=SOMATORIO[2]/Corpo.i.m;
componentes[3]=SOMATORIO[3]/Corpo.i.m;

return componentes[4];
};


=======
int write_to_file(CORPO *conjunto_corpos);
>>>>>>> master
=======
int write_to_file(CORPO *conjunto_corpos, int body_count);
>>>>>>> master
