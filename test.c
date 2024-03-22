#define STB_IMAGE_IMPLEMENTATION
#define STBI_FAILURE_USERMSG
#include "stb_image.c"

#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void printstr(char* a) {
    printf("%s", a);
}

void printint(long long int a) {
    printf("%llu", a);
}

void printfloat(float a) {
    printf("%f\n", a);
}

double random_double01() {
    // Returns a random real in [0,1).
    return rand() / (RAND_MAX + 1.0);
}

double random_double(double min, double max) {
    // Returns a random real in [min,max).
    return min + (max-min)*random_double01();
}

int random_int(int min, int max) {
    return (int)random_double(min, max + 1);
}

void log_pc(int i, int total) {
    fprintf(stderr, "%f percent\n", ((float)i)/((float)total) * 100);
}

void log_info(char* ch) {
    fprintf(stderr, "%s percent\n", ch);
}

int idx = 0;
char tmp[256];

char* get_name(int n) {
    sprintf(tmp, "out/s-%d.png", idx++);

    return (char*)&tmp;
}
