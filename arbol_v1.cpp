#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
class nodo {
	//dESDE OTRA CLASE SE PUEDEN acceder a estos atributos
   public:
    nodo(int v, nodo *izq, nodo *der ,nodo *padre)
    {
       valor = v;
       izquierda = izq;
       derecha = der;
       padre=padre;
    }
    //Desde otra clase/funcion no de puede acceder a los atributos o metodos privados.
   private:
    int valor;
    nodo *izquierda;
    nodo *derecha;
    nodo *padre;

   //Una funcion externa puede acceder a los atributos privados.
   friend class lista;
};

//PROTOTIPOS
void menu();
void mostrar();
nodo *crearnodo(int,nodo *,nodo *, nodo *);


nodo *arbol = NULL; //incializa el arbol en NULL
nodo *arbol2 = NULL; //incializa el arbol en NULL
nodo *arbol3 = NULL;

typedef nodo *pnodo;

class lista {
   public:
   	void insertarnodo(nodo *&, int, nodo * );
   	void mostrararbol(nodo *); //funcion para mostrar el arbol con recursividad
   	void mostrararbol2(nodo *); //FUNCIOIN PARA RECCORER EL arbol con while
   private:
    pnodo primero;
    pnodo actual;
};

void mostar(){
	
}

int main() {
	menu();
   system("pause");
   return 0;
}

void menu(){
	int opcion=0,val=0,contador=0;
	do {
		system("cls");
		cout<<"--------------ARBOLES---------------------"	<<endl;
		cout<<"1. Insertar un nodo"<<endl;
		cout<<"2. listar nodos usando while"<<endl;
		cout<<"3. listar nodos usando recursividad"<<endl;
		cout<<"4. salir"<<endl<<endl;
		cout<<"ingrese una opcion: ";
		cin>>opcion;
			switch(opcion){
				case 1:
						system("cls");
						cout<<"--------INGRESANDO UN NODO--------"<<endl;
						cout<<"ingrese el valor del nodo Raiz: ";
						cin>>val;
						lista Lista;
						Lista.insertarnodo(arbol,val,NULL);
						system("pause");
						break;
				case 3: 
						system("cls");
						cout<<"--------MOSTRANDO EL ARBOL RECURSIVO--------"<<endl;
						lista Lista2;
						Lista2.mostrararbol(arbol);
						system("pause");
						break;
				case 2: 
						system("cls");
						cout<<"--------MOSTRANDO EL ARBOL usando while--------"<<endl;
						lista Lista6;
						Lista6.mostrararbol2(arbol);
						system("pause");
						break;
			}	
	}while(opcion != 4);
}

//funcion para crear nodos nuevos
nodo *crearnodo(int n,nodo *padre){
     nodo *nuevo_nodo= new nodo(n,NULL,NULL,padre);
     return nuevo_nodo;
}

