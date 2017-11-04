#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    VECTOR a;
    VECTOR dif;
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
 * print_body
 *  funcao auxiliar para imprimir para o ecra os
 *  valores dos corpos
**/
void print_body(CORPO *body);

/**
 * read_from_file:
 *  ficheiro para obter a informacao dos corpos, 
 *  apartir de um ficheiro
**/
CORPO *read_from_file(int *total_time, int *time_delta, int body_count);


/**
 * write_to_file:
 *  ficheiro para escrever a informacao dos corpos em ficheiro, 
 *  com uma estrutura pre definida
**/
int write_to_file(CORPO *conjunto_corpos, int body_count);

/**
 * get_body_count
 *  vai ler o ficheiro sem recuperar nenhuma informacao,
 *  so para contar o numero de linhas, para saber
 *  quantos corpos vao ser introduzidos
 **/
int get_body_count();

/**
 * create_body_from_line
 *  tem como parametro de entrada uma linha do ficheiro
 *  que corresponde a x,y,z e m de um corpo, e devolve um novo corpo.
 **/
CORPO create_body_from_line(char* str);

/**
 * subtracao
  **/
VECTOR sub_vector(VECTOR a, VECTOR b);

/**
 * mult_vector
 *  multiplica 2 vectores, devolve um novo vector
**/
VECTOR mult_vector(VECTOR a, VECTOR b);

/**
 * mult_vector_with_scalar
 *  multiplica um vector por um valor escalar
**/
VECTOR mult_vector_with_scalar(VECTOR v, double d);

/**
 * forca
 *  tem como parametro de entrada duas estruturas do tipo Corpo
 *   e devolve um novo vector.
 **/

VECTOR forca( CORPO i, CORPO j);

/**
 * soma de vectores
  **/
  VECTOR sum_vector(VECTOR a, VECTOR b);

  /**
 * aceleração
  **/

  VECTOR aceleracao(CORPO i);
/**
 * velocidade
  **/
  VECTOR velocidade(VECTOR v_anterior, VECTOR a, int tempo_delta);

  /**
 * posicao
  **/
  VECTOR posicao(VECTOR p_anterior, VECTOR v, int TEMPO);