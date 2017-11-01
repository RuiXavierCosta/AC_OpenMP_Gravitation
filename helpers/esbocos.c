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