//funcion para insertar nodos en el arbol
void lista::insertarnodo(nodo *&arbol, int n, nodo *padre){
     if(arbol==NULL)
     {		//si el arbol esta vacio
            nodo *nuevo_nodo=crearnodo(n,padre);
            arbol=nuevo_nodo;
     }else //si el arbol tiene al menos un nodo
     {	
	 	if(arbol->izquierda==NULL && arbol->derecha==NULL)
		 {	
	 		//aca preguntamos si quiere ingresar un valor en el nodo izquierdo, derecho o en los dos 
  			cout<<"------------Seleccione una opcion: ---------"<<endl<<endl;
  			cout<<"1. Ingresar nodos a la izquiera "<<endl;
  			cout<<"2. Ingresar nodos a la derecha "<<endl;
  			cout<<"3. Ingresar nodos a la izquierda y derecha "<<endl;
  			int selec=0; cin>>selec;
  			switch(selec){
  				case 1: //ingresamos el valor al nodo izquierdo
  						insertarnodo(arbol->izquierda,n,arbol);
  						break;
  				case 2://ingresamos el valor al nodo derecho
  						insertarnodo(arbol->derecha,n,arbol);
  						break;
  				case 3://ingresamos el valor al nodo izquierdo y derecho  						
				  		insertarnodo(arbol->izquierda,n,arbol);
  						insertarnodo(arbol->derecha,n,arbol);
  						break;
			  }//fin del switch			 
     	}
     		else if (arbol->izquierda!=NULL && arbol->derecha!=NULL)
     		{//aca validamos si el nodo izquierdo y derecho tienen valores, entonces escogemos en cual de los dos nodos le vamos a ingresar valores de los subnodos
	  			cout<<"------------Seleccione una opcion: ---------"<<endl<<endl;
	  			cout<<"1. Ingresar nodos a la izquiera "<<endl;
	  			cout<<"2. Ingresar nodos a la derecha "<<endl;	  			
	  			int selec=0; cin>>selec;
	  			switch(selec){
	  				case 1: //ingresamos el valor al nodo izquierdo
	  						insertarnodo(arbol->izquierda,n,arbol);
	  						break;
	  				case 2://ingresamos el valor al nodo derecho
	  						insertarnodo(arbol->derecha,n,arbol);
	  						break;
				 }//fin del switch			 
     			
     		}
		     	else if (arbol->izquierda!=NULL && arbol->derecha==NULL)
		     	{//aca validamos si el nodo izquierdo tiene valor y el nodo derecho no tiene, entonces ingresamos el valor directo al nodo derecho	 		
		  			cout<<"EL NODO IZQUIERDO YA TIENE VALOR"<<endl;
		  			cout<<"Ingresar nodos a la derecha "<<endl;
		  			insertarnodo(arbol->derecha,n,arbol);     		
		     	}
			     	else if(arbol->izquierda==NULL && arbol->derecha!=NULL)
			     	{//aca validamos si el nodo izquiero no tiene valor y el nodo derecho si tiene, entonces ingresamos el valor directo al nodo izquierdo
			  			cout<<"Ingresar nodos a la izquierda "<<endl;
			  			insertarnodo(arbol->izquierda,n,arbol);     		
			     	}     		
    }
}

//funcion para buscar un nodo por su valor dentro del arbol


//funcon para mostrar el arbol con recursividad
void lista::mostrararbol(nodo *arbol){
     if(arbol== NULL)
     {
                return ;
     }
     else
     {	
     	
        cout<<"codigo_nodo: "<<arbol<<" , valor: "<<arbol->valor<<" ,nodo izq: "<<arbol->izquierda<<" ,nodo der"<<arbol->derecha<<endl;
		mostrararbol(arbol->izquierda);
		mostrararbol(arbol->derecha);
     }
}

//funcon para mostrar el arbol USANDO ITERACIONES
void lista::mostrararbol2(nodo *arbol){
     if(arbol== NULL)
     {
                return ; //SI no encuentra nodos retorno sin hacer nada
     }
     else
     {
 			if(arbol->derecha != NULL){
 				arbol3=arbol->derecha;
			 }
 			
     	
     do{ //imprime el subarbol izquierdo
     		cout<<"codigo_nodo: "<<arbol<<" , valor: "<<arbol->valor<<" , nodo izq: "<<arbol->izquierda<<" ,nodo der: "<<arbol->derecha<<endl;
     		if(arbol3 != arbol->derecha){
			 
			 if(arbol->derecha != NULL){
     			arbol2=arbol->derecha;
     			cout<<"codigo_nodo: "<<arbol2<<" , valor: "<<arbol2->valor<<" , nodo izq: "<<arbol2->izquierda<<" ,nodo der: "<<arbol2->derecha<<endl;
			}
			 }
     		arbol=arbol->izquierda;
		 }while(arbol!= NULL);
		 
		//imprime el sub arbol derecho		 
		//cout<<"puntero a iniciar en el segundo while: "<<arbol3<<endl;
		//system("pause");
		//	arbol3=arbol3->izquierda;
			
		 while(arbol3 != NULL){
		 	
			cout<<"codigo_nodo: "<<arbol3<<" , valor: "<<arbol3->valor<<" , nodo izq: "<<arbol3->izquierda<<" ,nodo der: "<<arbol3->derecha<<endl;     		
     		if(arbol3->derecha != NULL){
     			arbol2=arbol3->derecha;
     			cout<<"codigo_nodo: "<<arbol2<<" , valor: "<<arbol2->valor<<" , nodo izq: "<<arbol2->izquierda<<" ,nodo der: "<<arbol2->derecha<<endl;
			 }
     		
     		arbol3=arbol3->izquierda;
     		
		 }
		 cout<<"ya salio de todo"<<endl;
		 system("pause");
     }
}
