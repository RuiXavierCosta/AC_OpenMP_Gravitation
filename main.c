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
	clock_t t1,t2;
    
    // CORPO *P = generate_mock_bodies(TOTAL_CORPOS);
    body_count = get_body_count();
    CORPO *P = read_from_file(&total_time, &delta_time, body_count);
    VECTOR F = get_vector_cartesian(0,0,0);
    VECTOR p_anterior, v_anterior;
    FILE *fp;
    
    fp = fopen(OUTPUT_FILE, "w");
    if (fp == NULL){
        printf("\n\nOcorreu um erro ao abrir o ficheiro!\n");
        return 1;
    }
    
    printf("total = %d. delta = %d\n", total_time, delta_time);
    printf("body count=%i\n\n\n", body_count);

	t1 = clock();
    printf("A comecar a simulacao com %i processadores. Hello P%i.\n", omp_get_num_threads(), omp_get_thread_num());
    for(int k = 0; k < total_time; k += delta_time){
        if(omp_get_thread_num() == 0){
            printf("Iteracao temporal %i/%i (k = %i).\n", k/delta_time, total_time/delta_time, k/delta_time);
        }
        #pragma omp parallel num_threads(4)
        {
            #pragma omp for
            for (int i=0; i<body_count; i++){
                write_position_to_file(P[i].p, fp);
                //printf("fx = %.13f fy = %.13f fz = %.13f\n", P[i].f.x, P[i].f.y, P[i].f.z);
                //print_body(&P[i]);
                //#pragma omp for
                for(int j=0; j<body_count; j++ ){
                    if( j != i ){
                        F = sum_vector(F, forca(P[i], P[j]));
                    }
                }

                //#pragma sections
                {
                    //#pragma section
                    //{
                        P[i].f = F;
                        P[i].a=aceleracao(P[i].f, P[i].m);
                    //}
                    //#pragma section
                    //{
                        v_anterior = P[i].v;
                        P[i].v=velocidade(v_anterior, P[i].a, delta_time);
                    //}
                    //#pragma sections
                    //{
                        p_anterior = P[i].p;
                        P[i].p=posicao(p_anterior, P[i].v, delta_time);
                    //}
                    // printf("px = %0.10f; py = %0.10f; pz = %0.10f;\n", 
                    //     P[i].p.x,
                    //     P[i].p.y,
                    //     P[i].p.z
                    // );
                }

                //quando correr todas os corpos na iteracao atual
                // imprime o \n para sinalizar a nova iteracao
                if(i == body_count - 1){
                    fprintf(fp, "\n");
                }
            }
        }
    }
    fclose(fp);
    t2=clock();
    printf("Simulacao gerada em %6.3f secs.\n",(((double)(t2-t1))/CLOCKS_PER_SEC));

    return 0;
}