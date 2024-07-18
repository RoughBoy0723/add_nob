#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <stddef.h>
#include <iostream>
#include <cstdint>

uint32_t *read_fp_ntohl(char **fp,int fp_cnt);

void sum_print_res(uint32_t *num, int fp_cnt);
