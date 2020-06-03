#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFSIZE 80
#define ROUND(x) ((x > 0) ? (x + 0.5) : (x - 0.5))

int main(int argc, char **argv) {
    int tm, __amp = 0, _amp = 0, amp, _tm;
    char buf[BUFSIZE];
    double vout;
    FILE *fp;

    if (argc != 2) {
        return EXIT_FAILURE;
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        return EXIT_FAILURE;
    }

    srand((unsigned)time(NULL));

    while (fgets(buf, sizeof(buf), fp) != NULL) {
        if (buf[0] == '#') continue;
        
        tm  = atoi(strtok(buf, ","));
        amp = atoi(strtok(NULL, "\r\n\0"));

        if (_amp == 0) {
            _amp = amp;
            continue;
        }
        if (__amp == 0) {
            __amp = _amp;
            _tm = tm;
            continue;
        }

        vout = ROUND((__amp + _amp + amp) / 3.0);
        printf("%4d, %4d\n", _tm, (int)vout);

        __amp = _amp;
        _amp  = amp;
        _tm   = tm;
    }
    fclose(fp);

    return EXIT_SUCCESS;
}
