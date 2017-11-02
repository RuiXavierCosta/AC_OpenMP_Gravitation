#include "helpers.h"

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

    return body;
}

CORPO *read_from_file(int *total_time, int *time_delta){
    int body_count = 0;
    int ch=0;
    char *buff = (char*)malloc(sizeof(char)*256);
    FILE *fp;
    fp = fopen("bodies.txt", "r");

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
            i++;
        }

    }

    fclose(fp);
    return 0;
}

int write_to_file(CORPO *conjunto_corpos, int body_count){
    FILE *fp;

    fp = fopen("build/bodie_positions.txt", "w");
    for(int i = 0; i < body_count; i++){
        fprintf(fp, "Teste %d", i);
    }
    
    return 0;
}
