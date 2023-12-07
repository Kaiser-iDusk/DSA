#include main() <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

/*
 * Complete the 'calc_bases' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING sdna1 as parameter.
 */

/*
 * To return the integer array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * int* return_integer_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static int a[5] = {1, 2, 3, 4, 5};
 *     
 *     return a;
 * }
 *
 * int* return_integer_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     int *a = malloc(5 * sizeof(int));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = i + 1;
 *     }
 *
 *     return a;
 * }
 *
 */
int* calc_bases(char* sdna1, int* result_count) {
    // Enter your code here
    result_count = calloc(4, sizeof(int));
    int i = 0;
    while((sdna1[i])!='\0'){
        if(sdna1[i]=='A'){
            result_count[0]++;
        }
        if(sdna1[i]=='T'){
            result_count[1]++;
        }
        if(sdna1[i]=='C'){
            result_count[2]++;
        }
        if(sdna1[i]=='G'){
            result_count[3]++;
        }
        i++;
    }
    return result_count;
    }

/*
 * Complete the 'calc_substring' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING sdna2
 *  2. STRING tdna1
 */

int calc_substring(char* sdna2, char* tdna1) {
    // Enter your code here

}

/*
 * Complete the 'calc_complement' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING sdna3 as parameter.
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
char* calc_complement(char* sdna3) {
    // Enter your code here
    char* ret = malloc(sizeof(sdna3));
    int i = 0;
    while(sdna3[i]!='\0'){
        if(sdna3[i]=='A'){
            ret[i] = 'T';
        }
        if(sdna3[i]=='T'){
            ret[i] = 'A';
        }
        if(sdna3[i]=='C'){
            ret[i] = 'G';
        }
        if(sdna3[i]=='G'){
            ret[i] = 'C';
        }
        i++;
    }
    return ret;
}

/*
 * Complete the 'calc_missmatch' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING sdna4
 *  2. STRING cdna1
 */

int calc_missmatch(char* sdna4, char* cdna1) {
    // Enter your code here
    
}

int main()
{
    char* sdna4 = readline();

    char* tdna = readline();

    char* cdna1= readline();

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}