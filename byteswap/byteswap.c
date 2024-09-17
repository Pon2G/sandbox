#include    <stdio.h>
#include    <stdlib.h>
#include    <arpa/inet.h>

char input[128] = {'\0'};     /* 入力ファイルパス */
char output[128] = {'\0'};    /* 出力ファイルパス */

int main(int argc, char* argv[]) {
    if (argc < 3) {
        fprintf(stderr, "%s 入力ファイルパス 出力ファイルパス\n", argv[0]);
        exit(1);
    }
    sprintf(input, "%s", argv[1]);
    sprintf(output, "%s", argv[2]);

    FILE *fpin = NULL;
    if ((fpin = fopen(input, "rb")) == NULL) {
        fprintf(stderr, "cannot open %s\n", input);
        exit(1);
    }
    FILE *fpout = NULL;
    if ((fpout = fopen(output, "wb")) == NULL) {
        fprintf(stderr, "cannot open %s\n", output);
        fclose(fpin);
        exit(1);
    }

    short buf, buf2;
    while (fread(&buf, sizeof(buf), 1, fpin) == 1) {
        buf2 = htons(buf);
        if (fwrite(&buf2, sizeof(buf), 1, fpout) < 1) {
            fprintf(stderr, "fwrite error\n");
            break;
        }
    }


    fclose(fpin);
    fclose(fpout);

    return 0;
}
