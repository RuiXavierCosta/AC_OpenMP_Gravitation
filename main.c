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
    VECTOR F = get_vector_cartesian(0,0,0);
    VECTOR p_anterior, v_anterior;

    printf("total = %d. delta = %d\n", total_time, delta_time);
    printf("body count=%i\n\n\n", body_count);

    for(int k = 0; k < total_time; k += delta_time){
        printf("\n\n Iteracao n - %i\n", k/delta_time);
        for (int i=0; i<body_count; i++){
            //print_body(&P[i]);
            for(int j=0; j<body_count; j++ ){
                if( j != i ){
                    F = sum_vector(F, forca(P[i], P[j]));
                }
            }

            P[i].f = F;
            P[i].a=aceleracao(P[i]);
            v_anterior = P[i].v;
            P[i].v=velocidade(v_anterior, P[i].a, delta_time);
            p_anterior = P[i].p;
            P[i].p=posicao(p_anterior, P[i].v, delta_time);
            printf("px = %0.10f; py = %0.10f; pz = %0.10f;\n", 
                P[i].p.x,
                P[i].p.y,
                P[i].p.z
            );
        }
    }

    return 0;
}