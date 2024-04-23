#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

int main()
{
    char *buff[MAX];
    char *vector[5];

    for (int i = 0; i < 5; i++) {
        printf("Ingrese el nombre %d: ", i + 1);
        scanf("%s", buff);
        vector[i] = (char *)malloc(strlen(buff) + 1);  
        strcpy(vector[i], buff); 
    }
    
    
    printf("\nNombres ingresados:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d: %s\n", i + 1, vector[i]);
    }
    
   
    for (int i = 0; i < 5; i++) {
        free(vector[i]);
    }
    
    return 0;
}