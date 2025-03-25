#include <stdio.h>

// Funciones de conversión
float convertir_a_dolares(float cantidad, char moneda);
float convertir_a_euros(float cantidad, char moneda);
float convertir_a_quetzales(float cantidad, char moneda);
void imprimir_moneda(char moneda);

int main() {
    int opcion;
    float cantidad, resultado;
    char moneda_origen;

    printf("Conversor de Monedas\n");
    printf("Seleccione la moneda de origen (Q=Quetzales, $=Dolares, €=Euros): ");
    scanf(" %c", &moneda_origen); // Espacio antes de %c para manejar el salto de línea

    printf("Ingrese la cantidad que desea convertir: ");
    scanf("%f", &cantidad);

    printf("Seleccione la moneda de destino:\n");
    printf("1. Convertir a Dolares\n");
    printf("2. Convertir a Euros\n");
    printf("3. Convertir a Quetzales\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    // Realizar la conversión según la opción seleccionada
    switch(opcion) {
        case 1:
            resultado = convertir_a_dolares(cantidad, moneda_origen);
            printf("%.2f ", cantidad);
            imprimir_moneda(moneda_origen);
            printf(" son %.2f Dolares.\n", resultado);
            break;
        case 2:
            resultado = convertir_a_euros(cantidad, moneda_origen);
            printf("%.2f ", cantidad);
            imprimir_moneda(moneda_origen);
            printf(" son %.2f Euros.\n", resultado);
            break;
        case 3:
            resultado = convertir_a_quetzales(cantidad, moneda_origen);
            printf("%.2f ", cantidad);
            imprimir_moneda(moneda_origen);
            printf(" son %.2f Quetzales.\n", resultado);
            break;
        default:
            printf("Opción inválida.\n");
    }

    return 0;
}

// Función que imprime el nombre completo de la moneda
void imprimir_moneda(char moneda) {
    if (moneda == 'Q' || moneda == 'q') {
        printf("Quetzales");
    } else if (moneda == '$') {
        printf("Dolares");
    } else if (moneda == '€') {
        printf("Euros");
    } else {
        printf("Moneda desconocida");
    }
}

// Funciones de conversión
float convertir_a_dolares(float cantidad, char moneda) {
    if (moneda == 'Q' || moneda == 'q') {
        return cantidad / 7.7; // 1 Q = 7.7 USD (aproximado)
    } else if (moneda == '€' || moneda == 'e') {
        return cantidad / 0.91; // 1 EUR = 0.91 USD (aproximado)
    } else {
        return cantidad; // Si la moneda es $ (dólares)
    }
}

float convertir_a_euros(float cantidad, char moneda) {
    if (moneda == 'Q' || moneda == 'q') {
        return cantidad / 8.5; // 1 Q = 8.5 EUR (aproximado)
    } else if (moneda == '$') {
        return cantidad * 0.91; // 1 USD = 0.91 EUR (aproximado)
    } else {
        return cantidad; // Si la moneda es € (euros)
    }
}

float convertir_a_quetzales(float cantidad, char moneda) {
    if (moneda == '$') {
        return cantidad * 7.7; // 1 USD = 7.7 Q (aproximado)
    } else if (moneda == '€') {
        return cantidad * 8.5; // 1 EUR = 8.5 Q (aproximado)
    } else {
        return cantidad; // Si la moneda es Q (quetzales)
    }
}
