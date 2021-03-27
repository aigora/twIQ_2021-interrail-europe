#include <stdio.h>


int main(){
   
    int opc;
    
   
    printf("\n\nMENU");
    printf("\n\n1. Registro del usuario.");
    printf("\n2. Mostrar todos los recorridos");
    printf("\n3. Compra de billetes de tren.");
    printf("\n4. Salir");
    do
    {
        printf("\n\nOpcion: ");
        scanf("%d",&opc);
        if(opc<=0||opc>4)
            printf("\nIntroducir opcion entre 1 y 4\n");
    }while(opc<=0||opc>4);
    
    return opc;
}
