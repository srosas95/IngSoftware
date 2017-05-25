#include <cstdlib>
#include <iostream>
#include <string.h>
#include <stdio.h>

#define precio 12

using namespace std;

int coca=0;
int sprite=5;
int fanta=9;
int manzana =0;
int coca_light=2;

int estado=1;
int credito=0;
char producto;

int dinero_permitido(char dinero[3]){ // acepta el dinero, verifica que este sea de los valores permitidos y lleva un resgistro del total
   char dn[6][3]={"1","2","5","10","20","50"};
   
   int x=-1;
   for(int i=0;i<6;i++){
     x=strcmp(dn[i],dinero);      
     if(x==0){	
		credito = credito+ atoi(dinero);
       return x;       
     }    
   }
   return x;   
}

int disponibilidad (char producto){   //Se checa disponibilidad de producto, se usa una bandera para determindad disponibilidad y se resta 1 unidad de la variable global
	int disponible =0;
	switch (producto){
		case '1' : if(coca>0){ disponible=1; coca--;}	
			    break;
		case '2' : if(manzana>0){ disponible=1; manzana--;}				   
			   break;		
		case '3' : if(coca_light>0){ disponible=1; coca_light--;}				   
			   break;
		case '4' : if(sprite>0){ disponible=1; sprite--;}
			   break;		
		case '5' : if(fanta>0){ disponible=1; fanta--;}		   
			   break;						
	}	
	if(disponible==1){
			   cout<<"\nProducto Disponible"<<endl;
			   }
			   else{
				cout<<"\nProducto No Disponible"<<endl;
					system("PAUSE");}
						  
	return disponible;
	
}


int despachar(){  // Da el cambio y despacha el producto
		int cambio;
		cambio=credito-precio; 
		credito=0;
		cout<<"Despachando Producto"<<endl<<endl;
		cout<<"Tu cambio es de:"<<cambio<<endl;
		estado=1;
		
}

int maquina_refrecos(char dinero[3]){ 
  int d;
  int disponible;
  d=dinero_permitido(dinero);
  
  if(d==0){
		if(credito>= precio){
    	estado=2;   }
  }
  else{
    cout<<"Cantidad no valida, ingrese solo cantidades permitidas"<<endl;   
  }
  
  if(estado==2){ // se selecciona el producto y se checa la disponibilidad
		do{
			system("cls");
			cout<<"Elija Producto: \n Coca:1        Manzana:2 \n Coca Light:3  Sprite:4 \n Fanta:5 \n >>Producto Seleccionado:  ";
    		fflush(stdin);
    		producto=getchar();
    		disponible=disponibilidad(producto);  
			if(disponible==1){
				estado=3;
			}
		//	estado=3;
			}while(estado==2);
		
		}
	if (estado==3)	{
			despachar();
	}
  
  return estado;                
}


		

	



int main(int argc, char *argv[])
{
    char dinero[3];
    char producto;
    do{ system("cls");
		cout<<"REFRESCOS VALLES Bienvenido !! "<<endl<<endl;
		cout<<"DINERO PERMITIDO $: 1,2,5,10,20,50:  ";
    	fflush(stdin);
    	gets(dinero);
    	printf("Estado actual %d",maquina_refrecos(dinero));
    	cout<<endl<<"Credito:"<<credito<<"\n\n";
		system("pause");}while(1);

    
    system("PAUSE");
    return EXIT_SUCCESS;
}
