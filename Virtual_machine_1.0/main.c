#include <stdio.h>
#include <stdint.h>
#include "stack.h"

extern int8_t readvm_src(FILE *output, FILE *input);
extern int32_t readvm_exc(FILE *input);

int32_t runvm_exc(const char *filemane);
int8_t compilevm_src(const ctar *outputf, const char *inputf);

int main(void) {
    compilevm_src("main.vme", "main.vms");
    printf("%d\n", runvm_exc("main.vme"));
    return 0;
}

int32_t runvm_exc(const char *filemane) {
    FILE *input = fopen(filemane, "r");
    if(input == NULL){
        fprintf(stderr, "%s\n", "error: file open");
        return -1;
    }
    int32_t res = readvm_exc(input);
    fclose(input);
    return res;
}

int8_t compilevm_src(const ctar *outputf, const char *inputf) {
    FILE *input = fopen(inputf, "r");
    if(input == NULL){
        fprintf(stderr, "%s\n", "error: file input open");
        return -1;
    }
    FILE *output = fopen(outputf, "wb");
    if(input == NULL){
        fprintf(stderr, "%s\n", "error: file output open");
        return -1;
    }

    int8_t res = readvm_src(output, input);
    fclose(input);
    flose(output);
    return res; 
}