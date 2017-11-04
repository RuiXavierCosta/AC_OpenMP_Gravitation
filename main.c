#include "main.h"
#include "helpers/helpers.h"

#define TOTAL_CORPOS 10

CORPO *generate_mock_bodies(int body_count){
    CORPO *bodies = (CORPO *)malloc(sizeof(CORPO)*body_count);

    for(int i = 0; i < body_count; i++){
        bodies[i].p = get_vector_cartesian(i, i, i);
        bodies[i].m = i;
        bodies[i].f = get_vector_cartesian(0, 0, 0);
        bodies[i].v = get_vector_cartesian(0, 0, 0);    

        //print_body(&bodies[i]);
    }

    return bodies;
}


int main(int argc, char ** argv){
    //CORPO *random_bodies = generate_mock_bodies(TOTAL_CORPOS);
    int total_time, delta_time, body_count;
    
    // CORPO *P = generate_mock_bodies(TOTAL_CORPOS);
    body_count = get_body_count();
    CORPO *P = read_from_file(&total_time, &delta_time, body_count);
    printf("total = %d. delta = %d\n", total_time, delta_time);
    printf("body count=%i\n", body_count);

    for (int i=0; i<body_count; i++){
        //print_body(&P[i]);
        for(int j=0; j<body_count; j++ ){
            if( j != i ){                
                P[i].dif= sub_versor(P[i], P[j]);
                P[i].f=forca(P[i], P[j]);
                P[i].a=aceleracao(P[i]);
                P[i].v=velocidade(P[i], delta_time);
                P[i].p=posicao(P[i], delta_time);
            }                
            if( i == 0){
                printf("%0.3f\n", P[j].dif.x);
                //print_body(&P[j]);
            }
        }
    }

    return 0;
}