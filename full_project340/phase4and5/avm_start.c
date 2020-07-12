#include "avm.h"

int main(int argc, char** argv) {
    unsigned sz;
    FILE* bf = fopen("TargetCodeFile.abc", "rb");

    fseek(bf, 0L, SEEK_END);
    sz = ftell(bf);
    rewind(bf);

    read_magic(bf);
    read_strings(bf);
    read_numbers(bf);
    read_userFuncs(bf);
    read_libFuncs(bf);
    read_code(bf);
    read_totalglobals(bf);
    avm_initstack();
    
    while (executionFinished == 0) {
        execute_cycle();
    }
    fclose(bf);
}