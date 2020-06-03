#include <stdio.h>

int main() {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d\n", i);
    }
    printf("%d\n\n", i);
    int j;
    for (j = 0; j < 10;) {
        printf("%d\n", j++);
    }
    printf("%d\n\n", j);
}