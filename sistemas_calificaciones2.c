#include <stdio.h>
#include <stdlib.h>

#define ASIGNATURAS 3

// Función para ingresar notas con validación
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

// Promedio por estudiante
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

// Promedio por asignatura
void promedioAsignaturas(float *notas, int estudiantes) {

    for (int j = 0; j < ASIGNATURAS; j++) {

        float suma = 0;

        for (int i = 0; i < estudiantes; i++) {
            suma += *(notas + i * ASIGNATURAS + j);
        }

        printf("Promedio asignatura %d: %.2f\n",
               j + 1, suma / estudiantes);
    }
}

// Máximos y mínimos por asignatura
void maxMinAsignaturas(float *notas, int estudiantes) {

    for (int j = 0; j < ASIGNATURAS; j++) {

        float max = *(notas + j);
        float min = *(notas + j);

        for (int i = 0; i < estudiantes; i++) {

            float valor = *(notas + i * ASIGNATURAS + j);

            if (valor > max)
                max = valor;

            if (valor < min)
                min = valor;
        }

        printf("Asignatura %d -> Max: %.2f | Min: %.2f\n",
               j + 1, max, min);
    }
}

// Máximos y mínimos por estudiante
void maxMinEstudiantes(float *notas, int estudiantes) {

    for (int i = 0; i < estudiantes; i++) {

        float max = *(notas + i * ASIGNATURAS + 0);
        float min = *(notas + i * ASIGNATURAS + 0);

        for (int j = 0; j < ASIGNATURAS; j++) {

            float valor = *(notas + i * ASIGNATURAS + j);

            if (valor > max)
                max = valor;

            if (valor < min)
                min = valor;
        }

        printf("Estudiante %d -> Max: %.2f | Min: %.2f\n",
               i + 1, max, min);
    }
}

int main() {

    int estudiantes;

    printf("Ingrese numero de estudiantes: ");
    scanf("%d", &estudiantes);

    float *notas = (float *)malloc(estudiantes * ASIGNATURAS * sizeof(float));

    ingresarNotas(notas, estudiantes);

    promedioEstudiantes(notas, estudiantes);

    promedioAsignaturas(notas, estudiantes);

    maxMinAsignaturas(notas, estudiantes);

    maxMinEstudiantes(notas, estudiantes);

    free(notas);

    return 0;
}
