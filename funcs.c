#include <stdio.h>
#include "funcs.h"
#include <math.h>
#include <string.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

const char *HISTORY_FILE = "history.txt";

void menu_item_1(void) {
    printf("\n>> Menu 1: dBm to mW\n");
    int choice;
    double input, output;

    printf("1. dBm to mW\n");
    printf("2. mW to dBm\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter value in dBm: ");
        scanf("%lf", &input);
        output = dbm_to_mw(input);
        printf("Result: %.4f mW\n", output);
        save_history(input, output, "dBm", "mW");
    }
    else if (choice == 2) {
        printf("Enter value in mW: ");
        scanf("%lf", &input);
        output = mw_to_dbm(input);
        printf("Result: %.4f dBm\n", output);
        save_history(input, output, "mW", "dBm");
    } else {
        printf("Invalid choice.\n");
    }
 }

void menu_item_2(void) {
    printf("\n>> Menu 2: Hz to rad/s\n");
    int choice;
    double input, output;

    printf("1. Hz to rad/s\n");
    printf("2. rad/s to Hz\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter frequency in Hz: ");
        scanf("%lf", &input);
        output = hz_to_rad(input);
        printf("Result: %.4f rad/s\n", output);
        save_history(input, output, "Hz", "rad/s");
    }
    else if (choice == 2) {
        printf("Enter frequency in rad/s: ");
        scanf("%lf", &input);
        output = rad_to_hz(input);
        printf("Result: %.4f Hz\n", output);
        save_history(input, output, "rad/s", "Hz");
    } else {
        printf("Invalid choice.\n");
    }
}

void menu_item_3(void) {
    printf("\n>> Menu 3:  Temperature Conversion\n");
    int choice;
    double input, output;

    printf("1. Celsius to Kelvin\n");
    printf("2. Kelvin to Celsius\n");
    printf("3. Celsius to Fahrenheit\n");
    printf("4. Fahrenheit to Celsius\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

    printf("Enter temperature: ");
    scanf("%lf", &input);

    switch (choice) {
        case 1: 
            output = c_to_k(input); 
            save_history(input, output, "C", "K"); 
            break;
        case 2: 
            output = k_to_c(input); 
            save_history(input, output, "K", "C"); 
            break;
        case 3: 
            output = c_to_f(input); 
            save_history(input, output, "C", "F"); 
            break;
        case 4: 
            output = f_to_c(input); 
            save_history(input, output, "F", "C"); 
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }

    printf("Result: %.3f\n", output);
}

void menu_item_4(void) {
    printf("\n>> Menu 4: show history\n");
    show_history();
}

double dbm_to_mw(double dbm) {
    /* P(mW) = 10^(P(dBm)/10) */
    return pow(10.0, dbm / 10.0);
}

double mw_to_dbm(double mw) {
    /* P(dBm) = 10 * log10(P(mW)) */
    return 10.0 * log10(mw);
}

/* Hz <-> rad/s */

double hz_to_rad(double hz) {
    /* ω = 2πf */
    return 2.0 * M_PI * hz;
}

double rad_to_hz(double rad) {
    /* f = ω / (2π) */
    return rad / (2.0 * M_PI);
}



double c_to_k(double c) {
    return c + 273.15;
}

double k_to_c(double k) {
    return k - 273.15;
}

double c_to_f(double c) {
    return c * 9.0 / 5.0 + 32.0;
}

double f_to_c(double f) {
    return (f - 32.0) * 5.0 / 9.0;
}


double apply_prefix(double value, char prefix) {
    switch (prefix) {
        case 'G': return value * 1e9;
        case 'M': return value * 1e6;
        case 'k': return value * 1e3;
        case 'm': return value * 1e-3;
        case 'u': return value * 1e-6;  
        case 'n': return value * 1e-9;
        case 'p': return value * 1e-12;
        default:  return value;         
     }
}



void save_history(double input, double output,
                  const char *inUnit, const char *outUnit) {
    FILE *fp = fopen(HISTORY_FILE, "a");
    if (fp == NULL) {
        printf("Error: could not open history file.\n");
        return;
    }

    fprintf(fp, "%.6f %s -> %.6f %s\n", input, inUnit, output, outUnit);

    fclose(fp);
}

void show_history(void) {
    FILE *fp = fopen(HISTORY_FILE, "r");
    if (fp == NULL) {
        printf("No history found.\n");
        return;
    }

    char line[256];
    printf("\nConversion history\n");
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }
    printf("End of history\n");

    fclose(fp);
}
