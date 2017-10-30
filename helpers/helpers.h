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



