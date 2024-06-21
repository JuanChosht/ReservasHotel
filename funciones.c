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

void buscarHotel(int *numHabitacion, char habitaciones[][3][40], double precios[]) {
    char hotel[40];
    printf("Ingrese el hotel que desea buscar: ");
    scanf("%s", hotel);
    printf("#\t\tTamaño\t\tHotel\t\tPrecio\n");
    for (int i = 0; i < 9; i++) {
        if (strcmp(habitaciones[i][2], hotel) == 0) {
            printf("%s\t\t%s\t\t%s\t\t%lf\n", habitaciones[i][0], habitaciones[i][1], habitaciones[i][2], precios[i]);
        }
    }
    printf("Elija la habitacion que desea reservar: ");
    scanf("%d", numHabitacion);
}

void realizarReserva(int numHabitacion, char habitaciones[][3][40], char clientes[][2][40], int reservas[][4]) {
    int clienteIndex = -1;
    char cedula[40];

    printf("Ingrese su cédula: ");
    scanf("%s", cedula);

    for (int i = 0; i < 5; i++) {
        if (strcmp(clientes[i][1], cedula) == 0) {
            clienteIndex = i;
            break;
        }
    }
    if (clienteIndex == -1) {
        for (int i = 0; i < 5; i++) {
            if (strcmp(clientes[i][1], "") == 0) {
                clienteIndex = i;
                strcpy(clientes[clienteIndex][1], cedula);
                printf("Ingrese su nombre: ");
                scanf("%s", clientes[clienteIndex][0]);
                break;
            }
        }
    }

    if (clienteIndex == -1) {
        printf("No hay espacio para nuevos clientes.\n");
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (reservas[i][0] == -1) {
            reservas[i][0] = clienteIndex;//cliente
            reservas[i][1] = numHabitacion - 1;//habitación
            reservas[i][2] = 0;//estado de la reserva
            printf("Reserva realizada con éxito. Número de reserva: %i\n", i + 1);
            return;
        }
    }
    printf("No hay espacio para nuevas reservas.\n");
}

void buscarReservaPorCedula(int *numReserva, char clientes[][2][40], int reservas[][4]) {
    char cedula[40];
    int clienteIndex = -1;

    printf("Ingrese su cédula: ");
    scanf("%s", cedula);

    for (int i = 0; i < 5; i++) {
        if (strcmp(clientes[i][1], cedula) == 0) {
            clienteIndex = i;
            break;
        }
    }
    if (clienteIndex == -1) {
        printf("Cliente no encontrado.\n");
        *numReserva = -1;
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (reservas[i][0] == clienteIndex) {
            *numReserva = i;
            printf("Reserva encontrada. Número de reserva: %d\n", *numReserva + 1);
            return;
        }
    }
    printf("No se encontraron reservas para la cédula ingresada.\n");
    *numReserva = -1;
}

void imprimirReserva(int numReserva, int reservas[][4], char habitaciones[][3][40], double precios[]) {
    if (numReserva < 0 || numReserva >= 10 || reservas[numReserva][0] == -1) {
        printf("Número de reserva inválido o reserva no encontrada.\n");
        return;
    }

    int clienteIndex = reservas[numReserva][0];
    int habitacionIndex = reservas[numReserva][1];
    int estadoReserva = reservas[numReserva][2];

    printf("Detalles de la Reserva:\n");
    printf("Número de Reserva: %d\n", numReserva + 1);
    printf("Cliente: %d\n", clienteIndex + 1); // Cliente index is 0-based, display as 1-based
    printf("Habitación: %s\n", habitaciones[habitacionIndex][0]);
    printf("Tamaño: %s\n", habitaciones[habitacionIndex][1]);
    printf("Hotel: %s\n", habitaciones[habitacionIndex][2]);
    printf("Precio: %.2lf\n", precios[habitacionIndex]);
    printf("Estado de la Reserva: %s\n", estadoReserva ? "Pagada" : "No Pagada");
}


void pagarReserva(int numReserva, int reservas[][4], char habitaciones[][3][40], double precios[]) {
    if (numReserva < 0 || numReserva >= 10 || reservas[numReserva][0] == -1) {
        printf("Número de reserva inválido o reserva no encontrada.\n");
        return;
    }

    if (reservas[numReserva][2] == 1) {
        printf("La reserva ya ha sido pagada.\n");
        return;
    }

    int habitacionIndex = reservas[numReserva][1];

    printf("Detalles de la Reserva:\n");
    printf("Número de Reserva: %d\n", numReserva + 1);
    printf("Habitación: %s\n", habitaciones[habitacionIndex][0]);
    printf("Tamaño: %s\n", habitaciones[habitacionIndex][1]);
    printf("Hotel: %s\n", habitaciones[habitacionIndex][2]);
    printf("Precio: %.2lf\n", precios[habitacionIndex]);

    char confirmarPago;
    printf("¿Desea confirmar el pago? (s/n): ");
    scanf(" %c", &confirmarPago);

    if (confirmarPago == 's' || confirmarPago == 'S') {
        reservas[numReserva][2] = 1;
        printf("Pago realizado con éxito. La reserva ahora está marcada como pagada.\n");
    } else {
        printf("Pago no realizado.\n");
    }
}