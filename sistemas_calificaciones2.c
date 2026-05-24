#include <stdio.h>
#include <stdlib.h>

#define ASIGNATURAS 3

// Función para ingresar notas con validación
void ingresarNotas(float *notas, int estudiantes) {
    for (int i = 0; i < estudiantes; i++) {
        for (int j = 0; j < ASIGNATURAS; j++) {
            do {
                printf("Ingrese nota del estudiante %d en asignatura %d (0-10): ", i + 1, j + 1);
                scanf("%f", (notas + i * ASIGNATURAS + j));

                if (*(notas + i * ASIGNATURAS + j) < 0 || *(notas + i * ASIGNATURAS + j) > 10) {
                    printf("Nota invalida. Intente nuevamente.\n");
                }
            } while (*(notas + i * ASIGNATURAS + j) < 0 || *(notas + i * ASIGNATURAS + j) > 10);
        }
    }
}