#include "add_nob.h"

uint32_t *read_fp_ntohl(char **fp,int fp_cnt){
    uint32_t *buffer = (uint32_t*)malloc(sizeof(uint32_t)*fp_cnt);
    if (buffer == NULL) {
        perror("Memory allocation failure");
        exit(1);
    }
    for(int i = 0 ; i < fp_cnt ; i++){
        FILE *res = fopen(*(fp+i), "r");
        if(res == NULL){
            perror("File that does not exist");
            free(buffer);
            exit(1);
        }
        fseek(res, 0, SEEK_END);
        int size = ftell(res);
        if(size < 4){
            perror("File size not in compliance");
            free(buffer);
            exit(1);
        }
        fseek(res, 0, SEEK_SET);
        fread(&(buffer[i]), sizeof(uint32_t), 1, res);
        buffer[i] = ntohl(buffer[i]);
        fclose(res);
    }
    return buffer;
}

void sum_print_res(uint32_t *num, int fp_cnt){
    uint32_t sum_res = 0;
    for(int i = 0 ; i < fp_cnt ; i++){
        sum_res += num[i];
    }

    for(int i = 0 ; i < fp_cnt ; i++){
        printf("%d(0x%x)", num[i], num[i]);
        if(i != fp_cnt -1 ){
            printf(" + ");
        }
    }
    printf(" = %d(0x%x)\n",sum_res,sum_res);
}


