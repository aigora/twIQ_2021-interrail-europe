#include <stdio.h>
#include<string.h>

int horarioManiana();
int horarioTarde();
int horarioNoche();
float precioBilletes(int ciudad,int nbilletes);

struct TPersona{
	char nombre[50];
	char apellido[60];
	int telefono;
};
int main(){
   
   
	FILE * pfichero1;  //para destinos
	FILE * pfichero2;
   	FILE * pfichero3; //datos de pasajeros
   	
   	struct TPersona pasajero[8];
   	
    int opcion,i,longitud=0,nbilletes,edad,opcion2,opcion3,hora,salir,j,equipaje,bultos;
    int dia,mes,anio,ciudad,pais,anio2,mes2,dia2,asiento,pago,tarjeta;
	int cvc,numeroTarjeta,mesCaducidad,anioCaducidad,telefono;
    float precio,precio2,descuento,peso,precioVuelta;
    char name[12],nameOriginal[25],destino,origen[30],precioEquipaje;
   	char titular[50],apellidosTitular[50],contrasena[20],contrasena1[20];
   
	do{
    printf("\n\t\t\tMENU");
    printf("\n1. Mostrar todos los recorridos");
    printf("\n2. Compra de billetes de tren de ida y vuelta");
    printf("\n3. Compra de billetes de tren de ida");
    printf("\n4. Ver precio del equipaje.");
    printf("\n5. Salir\n");
    scanf("%d",&opcion);
    switch(opcion){
	case 1:
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
	case 2:
		system("cls");
    	do{
   		printf("Introduce un nombre de usuario sin espacios:");
    	scanf("%s",name);
    	longitud=strlen(name);
		}while(longitud>12);

		strcpy(nameOriginal,name);
		if(eliminarCaracteres(name)==1){
    	printf("\nNombre de usuario %s incorecto\n",nameOriginal);
    	printf("\nSolo se permite un nombre de usuario con letras, se cambia a %s\n",name);
   	 	printf("\nBienvenid@ %s\n",name);
		}
    	else{
		printf("\nBienvenid@ %s, nombre de usuario correcto.\n",name);
		}
		
		do{
		printf("Introduzca el numero de billetes que deseas comprar:");
		scanf("%d",&nbilletes);
		if(nbilletes>7){
			printf("No se pueden comprar mas de 6 billetes en una misma compra.\n");
		}
		}while(nbilletes>7);
	
		pfichero1=fopen("destinos.txt","r");
		 if(pfichero1==NULL) {
  		printf("Error en la apertura del fichero\n");
  		return 0;
   		 }
 		printf("\nLista de las ciudades a las que puedes viajar\n");
		while (fscanf(pfichero1, "%c", &destino) != EOF) {
  		printf("%c",destino);
  		}
 		fclose(pfichero1);
		
		do{
    	 printf("\nIntroduzca un numero que corresponda a un pais de la lista anterior: ");
     	scanf("%d",&ciudad);
     	precio+=precioBilletes(ciudad,nbilletes);
   		printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  		 } while(ciudad<1 || ciudad>20);
		
		pfichero3=fopen("datos.txt","a");
		if(ciudad==1){
		fprintf(pfichero3, "DESTINO: Barcelona, Espania\n");	
		}
		else if(ciudad==2){
		fprintf(pfichero3,"DESTINO: Madrid, Espania\n");
		}
		else if(ciudad==3){
		fprintf(pfichero3,"DESTINO: Valencia, Espania\n");
		}
		else if(ciudad==4){
		fprintf(pfichero3,"DESTINO: Sevilla, Espania\n");
		}
		else if(ciudad==5){
		fprintf(pfichero3,"DESTINO: Zaragoza, Espania\n");
		}
		else if(ciudad==6){
		fprintf(pfichero3,"DESTINO: Malaga, Espania\n");
		}
		else if(ciudad==7){
		fprintf(pfichero3,"DESTINO: Paris, Paris\n");
		}
		else if(ciudad==8){
		fprintf(pfichero3,"DESTINO: Lyon, Paris\n");
		}
		else if(ciudad==9){
		fprintf(pfichero3,"DESTINO: Bruselas, Belgica\n");
		}
		else if(ciudad==10){
		fprintf(pfichero3,"DESTINO: Milan, Italia\n");
		}
		else if(ciudad==11){
		fprintf(pfichero3,"DESTINO: Roma, Italia\n");
		}
		else if(ciudad==12){
		fprintf(pfichero3,"DESTINO: Florencia, Italia\n");
		}
		else if(ciudad==13){
		fprintf(pfichero3,"DESTINO: Berlin, Alemania\n");
		}
		else if(ciudad==14){
		fprintf(pfichero3,"DESTINO: Frankurt, Alemania\n");
		}
		else if(ciudad==15){
		fprintf(pfichero3,"DESTINO: Colonia, Alemania\n");
		}
		else if(ciudad==16){
		fprintf(pfichero3,"DESTINO: Amsterdam, Paises Bajos\n");
		}
		else if(ciudad==17){
		fprintf(pfichero3,"DESTINO: Londres, Reino Unido\n");
		}
		else if(ciudad==18){
		fprintf(pfichero3,"DESTINO: Oslo, Noruega\n");
		}
		else if(ciudad==19){
		fprintf(pfichero3,"DESTINO: Varsovia, Polonia\n");
		}
		else if(ciudad==20){
		fprintf(pfichero3,"DESTINO: Zagreb, Croacia\n");
		}
		fclose(pfichero3);
		
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
       if(peso<5){
       	printf("El precio del equipaje es gratis");
	   }
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
      if(peso>26)
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
	}while(opcion2<0 || opcion2>4);
	
	switch(opcion2){
		do{
			case 1:printf("Escoja su tren de por la maniana");
			hora=horarioManiana();
			if(hora==1){
				precio+=(5*nbilletes);
				printf("Usted has elegido el tren de las 7:30 de la maniana.\n");
				printf("El suplemento de esta hora es de 5 euros\n");
				printf("Precio del billete actualmente %.2f\n.",precio);
			}
			else if(hora==2){
				printf("Usted has elegido el tren de las 10:30 de la maniana\n");
				printf("El suplemento de esta hora es de 5 euros\n");
				precio+=(5*nbilletes);
				printf("Precio del billete actualmente %.2f\n",precio);
			}
			else if(hora==3){
				printf("Usted has elegido el tren de las 12:30 de la maniana\n");
				printf("El suplemento de esta hora es de 8 euros\n");
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
			printf("El suplemento de esta hora es de 5 euros\n");
			printf("Precio del billete actualmente %.2f\n.",precio);	
		}
		else if(hora==2){
				printf("Usted has elegido el tren de las 17:15 de la tarde.\n");
				printf("El suplemento de esta hora es de 10 euros\n");
				precio+=(10*nbilletes);
				printf("Precio del billete actualmente %.2f\n",precio);
			}
			else if(hora==3){
				printf("Usted has elegido el tren de las 19:15 de la tarde.\n");
				printf("El suplemento de esta hora es de 10 euros\n");
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
		hora=horarioNoche();
		if(hora==1){
			precio+=(10*nbilletes);
			printf("Usted has elegido el tren de las 11:30 de la noche.\n");
			printf("El suplemento de esta hora es de 10 euros\n");
			printf("Precio del billete actualmente %.2f\n.",precio);	
		}
		else if(hora==2){
				printf("Usted has elegido el tren de las 2:30 de la noche.\n");
				printf("El suplemento de esta hora es de 15 euros\n");
				precio+=(15*nbilletes);
				printf("Precio del billete actualmente %.2f\n",precio);
			}
			else if(hora==3){
				printf("Usted has elegido el tren de las 4:30 de la noche.\n");
				printf("El suplemento de esta hora es de 15 euros\n");
				precio+=(15*nbilletes);
				printf("Precio del billete actualmente %.2f\n",precio);
			}
			else{
				printf("\nOpcion no disponible.");
			}
		}while(hora<0 || hora>3);
		break;
	}
	
	for(i=0;i<nbilletes;i++){
	printf("\n Seleccione el tipo de asiento para la ida:",i+1);
	printf("\n1-Turista");
	printf("\n2-Turista plus\n");
	scanf("%d",&asiento);
	if(asiento==1){
	precio+=30;
	printf("El asiento en turista supone un suplemento de 30 euros");
	printf("\nBillete de vuelta:%.2f euros\n",precio);
	}
	else if(asiento==2){
	precio+=60;
	printf("El asiento en turista plus supone un suplemento de 60 euros");
	printf("\nBillete de vuelta:%.2f euros\n",precio);
	}
}

	do{
  	printf("\nFecha de ida dd mm aaaa\n");
  	scanf("%d %d %d",&dia, &mes, &anio);
  	if(anio<2020){
  	printf("\nFecha introducida incorrecta\n");
  }
  }while(anio<2020);
	
	
//TREN DE REGRESO
printf("\nTREN DE REGRESO\n");
	do{
  	printf("\nFecha de vuelta dd mm aaaa\n");
  	scanf("%d %d %d",&dia2, &mes2, &anio2);
  	if(anio2<2020){                                        
  	printf("\nFecha introducida incorrecta\n");
  }
  }while(anio2<2020 || anio2>2022);
  
  pfichero3=fopen("datos.txt","a");
  fprintf(pfichero3,"\nBILLETE/S DE IDA\n");
  fprintf(pfichero3,"FECHA DE IDA: %d %d %d\n",dia,mes,anio);
  fprintf(pfichero3,"\nBILLETE/S DE VUELTA\n");
  fprintf(pfichero3,"FECHA DE VUELTA: %d %d %d\n",dia2,mes2,anio2);
  fclose(pfichero3);


	
	do{
	printf("\nIntroduzca su horario para el tren de la vuelta\n");
	printf("1-Horario de maniana\n");
 	printf("2-Horario de tarde\n");
 	printf("3-Horario de noche\n");
 
 	scanf("%d",&opcion2);
 	printf("Usted ha elegido la opcion %d\n",opcion2);
	}while(opcion2<0 || opcion2>4);
	
	switch(opcion2){
		do{
			case 1:printf("Escoja su tren de por la maniana");
			hora=horarioManiana();
			if(hora==1){
				precioVuelta+=(5*nbilletes);
				printf("Usted has elegido el tren de las 7:30 de la maniana.\n");
				printf("El suplemento de esta hora es de 5 euros\n");
				printf("Precio del billete actualmente %.2f\n.",precioVuelta);
			}
			else if(hora==2){
				printf("Usted has elegido el tren de las 10:30 de la maniana\n");
				printf("El suplemento de esta hora es de 5 euros\n");
				precioVuelta+=(5*nbilletes);
				printf("Precio del billete actualmente %.2f\n",precioVuelta);
			}
			else if(hora==3){
				printf("Usted has elegido el tren de las 12:30 de la maniana\n");
				printf("El suplemento de esta hora es de 8 euros\n");
				precioVuelta+=(8*nbilletes);
				printf("Precio del billete actualmente %.2f\n",precioVuelta);
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
			precioVuelta+=(5*nbilletes);
			printf("Usted has elegido el tren de las 15:30 de la tarde.\n");
			printf("El suplemento de esta hora es de 5 euros\n");
			printf("Precio del billete actualmente %.2f\n.",precioVuelta);	
		}
		else if(hora==2){
				printf("Usted has elegido el tren de las 17:15 de la tarde.\n");
				printf("El suplemento de esta hora es de 10 euros\n");
				precioVuelta+=(10*nbilletes);
				printf("Precio del billete actualmente %.2f\n",precioVuelta);
			}
			else if(hora==3){
				printf("Usted has elegido el tren de las 19:15 de la tarde.\n");
				printf("El suplemento de esta hora es de 10 euros\n");
				precioVuelta+=(10*nbilletes);
				printf("Precio del billete actualmente %.2f\n",precioVuelta);
			}
			else{
				printf("\nOpcion no disponible.");
			}
		}while(hora<0 || hora>3);
		break;
		
		do{
		case 3:printf("Escoja su tren de por la noche.\n");
		hora=horarioNoche();
		if(hora==1){
			precioVuelta+=(10*nbilletes);
			printf("Usted has elegido el tren de las 11:30 de la noche.\n");
			printf("El suplemento de esta hora es de 10 euros\n");
			printf("Precio del billete actualmente %.2f\n.",precioVuelta);	
		}
		else if(hora==2){
				printf("Usted has elegido el tren de las 2:30 de la noche.\n");
				printf("El suplemento de esta hora es de 15 euros\n");
				precioVuelta+=(15*nbilletes);
				printf("Precio del billete actualmente %.2f\n",precioVuelta);
			}
			else if(hora==3){
				printf("Usted has elegido el tren de las 5:30 de la noche.\n");
				printf("El suplemento de esta hora es de 15 euros\n");
				precioVuelta+=(15*nbilletes);
				printf("Precio del billete actualmente %.2f\n",precioVuelta);
			}
			else{
				printf("\nOpcion no disponible.");
			}
		}while(hora<0 || hora>3);
		break;
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
       precioVuelta+=10; 
        }
       if(peso>=9&&peso<15){
       precioVuelta+=20;
        }
       if(peso>=15&&peso<=25){
       precioVuelta+=30; 
        }
       printf("\nBillete de ida: %.2f euros actualmente\n",precioVuelta);
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

for(i=0;i<nbilletes;i++){
	printf("\n Seleccione el tipo de asiento para la vuelta\n",i+1);
	printf("1-Turista\n");
	printf("2-Turista plus\n");
	scanf("%d",&asiento);
	if(asiento==1){
	precioVuelta+=30;
	printf("El asiento en turista supone un suplemento de 30 euros");
	printf("\nBillete de vuelta:%.2f euros",precioVuelta);
	}
	else if(asiento==2){
	precioVuelta+=60;
	printf("\nEl asiento en turista plus supone un suplemento de 50 euros");
	printf("\nBillete de vuelta:%.2f euros\n\n",precioVuelta);
	}
}

 //RESUMEN COMPRA
printf("\n\n\t\t RESUMEN DE SU COMPRA");
printf("\n Billete/s de ida: %.2f euros",precio);
printf("\n Billete/s de vuelta: %.2f euros",precioVuelta);
printf("\n El precio total es : %.2f",precio+precioVuelta);
 
 
printf("\n\n \t\t DATOS\n");
for(j=0;j<nbilletes;j++){
	printf("Introduzca el nombre del pasajero:\n",j+1);
	scanf("%s",pasajero[j].nombre);
	fflush(stdin);
	
	printf("Introduzca el apellido:\n",j+1);
	gets(pasajero[j].apellido);
	fflush(stdin);
	
	printf("Introduzca el telefono:\n",j+1);
	scanf("%d",&pasajero[j].telefono);
	fflush(stdin);
}

pfichero3=fopen("datos.txt","a");
if (pfichero3 == NULL) {
    printf("\nNo se ha podido crear el fichero\n");
    return 0;
 }
 fprintf(pfichero3,"DATOS\n");
 for(j=0;j<nbilletes;j++){
 	fprintf(pfichero3,"%s %s",pasajero[j].nombre,pasajero[j].apellido);
 }
fclose(pfichero3);

do{
	printf("\nSeleccione el metodo de pago:\n");
	printf("1-Tarjeta de credito\n");
	printf("2- Paypal\n");
	scanf("%d",&pago);
}while(pago<1 || pago>2);

if(pago==1){
	printf("Seleccione el tipo de tarjeta:\n");
	do{
	printf("1-Visa\n");
	printf("2-MasterCard\n");
	scanf("%d",&tarjeta);	
	}while(tarjeta<1 || tarjeta>2);
	
	if(tarjeta==1){
	printf("Pago con tarjeta Visa\n");
	}
	else if(tarjeta==2){
	printf("Pago con Master Card\n");	
	}
	else {
		printf("Opcion no disponible");
	}
	
	printf("Introduzca los siguientes datos a continuacion.");
	printf("\nNombre del titular de la tarjeta:");
	scanf("%s",titular);
	fflush(stdin);
	printf("\nIntroduzca los apellidos del titular de la tarjeta:");
	gets(apellidosTitular);
	fflush(stdin);
	printf("Introduzca el numero de la tarjeta:\n");
	scanf("%d",&numeroTarjeta);
	fflush(stdin);	
	printf("\nIntroduzca el CVC:");
	scanf("%d",&cvc);
	fflush(stdin);
	printf("\nFecha de la caducidad de la tarjeta:\n");
	scanf("%d %d", &mesCaducidad, &anioCaducidad);
	
	printf("Se ha realizado correctamente el pago\n");
	printf("El cargo es %.2f euros",precio+precioVuelta);
}
	if(pago==2){
		printf("Se procede al pago con PayPal\n");
		printf("Introduzca el numero de telefono:\n");
		scanf("%d",&telefono);
		do{
			printf("\nIntroduzca su clave:");
			scanf("%s",contrasena);
			fflush(stdin);
			printf("\nVuelva a introducir su clave:");
			scanf("%s",contrasena1);
			fflush(stdin);
			if(strcmp(contrasena,contrasena1)==0){
				printf("\nSe ha realizado correctamente el pago.");
				printf("\nEl cargo es de %.2f euros.",precio);
			}
			else{
				printf("\nLas contrasenas no coinciden.");
			}
			
		}while(strcmp(contrasena,contrasena1)!=0);		
	}
	break;
	case 3: // SOLO PARA IDA
		system("cls");
    	do{
   		printf("Introduce un nombre de usuario sin espacios:");
    	scanf("%s",name);
    	longitud=strlen(name);
		}while(longitud>12);

		strcpy(nameOriginal,name);
		if(eliminarCaracteres(name)==1){
    	printf("\nNombre de usuario %s incorecto\n",nameOriginal);
    	printf("\nSolo se permite un nombre de usuario con letras, se cambia a %s\n",name);
   	 	printf("\nBienvenid@ %s\n",name);
		}
    	else{
		printf("\nBienvenid@ %s, nombre de usuario correcto.\n",name);
		}
		
		
		do{
		system("cls");
		printf("Introduzca el numero de billetes que deseas comprar:");
		scanf("%d",&nbilletes);
		if(nbilletes>7){
			printf("No se pueden comprar mas de 6 billetes en una misma compra.\n");
		}
		}while(nbilletes>7);
		
		pfichero1=fopen("destinos.txt","r");
		 if(pfichero1==NULL) {
  		printf("Error en la apertura del fichero\n");
  		return 0;
   		 }
 		printf("\nLista de las ciudades a las que puedes viajar\n");
		while (fscanf(pfichero1, "%c", &destino) != EOF) {
  		printf("%c",destino);
  		}
 		fclose(pfichero1);
		
		do{
    	 printf("\nIntroduzca un numero que corresponda a un pais de la lista anterior: ");
     	scanf("%d",&ciudad);
     	precio+=precioBilletes(ciudad,nbilletes);
   		printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  		 } while(ciudad<1 || ciudad>20);
		
		pfichero3=fopen("datos.txt","a");
		if(ciudad==1){
		fprintf(pfichero3, "DESTINO: Barcelona, Espania\n");	
		}
		else if(ciudad==2){
		fprintf(pfichero3,"DESTINO: Madrid, Espania\n");
		}
		else if(ciudad==3){
		fprintf(pfichero3,"DESTINO: Valencia, Espania\n");
		}
		else if(ciudad==4){
		fprintf(pfichero3,"DESTINO: Sevilla, Espania\n");
		}
		else if(ciudad==5){
		fprintf(pfichero3,"DESTINO: Zaragoza, Espania\n");
		}
		else if(ciudad==6){
		fprintf(pfichero3,"DESTINO: Malaga, Espania\n");
		}
		else if(ciudad==7){
		fprintf(pfichero3,"DESTINO: Paris, Paris\n");
		}
		else if(ciudad==8){
		fprintf(pfichero3,"DESTINO: Lyon, Paris\n");
		}
		else if(ciudad==9){
		fprintf(pfichero3,"DESTINO: Bruselas, Belgica\n");
		}
		else if(ciudad==10){
		fprintf(pfichero3,"DESTINO: Milan, Italia\n");
		}
		else if(ciudad==11){
		fprintf(pfichero3,"DESTINO: Roma, Italia\n");
		}
		else if(ciudad==12){
		fprintf(pfichero3,"DESTINO: Florencia, Italia\n");
		}
		else if(ciudad==13){
		fprintf(pfichero3,"DESTINO: Berlin, Alemania\n");
		}
		else if(ciudad==14){
		fprintf(pfichero3,"DESTINO: Frankurt, Alemania\n");
		}
		else if(ciudad==15){
		fprintf(pfichero3,"DESTINO: Colonia, Alemania\n");
		}
		else if(ciudad==16){
		fprintf(pfichero3,"DESTINO: Amsterdam, Paises Bajos\n");
		}
		else if(ciudad==17){
		fprintf(pfichero3,"DESTINO: Londres, Reino Unido\n");
		}
		else if(ciudad==18){
		fprintf(pfichero3,"DESTINO: Oslo, Noruega\n");
		}
		else if(ciudad==19){
		fprintf(pfichero3,"DESTINO: Varsovia, Polonia\n");
		}
		else if(ciudad==20){
		fprintf(pfichero3,"DESTINO: Zagreb, Croacia\n");
		}
		fclose(pfichero3);
		
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
       if(peso<5){
       	printf("El precio del equipaje es gratis");
	   }
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
      if(peso>26)
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
	}while(opcion2<0 || opcion2>=3);
	
	switch(opcion2){
		do{
			case 1:printf("Escoja su tren de por la maniana");
			hora=horarioManiana();
			if(hora==1){
				precio+=(5*nbilletes);
				printf("Usted has elegido el tren de las 7:30 de la maniana.\n");
				printf("El suplemento de esta hora es de 5 euros\n");
				printf("Precio del billete actualmente %.2f\n.",precio);
			}
			else if(hora==2){
				printf("Usted has elegido el tren de las 10:30 de la maniana");
				printf("El suplemento de esta hora es de 5 euros\n");
				precio+=(5*nbilletes);
				printf("Precio del billete actualmente %.2f\n",precio);
			}
			else if(hora==3){
				printf("Usted has elegido el tren de las 12:30 de la maniana");
				printf("El suplemento de esta hora es de 8 euros\n");
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
			printf("El suplemento de esta hora es de 5 euros\n");
			printf("Precio del billete actualmente %.2f\n.",precio);	
		}
		else if(hora==2){
				printf("Usted has elegido el tren de las 17:15 de la tarde.\n");
				printf("El suplemento de esta hora es de 10 euros\n");
				precio+=(10*nbilletes);
				printf("Precio del billete actualmente %.2f\n",precio);
			}
			else if(hora==3){
				printf("Usted has elegido el tren de las 19:15 de la tarde.\n");
				printf("El suplemento de esta hora es de 10 euros\n");
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
		hora=horarioNoche();
		if(hora==1){
			precio+=(10*nbilletes);
			printf("Usted has elegido el tren de las 11:30 de la noche.\n");
			printf("El suplemento de esta hora es de 10 euros\n");
			printf("Precio del billete actualmente %.2f\n.",precio);	
		}
		else if(hora==2){
				printf("Usted has elegido el tren de las 2:30 de la noche.\n");
				printf("El suplemento de esta hora es de 15 euros\n");
				precio+=(15*nbilletes);
				printf("Precio del billete actualmente %.2f\n",precio);
			}
			else if(hora==3){
				printf("Usted has elegido el tren de las 5:30 de la noche.\n");
				printf("El suplemento de esta hora es de 15 euros\n");
				precio+=(15*nbilletes);
				printf("Precio del billete actualmente %.2f\n",precio);
			}
			else{
				printf("\nOpcion no disponible.");
			}
		}while(hora<0 || hora>3);
		break;
	}
	
	for(i=0;i<nbilletes;i++){
	printf("\n Seleccione el tipo de asiento para la ida",i+1);
	printf("\n1-Turista\n");
	printf("\n2-Turista plus\n");
	scanf("%d",&asiento);
	if(asiento==1){
	precio+=30;
	printf("El asiento en turista supone un suplemento de 30 euros\n");
	printf("\nBillete de vuelta:%.2f euros",precio);
	}
	else if(asiento==2){
	precio+=60;
	printf("El asiento en turista plus supone un suplemento de 60 euros\n");
	printf("\nBillete de vuelta:%.2f euros",precio);
	}
}
	do{
  	printf("\nFecha de ida dd mm aaaa\n");
  	scanf("%d %d %d",&dia, &mes, &anio);
  	if(anio<2019){
  	printf("\nFecha introducida incorrecta\n");
  	}
  	}while(anio<2020);
  	
  	
  	//RESUMEN COMPRA
	printf("\n\n\t RESUMEN DE SU COMPRA");
	printf("\n Billete/s de ida: %.2f euros",precio);
	printf("\n El precio total es : %.2f",precio);
	
	
	printf("\n\n \t\t DATOS\n");
for(j=0;j<nbilletes;j++){
	printf("Introduzca el nombre del pasajero:\n",j+1);
	scanf("%s",pasajero[j].nombre);
	fflush(stdin);
	
	printf("Introduzca el apellido:\n",j+1);
	gets(pasajero[j].apellido);
	fflush(stdin);
	
	printf("Introduzca el telefono:\n",j+1);
	scanf("%d",&pasajero[j].telefono);
	fflush(stdin);
}

pfichero3=fopen("datos.txt","a");
if (pfichero3 == NULL) {
    printf("\nNo se ha podido crear el fichero\n");
    return 0;
 }
 fprintf(pfichero3,"DATOS\n");
 for(j=0;j<nbilletes;j++){
 	fprintf(pfichero3,"%s %s",pasajero[j].nombre,pasajero[j].apellido);
 }
fclose(pfichero3);

do{
	printf("\nSeleccione el metodo de pago:\n");
	printf("1-Tarjeta de credito\n");
	printf("2- Paypal\n");
	scanf("%d",&pago);
}while(pago<1 || pago>2);

if(pago==1){
	printf("Seleccione el tipo de tarjeta:\n");
	do{
	printf("1-Visa\n");
	printf("2-MasterCard\n");
	scanf("%d",&tarjeta);	
	}while(tarjeta<1 || tarjeta>2);
	
	if(tarjeta==1){
	printf("Pago con tarjeta Visa\n");
	}
	else if(tarjeta==2){
	printf("Pago con Master Card\n");	
	}
	else {
		printf("Opcion no disponible");
	}
	
	printf("Introduzca los siguientes datos a continuacion.");
	printf("\nNombre del titular de la tarjeta:");
	scanf("%s",titular);
	fflush(stdin);
	printf("\nIntroduzca los apellidos del titular de la tarjeta:");
	gets(apellidosTitular);
	fflush(stdin);
	printf("Introduzca el numero de la tarjeta:\n");
	scanf("%d",&numeroTarjeta);
	fflush(stdin);	
	printf("\nIntroduzca el CVC:");
	scanf("%d",&cvc);
	fflush(stdin);
	printf("\nFecha de la caducidad de la tarjeta:\n");
	scanf("%d %d", &mesCaducidad, &anioCaducidad);
	
	printf("Se ha realizado correctamente el pago");
	printf("\nEl cargo es %.2f euros",precio);
}
	if(pago==2){
		printf("Se procede al pago con PayPal\n");
		printf("Introduzca el numero de telefono:\n");
		scanf("%d",&telefono);
		do{
			printf("\nIntroduzca su clave:");
			scanf("%s",contrasena);
			fflush(stdin);
			printf("\nVuelva a introducir su clave:");
			scanf("%s",contrasena1);
			fflush(stdin);
			if(strcmp(contrasena,contrasena1)==0){
				printf("\nSe ha realizado correctamente el pago.");
				printf("\nEl cargo es de %.2f euros.",precio);
			}
			else{
				printf("\nLas contrasenas no coinciden.");
			}
			
		}while(strcmp(contrasena,contrasena1)!=0);		
	}


	break;
	
	case 4:
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
	case 5:
		system("cls");
		printf("Esta usted seguro que desea salir de la aplicacion?\n");
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
	printf("1- 12:30\n");
	printf("2- 2:30\n");
	printf("3- 4:30\n");
	scanf("%d",&hora);
	return hora;
}
float precioBilletes(int ciudad,int nbilletes){
	float coste;
	
	if(ciudad>=1 && ciudad<=10){
		coste+=(30*nbilletes);
		printf("\nEl viaje tiene un precio de 30 euros por persona.\n");
	}
	else if(ciudad>10 && ciudad<=20){
		coste+=(40*nbilletes);
		printf("\nEl viaje tiene un precio de 40 euros por persona.\n");
	}
	return coste;
}
int eliminarCaracteres(char str[]){
	int i,j,resultado=0;
	
	for(i=0;str[i]!='\0';i++){
		if((str[i]<65 || str[i>90])&&(str[i]<97 || str[i]>122)&&str[i]!='\0'){
			resultado=1;
		for(j=i;str[j]!='\0';j++){
			str[j]=str[j+1];
			}
			i--;
		}
	}
	return resultado;
}



