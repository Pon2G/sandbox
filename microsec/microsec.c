#include <stdio.h>
#include <time.h>
#include <sys/time.h>

char* strmtime(char* str) {
    struct timeval  mTime;
    struct tm       *tmTime;
    gettimeofday(&mTime, NULL);
    tmTime = localtime((long long int*)&mTime.tv_sec);
    sprintf(str, "%4d-%02d-%02d %02d:%02d:%02d.%03ld",
            tmTime->tm_year + 1900,
            tmTime->tm_mon + 1,
            tmTime->tm_mday,
            tmTime->tm_hour,
            tmTime->tm_min,
            tmTime->tm_sec,
            mTime.tv_usec
            );
    return str;
}

int main() {
    char str[128];
    int ii;
    for (ii = 0; ii < 100; ii++) {
        printf("%s\n", strmtime(str));
    }
    return 0;
}
