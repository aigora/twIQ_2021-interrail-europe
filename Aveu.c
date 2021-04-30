#include <stdio.h>
#include<string.h>

int horarioManiana();

int main(){
   
   
	FILE * pfichero1;
	FILE * pfichero2;
   	
    int opcion,i,longitud=0,nbilletes,edad,opcion2,opcion3,hora,salir,j,equipaje,bultos;
    float precio=30,precio2,descuento,peso;
    char name[12],nameOriginal[25],destino,origen[30],destino1[30],precioEquipaje;
   
	do{
    printf("\nMENU");
    printf("\n1. Registro del usuario.");
    printf("\n2. Mostrar todos los recorridos");
    printf("\n3. Compra de billetes de tren de ida y vuelta");
    printf("\n4. Compra de billetes de tren de ida");
    printf("\n5. Ver precio del equipaje.");
    printf("\n6. Salir\n");
    scanf("%d",&opcion);
    switch(opcion){
    case 1:
    	system("cls");
    	do{
   		printf("Introduce un nombre de usuario sin espacios:");
    	scanf("%s",name);
    	longitud=strlen(name);
		}while(longitud>12);
		strcpy(nameOriginal,name);
	
		if(name==nameOriginal){
    	printf("\nNombre de usuario %s incorecto\n",nameOriginal);
    	printf("\nSolo se permite un nombre de usuario con letras, se cambia a %s\n",name);
   	 	printf("\nBienvenid@ %s\n",name);
		}
    else{
	printf("\nBienvenid@ %s, nombre de usuario correcto.\n",name);
	}
	
	break;
	
	case 2:
		system("cls");
		pfichero1=fopen("destinos.txt","r");
    	if(pfichero1==NULL){
    	printf("Error en la apertura del fichero\n");
  		return 0;
		}
		printf("Lista de las ciudades a las que viajar\n");
		while(fscanf(pfichero1,"%c",&destino)!=EOF){
		printf("%c",destino);
		}
		fclose(pfichero1);
		getch();
		break;
	case 3:
		system("cls");
		printf("Introduzca la ciudad de origen:");
		scanf("%s",origen);
		printf("Introduzca el numero de billetes que deseas comprar:");
		scanf("%d",&nbilletes);
		printf("Introduzca el destino:");
		scanf("%s",destino1);
		
		precio2=precio;
		
		for(i=0;i<nbilletes;i++){
		printf("Introduzca la edad del pasajero:");
		scanf("%d",&edad);
		
		if (edad>=0 &&edad <=6){
  		printf("\nSe aplica la Tarifa Baby\n");
  		printf("\nSe aplica un descuento del 50 por ciento\n");
  		descuento=(precio2/nbilletes)*0.5;
  		precio -= descuento;
  	 	printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  		}else if (edad>=6 && edad<=12){
  		printf("\nSe aplica la Tarifa Children\n");
  		printf("\nSe aplica un descuento del 30 por ciento\n");
  		descuento=(precio2/nbilletes)*0.3;
  		precio-= descuento;
  		printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  		}else if(edad>=13 && edad<=60){
  		printf("\nNo se aplican descuentos\n");
  		printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  		}else{
  		printf("\nSe aplica la Tarifa Senior\n");
  		printf("\nSe aplica un descuento del 30 por ciento\n");
  		descuento=(precio2/nbilletes)*0.3;
  		precio -= descuento;
  		printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  		}
	}
	
	for(i=0;i<nbilletes;i++){
	do{
    printf("\nDesea facturar el equipaje  %d? Pulse 1- Si, 2- No\n",i+1);
    scanf("%d",&equipaje);
    }while(equipaje!=1&&equipaje!=2);
    
    if(equipaje==1){
      
      do{
      printf("\nIntroduzca el numero de bultos que desea facturar\n");
      scanf("%d",&bultos);
      
       if(bultos>2){
       printf("\nLe recordamos que no es posible facturar mas de 2 bultos por persona\n");
        }
    }while(bultos>2);
    
        printf("\n Introduzca la informacion de su equipaje\n");
    
      for(j=0;j<bultos;j++){
       printf("Introduzca el peso en kg del bulto %d: ",j+1);
       scanf("%f",&peso);
       if(peso>=5&&peso<9){
       precio+=10; 
        }
       if(peso>=9&&peso<15){
       precio+=20;
        }
       if(peso>=15&&peso<=25){
       precio+=30; 
        }
       printf("\nBillete de ida: %.2f euros actualmente\n",precio);
      if(peso>35)
       printf("\nLo sentimos, el bulto %d no puede ser transpotado por sobrepeso\n",j+1);
      else
      printf("\nEl bulto %d sera transportado\n",j+1);
    
        }
    }else if(equipaje==2){
     printf("\nUsted ha elegido no facturar\n");
    }else{
    printf ("\nError. La opcion no es correcta\n");
    }
    }while(equipaje>=3);

	
	do{
	printf("Introduzca su horario para el tren de la ida\n");
	printf("1-Horario de maniana\n");
 	printf("2-Horario de tarde\n");
 	printf("3-Horario de noche\n");
 
 	scanf("%d",&opcion2);
 	printf("Usted ha elegido la opcion %d\n",opcion2);
	}while(opcion2<1 ||opcion2>3);
	
	break;
	case 4:
		system("cls");
		printf("Introduzca la ciudad de origen:");
		scanf("%s",origen);
		printf("Introduzca el numero de billetes que deseas comprar:");
		scanf("%d",&nbilletes);
		printf("Introduzca el destino:");
		scanf("%s",destino1);
		
		precio2=precio;
		
		for(i=0;i<nbilletes;i++){
		printf("Introduzca la edad del pasajero:");
		scanf("%d",&edad);
		
		if (edad>=0 &&edad <=6){
  		printf("\nSe aplica la Tarifa Baby\n");
  		printf("\nSe aplica un descuento del 50 por ciento\n");
  		descuento=(precio2/nbilletes)*0.5;
  		precio -= descuento;
  	 	printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  		}else if (edad>=6 && edad<=12){
  		printf("\nSe aplica la Tarifa Children\n");
  		printf("\nSe aplica un descuento del 30 por ciento\n");
  		descuento=(precio2/nbilletes)*0.3;
  		precio-= descuento;
  		printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  		}else if(edad>=13 && edad<=60){
  		printf("\nNo se aplican descuentos\n");
  		printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  		}else{
  		printf("\nSe aplica la Tarifa Senior\n");
  		printf("\nSe aplica un descuento del 30 por ciento\n");
  		descuento=(precio2/nbilletes)*0.3;
  		precio -= descuento;
  		printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  		}
	}
	
	for(i=0;i<nbilletes;i++){
	do{
    printf("\nDesea facturar el equipaje  %d? Pulse 1- Si, 2- No\n",i+1);
    scanf("%d",&equipaje);
    }while(equipaje!=1&&equipaje!=2);
    
    if(equipaje==1){
      
      do{
      printf("\nIntroduzca el numero de bultos que desea facturar\n");
      scanf("%d",&bultos);
      
       if(bultos>2){
       printf("\nLe recordamos que no es posible facturar mas de 2 bultos por persona\n");
        }
    }while(bultos>2);
    
         printf("\n Introduzca la informacion de su equipaje\n");
    
      for(j=0;j<bultos;j++){
       printf("Introduzca el peso en kg del bulto %d: ",j+1);
       scanf("%f",&peso);
       if(peso>=5&&peso<9){
       precio+=10; 
        }
       if(peso>=9&&peso<15){
       precio+=20;
        }
       if(peso>=15&&peso<=25){
       precio+=30; 
        }
       printf("\nBillete de ida: %.2f euros actualmente\n",precio);
      if(peso>35)
       printf("\nLo sentimos, el bulto %d no puede ser transpotado por sobrepeso\n",j+1);
      else
      printf("\nEl bulto %d sera transportado\n",j+1);
    
        }
    }else if(equipaje==2){
     printf("\nUsted ha elegido no facturar\n");
    }else{
    printf ("\nError. La opcion no es correcta\n");
    }
    }while(equipaje>=3);
	
	
	do{
	printf("\nIntroduzca su horario para el tren de la ida\n");
	printf("1-Horario de maniana\n");
 	printf("2-Horario de tarde\n");
 	printf("3-Horario de noche\n");
 
 	scanf("%d",&opcion2);
 	printf("Usted ha elegido la opcion %d\n",opcion2);
	}while(opcion2>0 && opcion2<=3);
	break;
	switch(opcion3){
		do{
			case 1:
				printf("Escoja la hora del vuelo de por la manania");
				if(hora==1){
					printf("Has elegido el vuelo de las 7:30 de la manania");
				}
				else if(hora==2){
					printf("Has elegido el vuelo de las 10:30");
				}
				else if(hora==3){
					printf("Has elegido el vuelo de las 12:30");
				}
				break;
		}while(hora>1 && hora<=3);
	}
	case 5:
		system("cls");
		pfichero2=fopen("equipaje.txt","r");
		if(pfichero2==NULL){
			printf("Error en la apertura del fichero");
			return 0;
		}
		
		while(fscanf(pfichero2,"%c",&precioEquipaje)!=EOF){
			printf("%c",precioEquipaje);
		}
		fscanf(pfichero2,"%c",precioEquipaje);
		fclose(pfichero2);

		break;
	system("cls");
	case 6:
		
		printf("1.SI \n");
					printf("2.NO \n");
						do{
							scanf("%i",&salir);	
							if(salir<1 || salir>2){
								printf("Opcion no valida\n");
							}
						}while(salir<1 || salir>2);
							if(salir==1){
								printf(" Hasta pronto.");
								return 0;
							}else{
								system("cls");
							}
     	break;
     	
		default:
     		printf("Opcion no valida");
			 system("cls"); 
	}
	
		
    }while(opcion>0 && opcion<=6);
    return 0;
}
int horarioManiana(){
	int hora;
	printf("1- 7:30");
	printf("2- 10:30 ");
	printf("3- 12:30");
	
}
