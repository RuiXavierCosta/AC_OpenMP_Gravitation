#include "helpers.h"

void print_body(CORPO *body){
    printf("BODY -> p = %.3f,%.3f,%.3f || %.3f,%.3f,%.3f     m = %0.1f\n",
        body->p.x, body->p.y, body->p.z,
        body->p.versor, body->p.theta, body->p.phi,
        body->m);
}

int get_body_count(){
    int body_count = 0;
    int ch=0;
    FILE *fp;
    fp = fopen(INPUT_FILE, "r");

    if (fp == NULL){
        return 0;
    }

    // vai contar o numero de linhas para saber
    // quantos corpos sao, para alocar memoria
    while ((ch = fgetc(fp)) != EOF){
        if (ch == '\n'){
            body_count++;
        }
    }

    fclose(fp);
    return body_count;
}

CORPO create_body_from_line(char* str){
    char *token = (char*)malloc(sizeof(char)*56);
    CORPO body;
    double values[4];

    int i = 0;
    while((token = strsep(&str, " ")) != NULL){
        if(token != "\n" && atoi(token) != EOF){
            values[i] = atof(token);
            i++;
        }
    }

    body.p = get_vector_cartesian(values[0],values[1],values[2]);
    body.m = values[3];

    //print_body(&body);
    return body;
}

CORPO *read_from_file(int *total_time, int *time_delta, int body_count){
    char *buff = (char*)malloc(sizeof(char)*256);
    FILE *fp;
    fp = fopen(INPUT_FILE, "r");

    if (fp == NULL){
        return 0;
    }

    // reset do ponteiro para o inicio do ficheiro
    fseek(fp, 0, SEEK_SET);

    CORPO *bodies = (CORPO *)malloc(sizeof(CORPO)*body_count);
    int i = -1;

    while((fgets (buff, 32, fp)!=NULL)){
        if( i == -1){
            *total_time = atoi((strsep(&buff, " ")));
            *time_delta = atoi(buff);
            i++;
        }else{
            bodies[i] = create_body_from_line(buff);
            print_body(&bodies[i]);
            //printf("i = %i\n",i);
            i++;
        }
    }

    fclose(fp);
    return bodies;
}

void write_position_to_file(VECTOR p, FILE *fp){
    fprintf(fp, "%0.5f %0.5f %0.5f\n", p.x, p.y, p.z);
}
