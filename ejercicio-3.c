#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main()
{
    char *buff;
    char *vector;

    for (int i = 0; i < 5; i++)
    {
        buff = (char *) malloc(100*sizeof(char));
        printf("Ingrese un nombre: ");
        gets(buff);

        vector= (char *) malloc((strlen(buff)+1)*sizeof(char));
        strcpy(vector,buff);

        printf("%s",vector);

        

        

    }
    
    
    
    
    return 0;
}