#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define LIRE_TO_EURO 0.000516457
#define EURO_TO_LIRE 1936.27
#define SILENT_ARGUMENT "-s"

/// @brief Prints the formatted currency.
/// @param value The value to print.
void printf_currency(double value)
{
    // obtain the existing locale name for numbers
    char *oldLocale = setlocale(LC_NUMERIC, NULL);

    // inherit locale from environment
    setlocale(LC_NUMERIC, "");

    // print number
    printf("%'.2f", value);

    // set the locale back
    setlocale(LC_NUMERIC, oldLocale);
}

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf("no arguments found\n");
        return 1;
    }

    double input = atof(argv[1]);
    double result = input * EURO_TO_LIRE;

    printf_currency(result);

    if (argc < 3 || strcmp(argv[2], SILENT_ARGUMENT) != 0)
        printf(" delle vecchie lire");

    return 0;
}
