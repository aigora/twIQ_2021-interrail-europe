#include <stdio.h>
#include<string.h>

int horarioManiana();
int horarioTarde();
int horarioNoche();

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
		do{
		printf("Introduzca el numero de billetes que deseas comprar:");
		scanf("%d",&nbilletes);
		if(nbilletes>7){
			printf("No se pueden comprar mas de 6 billetes en una misma compra.\n");
		}
	}while(nbilletes>7);
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
	}while(opcion2<0 || opcion2>3);
	
	switch(opcion2){
		do{
			case 1:printf("Escoja su tren de por la maniana");
			hora=horarioManiana();
			if(hora==1){
				precio+=(5*nbilletes);
				printf("Usted has elegido el tren de las 7:30 de la maniana.\n");
				printf("Precio del billete actualmente %.2f\n.",precio);
			}
			else if(hora==2){
				printf("Usted has elegido el tren de las 10:30 de la maniana");
				precio+=(5*nbilletes);
				printf("Precio del billete actualmente %.2f\n",precio);
			}
			else if(hora==3){
				printf("Usted has elegido el tren de las 12:30 de la maniana");
				precio+=(8*nbilletes);
				printf("Precio del billete actualmente %.2f\n",precio);
			}
			else{
				printf("\nOpcion no disponible.");
			}
			
		}while(hora<0 || hora>3);
		break;
		
		do{
		case 2:printf("Escoja su tren de por la tarde");
		hora=horarioTarde();
		if(hora==1){
			precio+=(5*nbilletes);
			printf("Usted has elegido el tren de las 15:30 de la tarde.\n");
			printf("Precio del billete actualmente %.2f\n.",precio);	
		}
		else if(hora==2){
				printf("Usted has elegido el tren de las 17:15 de la tarde.\n");
				precio+=(10*nbilletes);
				printf("Precio del billete actualmente %.2f\n",precio);
			}
			else if(hora==3){
				printf("Usted has elegido el tren de las 19:15 de la tarde.\n");
				precio+=(10*nbilletes);
				printf("Precio del billete actualmente %.2f\n",precio);
			}
			else{
				printf("\nOpcion no disponible.");
			}
		}while(hora<0 || hora>3);
		break;
		
		do{
		case 3:printf("Escoja su tren de por la noche.\n");
		hora=horarioTarde();
		if(hora==1){
			precio+=(10*nbilletes);
			printf("Usted has elegido el tren de las 11:30 de la noche.\n");
			printf("Precio del billete actualmente %.2f\n.",precio);	
		}
		else if(hora==2){
				printf("Usted has elegido el tren de las 2:30 de la noche.\n");
				precio+=(15*nbilletes);
				printf("Precio del billete actualmente %.2f\n",precio);
			}
			else if(hora==3){
				printf("Usted has elegido el tren de las 5:30 de la noche.\n");
				precio+=(15*nbilletes);
				printf("Precio del billete actualmente %.2f\n",precio);
			}
			else{
				printf("\nOpcion no disponible.");
			}
		}while(hora<0 || hora>3);
		break;
	}
	
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
	}while(opcion2<0 || opcion2>3);
	
	switch(opcion2){
		do{
			case 1:printf("Escoja su tren de por la maniana");
			hora=horarioManiana();
			if(hora==1){
				precio+=(5*nbilletes);
				printf("Usted has elegido el tren de las 7:30 de la maniana.\n");
				printf("Precio del billete actualmente %.2f\n.",precio);
			}
			else if(hora==2){
				printf("Usted has elegido el tren de las 10:30 de la maniana");
				precio+=(5*nbilletes);
				printf("Precio del billete actualmente %.2f\n",precio);
			}
			else if(hora==3){
				printf("Usted has elegido el tren de las 12:30 de la maniana");
				precio+=(8*nbilletes);
				printf("Precio del billete actualmente %.2f\n",precio);
			}
			else{
				printf("\nOpcion no disponible.");
			}
			
		}while(hora<0 || hora>3);
		break;
		
		do{
		case 2:printf("Escoja su tren de por la tarde");
		hora=horarioTarde();
		if(hora==1){
			precio+=(5*nbilletes);
			printf("Usted has elegido el tren de las 15:30 de la tarde.\n");
			printf("Precio del billete actualmente %.2f\n.",precio);	
		}
		else if(hora==2){
				printf("Usted has elegido el tren de las 17:15 de la tarde.\n");
				precio+=(10*nbilletes);
				printf("Precio del billete actualmente %.2f\n",precio);
			}
			else if(hora==3){
				printf("Usted has elegido el tren de las 19:15 de la tarde.\n");
				precio+=(10*nbilletes);
				printf("Precio del billete actualmente %.2f\n",precio);
			}
			else{
				printf("\nOpcion no disponible.");
			}
		}while(hora<0 || hora>3);
		break;
		
		do{
		case 3:printf("Escoja su tren de por la noche.\n");
		hora=horarioTarde();
		if(hora==1){
			precio+=(10*nbilletes);
			printf("Usted has elegido el tren de las 11:30 de la noche.\n");
			printf("Precio del billete actualmente %.2f\n.",precio);	
		}
		else if(hora==2){
				printf("Usted has elegido el tren de las 2:30 de la noche.\n");
				precio+=(15*nbilletes);
				printf("Precio del billete actualmente %.2f\n",precio);
			}
			else if(hora==3){
				printf("Usted has elegido el tren de las 5:30 de la noche.\n");
				precio+=(15*nbilletes);
				printf("Precio del billete actualmente %.2f\n",precio);
			}
			else{
				printf("\nOpcion no disponible.");
			}
		}while(hora<0 || hora>3);
		break;
	}
	break;
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
	printf("\n1- 7:30\n");
	printf("2- 10:30\n");
	printf("3- 12:30\n");
	scanf("%d",&hora);
	return hora;
}
int horarioTarde(){
	int hora;
	printf("\n1- 15:30\n");
	printf("2- 17:15\n");
	printf("3- 19:15\n");
	scanf("%d",&hora);
	return hora;
}
int horarioNoche(){
	int hora;
	printf("\n1- 11:30\n");
	printf("2- 2:30\n");
	printf("3- 5:30\n");
	scanf("%d",&hora);
	return hora;
}
