#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char film_code[10];
    int copies;
    int year;
} film;

film* appropriateFilm(char* fileName, int copies_limit, int last_year, int* size) {
    int i = 0;
    FILE* fp = fopen(fileName, "rb");
    film *approp_film_units, unit;
    *size = 0;
    if (!fp) return NULL;
    fread(&unit, sizeof(film), 1, fp);
    while (!feof(fp)) {
        if (unit.copies <= copies_limit && unit.year <= last_year) {
            (*size)++;
        }
        fread(&unit, sizeof(film), 1, fp);
    }

    if (*size == 0) {
        fclose(fp);
        return NULL;
    }

    approp_film_units = (film*)calloc(*size, sizeof(film));
    rewind(fp);
    fread(&unit, sizeof(film), 1, fp);
    while (!feof(fp)) {
        if (unit.copies <= copies_limit && unit.year <= last_year) {
            approp_film_units[i++] = unit;
        }
        fread(&unit, sizeof(film), 1, fp);
    }

    fclose(fp);
    return approp_film_units;
}