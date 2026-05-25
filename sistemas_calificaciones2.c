#include <stdio.h>
#include <stdlib.h>

#define ASIGNATURAS 3

void ingresarNotas(float *notas, int estudiantes) {

    for (int i = 0; i < estudiantes; i++) {

        for (int j = 0; j < ASIGNATURAS; j++) {

            do {

                printf("Ingrese nota del estudiante %d en asignatura %d (0-10): ",
                       i + 1, j + 1);

                scanf("%f", (notas + i * ASIGNATURAS + j));

                if (*(notas + i * ASIGNATURAS + j) < 0 ||
                    *(notas + i * ASIGNATURAS + j) > 10) {

                    printf("Nota invalida. Intente nuevamente.\n");
                }

            } while (*(notas + i * ASIGNATURAS + j) < 0 ||
                     *(notas + i * ASIGNATURAS + j) > 10);
        }
    }
}

void promedioEstudiantes(float *notas, int estudiantes) {

    for (int i = 0; i < estudiantes; i++) {

        float suma = 0;

        for (int j = 0; j < ASIGNATURAS; j++) {
            suma += *(notas + i * ASIGNATURAS + j);
        }

        printf("Promedio estudiante %d: %.2f\n",
               i + 1, suma / ASIGNATURAS);
    }
}

int main() {

    int estudiantes;

    printf("Ingrese numero de estudiantes: ");
    scanf("%d", &estudiantes);

    float *notas = (float *)malloc(estudiantes * ASIGNATURAS * sizeof(float));

    ingresarNotas(notas, estudiantes);

    promedioEstudiantes(notas, estudiantes);

    free(notas);

    return 0;
}