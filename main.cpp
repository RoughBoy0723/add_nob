#include "add_nob.h"

int main(int argc, char *argv[]){
    if(argc <=1){
        perror("Invalid input\n");
        exit(0);
    }
    int fp_cnt = argc - 1 ;

    uint32_t *num = read_fp_ntohl(argv+1,fp_cnt);

    sum_print_res(num, fp_cnt);

    free(num);
    return 0;
}
