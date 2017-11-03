#include "main.h"
#include "helpers/helpers.h"

#define TOTAL_CORPOS 10

void print_body(CORPO body){
    printf("BODY -> p = %.3f,%.3f,%.3f || %.3f,%.3f,%.3f     m = %0.1f\n",
        body.p.x, body.p.y, body.p.z,
        body.p.versor, body.p.theta, body.p.phi,
        body.m);
}

CORPO * generate_mock_bodies(int body_count){
    CORPO *bodies = (CORPO *)malloc(sizeof(CORPO)*body_count);

    for(int i = 0; i < body_count; i++){
        bodies[i].p = get_vector_cartesian(i, i, i);
        bodies[i].m = i;
        bodies[i].f = get_vector_cartesian(0, 0, 0);
        bodies[i].v = get_vector_cartesian(0, 0, 0);    

        // print_body(bodies[i]);
    }

    return bodies;
}


int main(int argc, char ** argv){
    //CORPO *random_bodies = generate_mock_bodies(TOTAL_CORPOS);
    int total_time, delta_time;

    read_from_file(&total_time, &delta_time);
    printf("total = %d. delta = %d", total_time, delta_time);


    return 0;
}

