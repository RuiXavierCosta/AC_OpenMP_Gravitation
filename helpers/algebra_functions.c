#include "helpers.h"


double get_versor(double x, double y, double z){
    return sqrt( pow(x, 2.0) + pow(y, 2.0) + pow(z, 2.0) );
}

VECTOR sum(CORPO i){
    VECTOR soma;

    soma.x+= i.f.x;
    soma.y+= i.f.y;
    soma.z+= i.f.z;

    return soma;
}

VECTOR sub_versor(CORPO i, CORPO j){
    VECTOR diferenca;
    diferenca.x= j.p.x - i.p.x;
    diferenca.y= j.p.y - i.p.y;
    diferenca.z= j.p.z - i.p.z;
    diferenca.versor = get_versor(diferenca.x, diferenca.y, diferenca.z);

    return diferenca;
}

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

double *get_angles(double x, double y, double z){
    double *angles = (double *)malloc(sizeof(double)*2);
    double theta, phi;
    double versor = get_versor(x,y,z);
    
    if(versor > 0){
        theta = acos(z / versor);
    }else{
        theta = 0.0;
    }

    if( x > 0){
        phi = atan(y / x);
    }else{
        phi = 0.0;
    }

    angles[0] = theta;
    angles[1] = phi;
    return angles;
}



VECTOR get_vector_cartesian(double x, double y, double z){
    VECTOR v;

    v.x = x;
    v.y = y;
    v.z = z;

    v.versor = get_versor(x,y,z);
    double *angles = get_angles(x,y,z);
    v.theta = angles[0];
    v.phi = angles[1];

    return v;
}

VECTOR get_vector_polar(double versor, double theta, double phi){
    VECTOR v;

    v.versor = versor;
    v.theta = theta;
    v.phi = phi;

    v.x = versor * sin(theta) * cos(phi);
    v.y = versor * sin(theta) * sin(phi);
    v.z = versor * cos(phi);

    return v;
}