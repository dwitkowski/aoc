#include <stdio.h>
#include <stdbool.h>

#define AOC_DEBUG 0

int string_to_int(char *string) {
    int result = 0;
    int i = 0;
    while (string[i] != '\0') {
        result *= 10;
        result += string[i] - '0';
        i++;
    }
    return result;
}

int main() {
    int total_sum = 0;
    FILE *file = fopen("input.txt", "r");
    char first_number = 0;
    char last_number = 0;
    int line_number = 1;
    while (!feof(file)) {
        char c = fgetc(file);
        
        
        if (c == '\n' || c == EOF) {
            char line_number_string[3] = {first_number, last_number, '\0'};
            int line_value = string_to_int(line_number_string);
            total_sum += line_value;
            first_number = 0;
            last_number = 0;
            if (AOC_DEBUG) printf("Finished line %d with number %d\n", line_number, line_value);
            line_number++;
            continue;
        }
        //printf("Read character '%c'\n", c);
        if (c >= '0' && c <= '9') {
            if (first_number != 0) {
                if (AOC_DEBUG) printf("Set last number to %c\n", c);
                last_number = c;
            } else {
                if (AOC_DEBUG) printf("Set first number to %c\n", c);
                first_number = c;
                last_number = c;
            }
        }
    }
    printf("Sum of all calibration values: %d\n", total_sum);
    fclose(file);
    return 0;
}