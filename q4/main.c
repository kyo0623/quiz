/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>

#define DEBUG
#define DICT_FILE "input.txt"
#define MAX_SIZE 512

static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}

unsigned int transform(char line[], int *value)
{
    int counter = 0;
    char *buf;
    buf = strtok(line, ",");
    while(buf != NULL) {
        value[counter] = atoi(buf);
        counter++;
        buf = strtok (NULL, ",");
    }
    return counter;
}

int main(int argc, char *argv[])
{
    FILE *fp;
    char line[MAX_SIZE];
    int value[100];
    int length = 0;
    int input_ans;
    int i = 0;
    char input_array[MAX_SIZE];
    char *buf;
    int status = 0;
    int result = 0;
    struct timespec start, end;
    double cpu_time;


    /* check file opening */
    fp = fopen(DICT_FILE, "r");
    if (fp == NULL) {
        printf("cannot open the file\n");
        return -1;
    }

    clock_gettime(CLOCK_REALTIME, &start);
    while (fgets(line, sizeof(line), fp) != NULL) {
        while(line[i] != '\0')
            i++;
        buf = strtok(line, "\t");
        while(buf != NULL) {
            if(status ==0 )
                strcpy(input_array,buf);
            else
                input_ans = atoi(buf);
            status++;
            buf = strtok (NULL, "\t");
        }
        length = transform(input_array, value);
#ifdef DEBUG
        assert(maxSubArray(value, length) == input_ans);
#endif
        result = maxSubArray(value, length);

        printf("input:");
        for(i = 0; i < length; i++) {
            printf("  %d", value[i]);
        }
        printf("\nsum: %d\n", result);
        status = 0;
        i = 0;
    }
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diff_in_second(start, end);
    printf("execution time of maxSubArray() : %lf sec\n", cpu_time);

    fclose(fp);
    return 0;
}
