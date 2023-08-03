#include <stdio.h>
#include<string.h>
typedef unsigned char *byte_pointer;

void show_bytes(unsigned char *start, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x) { show_bytes((unsigned char *)&x, sizeof(int)); }

void show_float(float x) { show_bytes((unsigned char *)&x, sizeof(float)); }

void show_pointer(void *x) { show_bytes((unsigned char *)&x, sizeof(void *)); }

void test_show_bytes(int val) {
    int ival = val;
    float fval = (float)ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

int main() {
    test_show_bytes(12345);

    printf("------------\n");
    int val = 0x87654321;

    byte_pointer valp = (byte_pointer)&val;
    show_bytes(valp, 1);
    show_bytes(valp, 2);
    show_bytes(valp, 3);
    printf("------------\n");
    show_int(3510593);
    show_float(3510593.0);
    const char * s = "abcdef";
    show_bytes((byte_pointer)s, strlen(s));
    return 0;
}