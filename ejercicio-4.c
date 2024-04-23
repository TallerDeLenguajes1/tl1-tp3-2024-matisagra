#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definición de las estructuras de datos
char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

struct Producto {
    int ProductoID;
    int Cantidad;
    char *TipoProducto;
    float PrecioUnitario;
};

struct Cliente {
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    struct Producto *Productos;
    float TotalPagar;
};


int generarAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}


float calcularCostoTotal(struct Producto producto) {
    return producto.Cantidad * producto.PrecioUnitario;
}

int main() {
    int cantidadClientes;

    
    srand(time(NULL));

 
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantidadClientes);


    struct Cliente *clientes = (struct Cliente *)malloc(cantidadClientes * sizeof(struct Cliente));

   
    for (int i = 0; i < cantidadClientes; i++) {
        printf("\nCliente %d:\n", i + 1);
        printf("Ingrese el ID del cliente: ");
        scanf("%d", &clientes[i].ClienteID);

        
        clientes[i].CantidadProductosAPedir = generarAleatorio(1, 5);

        
        clientes[i].Productos = (struct Producto *)malloc(clientes[i].CantidadProductosAPedir * sizeof(struct Producto));

    
     

       
        printf("Productos para el cliente %d:\n", clientes[i].ClienteID);
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            clientes[i].Productos[j].Cantidad = generarAleatorio(1, 10);
            clientes[i].Productos[j].TipoProducto = TiposProductos[generarAleatorio(0, 4)];
            clientes[i].Productos[j].PrecioUnitario = generarAleatorio(10, 100);

            
            float costoTotal = calcularCostoTotal(clientes[i].Productos[j]);
            clientes[i].TotalPagar += costoTotal;

            
            printf("  Producto %d:\n", clientes[i].Productos[j].ProductoID);
            printf("    Cantidad: %d\n", clientes[i].Productos[j].Cantidad);
            printf("    Tipo: %s\n", clientes[i].Productos[j].TipoProducto);
            printf("    Precio unitario: %.2f\n", clientes[i].Productos[j].PrecioUnitario);
            printf("    Costo total: %.2f\n", costoTotal);
        }
        printf("Total a pagar para el cliente %d: %.2f\n", clientes[i].ClienteID, clientes[i].TotalPagar);
    }

    
    for (int i = 0; i < cantidadClientes; i++) {
        free(clientes[i].Productos);
    }
    free(clientes);

    return 0;
}