#include <stdio.h>
#include "funciones.h"
#include <string.h>

void buscarPorTamano(int *numHabitacion,char habitaciones[][3][40],double precios[]){
    char tipo[40];
    printf("Ingrese el tamaño de habitacion que desea buscar: ");
    scanf("%s",tipo);
    printf("#\t\tTamaño\t\tHotel\t\tPrecio\n");
    for (int i = 0; i < 9; i++)
    {
        if (strcmp(habitaciones[i][1],tipo)==0)
        {
            printf("%s\t\t%s\t\t%s\t\t%lf\n",habitaciones[i][0],habitaciones[i][1],habitaciones[i][2],precios[i]);
        }
    }
    printf("Elija la habitacion que desea reservar: ");
    scanf("%d",numHabitacion); 
}

