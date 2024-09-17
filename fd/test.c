#include <stdio.h>

int
main(int argc, char* argv[]) {
    fprintf(stdout, "NORMAL\n");
    fprintf(stderr, "ERROR\n");
    return 0;
}
