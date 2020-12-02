#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main () {
    FILE *file;
    file = fopen("./input.txt", "r");

    // Create an array to store our numbers. I'm sure there's a better way to handle this array.
    int numbers[256] = {0};
    int i = 0;
    int k = 0;
    char str[8];
    char c;

    // Iterate over characters in file, building up each number as we go
    for (c = getc(file); c != EOF; c = getc(file)) {
        if (c == '\n') {
            numbers[i] = atoi(str);
            memset(&str[0], 0, sizeof(str));
            k = 0;
            i++;
        } else {
            str[k] = c;
            k++;
        }
    }

    // Nested loop (I know, eww) which checks each number against every other number.
    // If three of them add to equal 2020 we print the numbers and break out of the loops.
    int j, l, p;
    for (j = 0; j < sizeof(numbers); j++) {
        if (numbers[j] == 0) break;

        for (l = 0; l < sizeof(numbers); l++) {
            if (numbers[l] == 0) break;
            if (l == j) continue;

            for (p = 0; p < sizeof(numbers); p++) {
                if (numbers[p] == 0) break;
                if (p == l) continue;

                int n1 = numbers[j];
                int n2 = numbers[l];
                int n3 = numbers[p];

                // Makes things take way too long
                // printf("Checking %d, %d, and %d\n", n1, n2, n3);

                if (n1 + n2 + n3 == 2020) {
                    printf("\nThe numbers are %d, %d, and %d\n", n1, n2, n3);
                    printf("Their product is %d\n", n1 * n2 * n3);
                    goto success;
                }
            }
            
        }
    }

    printf("Failed to find a match :(\n");
    fclose(file);
    return 1;

success:
    fclose(file);
    return 0;
}
