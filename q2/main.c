/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define DEBUG
#define DICT_FILE "input.txt"
#define MAX_SIZE 16

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

int main(int argc, char *argv[])
{
    FILE *fp;
    char line[MAX_SIZE];
    char output;
    int i = 0;
    struct timespec start, end;
    double cpu_time;


    /* check file opening */
    fp = fopen(DICT_FILE, "r");
    if (fp == NULL) {
        printf("cannot open the file\n");
        return -1;
    }
    while (fgets(line, sizeof(line), fp)!=NULL) {
        while (line[i] != '\t')
            i++;
#ifdef DEBUG
        assert(smallest_character(line,line[i-1]) == line[i+1]);
#endif
        clock_gettime(CLOCK_REALTIME, &start);
        output = smallest_character(line,line[i-1]);
        clock_gettime(CLOCK_REALTIME, &end);
        cpu_time = diff_in_second(start, end);
        printf("execution time of smallest_character() : %lf sec\n", cpu_time);
        printf("output:%c\n", output);
        i = 0;
    }
    fclose(fp);
    return 0;
}
