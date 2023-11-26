	//Registro de clientes en el Hotel Realeza

	#include <stdio.h>
	#include <time.h>
	#include <stdlib.h>
	#include <ctype.h>
	#define TOTALC 100
	#define TOTALE 50
	#define CANTC 100
	#define DIAS 5
	#define TOTALP 5
	#define SUITE 350
	#define STANDARD 150
	#define DOBLE 250
											//tipo de habitaciones y sus precios

	typedef struct 
	{
		float extra[DIAS];
		float telf[DIAS];
		float gasto;
	}CONSUMO;

	typedef struct 
	{
		char nombre[50];
		char apellido[50];
		int reserv;
		int est;          //est representa la estancia del cliente
		int formPago;
	    CONSUMO saldo;
	}HUESPED;

	typedef struct 
	{
		 int idD;           //idD es el numero de cuarto
		 float precio;
	}CUARTO;
	
	typedef struct 
	{
		char nomV[50];
		float costV;
		char fecha[10];
		int tipoPago;
	}EVENTO;

	typedef struct
	{
		int id;
		char nomP[50];
		int cantE; //cantidad de producto existente
		float costp; //costo del producto
	} PRODUCTO;
	
     PRODUCTO produc[5]={1,"Jabon",25,90,2,"shampoo",45,120};      //ingreso de producto mediante declaracion;
     
     typedef union 
     {
     	int cant;
     	int opc;
     	char client;
     	char con;
	 }ALMACEN;
	 
	 ALMACEN control;

	//Prototipos de funciones

	void listaRese(HUESPED);
	float precioHab(int);
	int  buscarHab();
	int tipoHab();
	void inven();

	main()
	{
		 HUESPED cliente[CANTC];
		 CUARTO dorm[TOTALC]; //dorm representa a los dormitorios
		 EVENTO even[TOTALE];

		float sum=0,sumTel=0;
		int op,reg,fac=0;;  //reg almacena la opcion de registro de inventario
		int i=0,j=0,d=2;
		float precio;
		long int rut=19062023;
	
		 while(op!=4)
		 {
			 system("cls");

			 printf("\t\t-> Bienvenid%c al Hotel Realeza <- \n\n",64);
			 printf("\t\t M E N U  P R I N C I P A L \n\n");
			 printf("\t 1.Registro de clientes \n");
			 printf("\t 2.Lista de productos \n");
			 printf("\t 3.Eventos \n");
			 printf("\t 4.Salir \n");
			 printf("\t Opcion:");
			 scanf("%d",&op);

			 system("cls");

			 switch(op)
			 {
					case 1:printf("\n \t\t-----------Registro De Clientes------\n\n");
								 printf("\t 1.Entrada \n");
								 printf("\t 2.Salida \n");
								 printf("\t 0.Salir \n");
								 printf("\t Opcion:");
								 scanf("%d",&control.opc);

								 system("cls");

								 switch(control.opc)
								 {
									 case 1:printf("\n\t\t -----------------Entrada-------\n\n");
													do
													{
														system("cls");

														printf("\n Nombre del Cliente:");
														fflush(stdin);
														gets(cliente[i].nombre);
														printf("\n Apellidos del Cliente:");
														fflush(stdin);
														gets(cliente[i].apellido);
														printf("\n Tiempo de Estadia:");
														scanf("%d",&cliente[i].est);
														printf("\n Forma de pago: \n\t 1.Tarjeta de credito  \n\t 2.Efectivo \n Opcion");
														scanf("%d",&cliente[i].formPago);
														printf("\n Reservacion: \n\t 1.Si \n\t 2.No \n Opcion:");
														scanf("%d",&cliente[i].reserv);

														system("cls");

														control.cant=tipoHab();
														precio=precioHab(control.cant);
														
														system("cls");

														if(cliente[i].reserv==1)
														{
															printf("\n \t\t -> Reservacion <- \n");
															listaRese(cliente[i]);
															printf("\n\t Precio de la Habitacion: %.2f \n",precio);
														}
														if(cliente[i].reserv==2)
														 {
															 dorm[i].idD=buscarHab();

															 if(dorm[i].idD!=-1)
															 {
																 printf("\n Habitacion asignada: %d",dorm[i].idD);
																 printf("\n Precio de la Habitacion: %.2f \n",precio);
															 }
															 else
																	printf("\n Habitaciones no disponibles");
														 }

														printf("\n Desea registrar a otro cliente (s/n) \n\n");
														fflush(stdin);
														scanf("%c",&control.client);
														control.client=toupper(control.client);
														if(control.client== 'S')
														{
															i++;
															continue;
														}
													}while(control.client=='S');
													break;

									 case 2:printf("\t\t --------- Salida ----- \n\n");
													do
													{
														system("cls");
														
														printf("\n Digite el nombre del cliente:");
														fflush(stdin);
														gets(cliente[i].nombre);
														printf("\n Digite el apellido del cliente:");
														gets(cliente[i].apellido);
														printf("\n Digite el numero de habitacion:");
														scanf("%d",&dorm[i].idD);
														printf("\n Digite la cantidad de dias de estancia:");
														scanf("%d",&cliente[i].est);

                                                        
														for(j=0;j<=cliente[i].est-1;j++)
														{
															printf("\n Ingrese los consumido por dia %d:",j+1);
															fflush(stdin);
															scanf(" %f",&cliente[i].saldo.extra[j]);
															printf("\n Ingrese gastos telefonicos por dia %d:",j+1);
															scanf(" %f",&cliente[i].saldo.telf[j]);
															sum+=cliente[i].saldo.extra[j];
															sumTel+=cliente[i].saldo.telf[j];
														}
														system("cls");
														
														control.cant=tipoHab();
													    dorm[i].precio=precioHab(control.cant);

														cliente[i].saldo.gasto+=sum+sumTel+(dorm[i].precio*cliente[i].est);
														while(fac<=0 || fac>2)
														{
															printf("\n Desea 1.Boleta 2.Factura \n");
															scanf("%d",&fac);
														}

														printf("\n Salida de Cliente registrada con exito \n");
														system("cls");

														if(fac==1)
															printf("\n \t\t --> Boleta <-- \n");

														printf("\n \t\t >>> Hotel Realeza <<< \n");

														if(fac==2)
														 {
															 printf("\n \t\t --> Factura <-- \n");
															 printf("\t Rut: %lu \n",rut);
														 }

														printf("\t Nombre: %s \n",cliente[i].nombre);
														printf("\t Apellido: %s \n",cliente[i].apellido);
														printf("\t Estadia: %d \n",cliente[i].est);
														printf("\t Gasto Telefonico: %.2f \n",sumTel);
														printf("\t Consumo: %.2f \n",sum);
														printf("\t Costo total del cuarto: %.2f \n",(dorm[i].precio*cliente[i].est));
														printf("\t Total a pagar: %.2f \n\n",cliente[i].saldo.gasto);
														printf("\t Gracias por Hospedarse en el Hotel Realeza \n\n");

														printf("Desea registrar la salida de otro cliente: (s/n) \n");
														fflush(stdin);
														scanf("%c",&control.con);
														i++;
													}while(control.con=='s');
													break;

									 case 0:exit(1);
													 break;
									 default:printf("\n ERROR %d no corresponde a ninguna opcion",control.opc);
													 break;
									}
								 break;
					case 2:printf("\t\t \n --> Bienvenido al inventario del Hotel Realeza <-- \n");
					             reg=0;
								 printf("\t 1.Regitrar producto  \n");
								 printf("\t 2.Ver productos existentes \n");
								 fflush(stdin);
								 while(reg<=0 || reg>2)
								 {
									 printf("\t opcion:");
									 scanf("%d",&reg);
								 }

								 if(reg==1)
									{
										do
										{
											printf("\n Inserte el codigo del producto:");
											scanf("%d",&produc[d].id);
											printf("\n Inserte nombre:");
											fflush(stdin);
											gets(produc[d].nomP);
											printf("\n Inserte la cantidad:");
											scanf("%d",&produc[d].cantE);
											printf("\n Inserte el costo por unidad:");
											scanf("%d",&produc[d].costp);

											printf("\n Desea ingresar otro producto (s/n): ");
											fflush(stdin);
											scanf("%c",&control.con);
											d++;
										}while(control.con=='s');
									}
								 if(reg==2)
									inven();
								 break;
					case 3:
								 do
								 {
								 	 system("cls");
								 	 
									 printf("\t\t --> Evento <-- \n");
									 printf("\n Inserte el nombre del evento:");
									 fflush(stdin);
									 gets(even[i].nomV);
									 printf("\n Inserte el costo del evento:");
									 fflush(stdin);
									 scanf(" %f",&even[i].costV);
									 printf("\n Inserte la fecha en la que se llevo a cabo dd/mm/aa:");
									 fflush(stdin);
									 gets(even[i].fecha);
									 printf("\n tipo de pago: \n 1.Efectivo \n 2.Tajeta \n");
									 scanf(" %d",&even[i].tipoPago);
									 while(fac<=0 || fac>2)
									 {
										 printf("\n Desea 1.Factura o 2.boleta:");
										 scanf("%d",&fac);
									 }
                                      
                                    system ("cls");
                                    
									  if(fac==2)
										 printf("\n \t\t --- Boleta --- \n \n");
									 printf("\n \t\t >>> Hotel Realeza <<<  \n");

									 if(fac==1)
										{
										 printf("\n \t\t --- Factura --- \n \n");
										 printf("\n RUT: %lu",rut);
										}
										
									 printf("\n Nombre: %s \n",even[i].nomV);
									 printf("\n Total a pagar %.2f \n",even[i].costV);
									 printf("\n Fecha: %s \n",even[i].fecha);
									 printf("\n Deseas facturar otro evento: (s/n)");
									 fflush(stdin);
									 scanf("%c",&control.con);
									 i++;
								 }while(control.con=='s');
								 break;
					default: printf("\n Saliendo del programa \n");
									 break;
			}
		}
		 system("pause");
		 return 0;
	}
	//Permite seleccionar el tipo de habitacion

	int tipoHab()
	{
		 int resp=0;

		 printf("\n \t\t -> Tipo de Habitaciones<- \n");
		 printf("\t 1.Estandar \n");
		 printf("\t 2.Doble \n");
		 printf("\t 3.Suite \n");
		 while(resp<=0 || resp>3)
		 {
			 printf("\t Respuesta:");
			 scanf("%d",&resp);
		 }

		 return resp;
	}

	//calcula el precio por habitacion

	float precioHab (int tip) //recibe a cant
	{
		 float costo=0,des;
		 int res=0,pers=0;       //Representa la cantidad de personas

		 while(pers<=0)
		 {
			 printf("\n Ingrese cantidad de personas:");
			 fflush(stdin);
			 scanf("%d",&pers);
		 }
		 while(res<=0 || res>2)
		 {
			 printf("\n Fecha de registro \n\t1.Dia de la semana \n\t2.Fin de semana \nOpcion:");
			 scanf("%d",&res);
		 }

		 if(pers>5 || res==2)
			 des=0.20;
		 else
			 des=0;
		 if(tip==1)
				costo=STANDARD-(STANDARD*des);
			 if(tip==2)
				 costo=DOBLE-(DOBLE*des);
				 if(tip==3)
					 costo=SUITE-(SUITE*des);

		 return costo;

	}
	//permite buscar y asignar una habitacion

	int buscarHab()
	{
		int cuar;

		srand(time(0));
		cuar=(rand()%100)+1;

		return cuar;
	}

	//Muestra las reservaciones

	void listaRese(HUESPED h1)
	{
		time_t fecha;        //asigna variable de fecha
		time(&fecha);

		printf("\t Nombre: %s \n",h1.nombre);
		printf("\t Apellido %s \n",h1.apellido);
		printf("\t Estadia: %d \n",h1.est);
		printf("\t Fecha: %s \n",ctime(&fecha));
		printf("\t Habitacion: %d \n",buscarHab());

		return;
	}

	//Muestra el inventario
	void inven()
	{   
		int c;

		for(c=0;c<=TOTALP-1;c++)
		{
			printf("\n\t ID: %d",produc[c].id);
			printf("\n\t Nombre: %s",produc[c].nomP);
			printf("\n\t Cantidad: %d",produc[c].cantE);
			printf("\n\t Costo: %.2f",produc[c].costp);
			printf("\n");
		}
		system("pause");
	}
