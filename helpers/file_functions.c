#include "helpers.h"

struct Corpo *read_from_file(int *total_time, int *time_delta){
    int body_count = 0;
    int ch=0;
    char buff;
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
    int t_total = -1, delta = -1;

    while((buff=fgetc(fp))!=EOF){
        if(buff == '\n'){
            i++;
        } else{
            if( i == -1 && buff != ' '){
                if(t_total == -1){
                    t_total = (int)buff;
                } else if(delta == -1){
                    delta = (int)buff;
                }
            }
        }
    }

    printf("total = %d. delta = %d", t_total, delta);

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
