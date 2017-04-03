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
   	void buscar(int , nodo *);
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
		cout<<"4. buscar un nodo por su valor"<<endl;
		cout<<"5. salir"<<endl<<endl;
		cout<<"ingrese una opcion: ";
		cin>>opcion;
			switch(opcion){
				case 1:
						system("cls");
						cout<<"--------INGESANDO UN NODO--------"<<endl;
						cout<<"ingrese el valor del nodo: ";
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
				case 4:
						system("cls");
						cout<<"-------BUSAR UN NODO POR SU VALOR--------------------"<<endl<<endl;
						int valor_buscado=0;
						cout<<"ingrese el valor buscado: "; cin>>valor_buscado;
						lista Lista3;
						Lista6.buscar(valor_buscado,arbol);
						break;
			}	
	}while(opcion != 5);
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
     {		//aca debemos preguntar a que lado del unico nodo que tiene va insertar, si a  la izq, o la derecha
  			cout<<"------------Seleccione una opcion: ---------"<<endl<<endl;
  			cout<<"1. ingresar nodos a la izquiera "<<endl;
  			cout<<"2. ingresar nodos a la derecha "<<endl;
  			int selec=0; cin>>selec;
  			switch(selec){
  				case 1: 
  						insertarnodo(arbol->izquierda,n,arbol);
  						break;
  				case 2:
  						insertarnodo(arbol->derecha,n,arbol);
  						break;
			  }
     }
}

//funcion para buscar un nodo por su valor dentro del arbol
void lista::buscar(int v, nodo *arbol){
	//verificamos qu el arbol no este vacio
	if(arbol == NULL){
			return ;
	}else{ //si no esta vacio
				if(arbol->derecha != NULL){
 				arbol3=arbol->derecha;
			 	}
			 	
			do{ //imprime el subarbol izquierdo
				if(arbol->valor == v){
	     		cout<<"codigo_nodo: "<<arbol<<" , valor: "<<arbol->valor<<" , Codigo_izq: "<<arbol->izquierda; //imprime una parte del contenido
				 if(arbol->izquierda == NULL){ //verificamos si los nodos hijos estan vacios
				 	cout<<" , valor_izq: nodo vacio"<<endl;
				 }else{
				 	cout<<" , valor_izq: "<<arbol->izquierda->valor<<endl;
				}
				//ahora el hijo derecho
				if(arbol->derecha == NULL){
					cout<<"Codigo_der: "<<arbol->derecha<<" , valor_der: El nodo derecho esta vacio"<<endl;
				}else{
					cout<<"Codigo_der: "<<arbol->derecha<<" , valor_der: "<<arbol->derecha->valor<<endl;
				}
	     		system("pause");
	     		}
	     		
	     		if(arbol3 != arbol->derecha){
				 
				 if(arbol->derecha != NULL){
	     			arbol2=arbol->derecha;
		     			if(arbol2->valor == v){
		     			cout<<"codigo_nodo: "<<arbol2<<" , valor: "<<arbol2->valor<<" , nodo izq: "<<arbol2->izquierda;
						if(arbol2->izquierda == NULL){
							cout<<" , nodo_izq: nodo vacio"<<endl;
						}else{
							cout<<" , valor_izq: "<<arbol2->izquierda->valor<<endl;
						}
						//ahora el nodo hijo derecho
						if(arbol2->derecha == NULL){
							cout<<"Codigo_der: "<<arbol->derecha<<" , valor_der: nodo vacio"<<endl;
						}else{
							cout<<"Codigo_der: "<<arbol->derecha<<" , valor_der: "<<arbol->derecha->valor;
						}
		     			system("pause");
		     			}
				}
				 }
	     		arbol=arbol->izquierda;
		 }while(arbol!= NULL);
			 	//ahora recorremos el subarbol derecho
		 while(arbol3 != NULL){
			if(arbol3->valor == v){
			cout<<"codigo_nodo: "<<arbol3<<" , valor: "<<arbol3->valor<<" , Codigo izq: "<<arbol3->izquierda;
			if(arbol3->izquierda == NULL){
				cout<<" , Valor_izq: nodo vacio"<<endl;
			}else{
				cout<<" , Valor_izq: "<<arbol3->izquierda->valor<<endl;
			}
			//ahora verificamos el nodo hijo derecho
			if(arbol3->derecha == NULL){
				cout<<"Codigo_der: "<<arbol3->derecha<<" , Valor_der: nodo vacio"<<endl;
			}else{
				cout<<"Codigo_der: "<<arbol3->derecha<<" ,valor_der: "<<arbol3->derecha->valor<<endl;
			}
			system("pause");     		
			}
			
     		if(arbol3->derecha != NULL){
     			arbol2=arbol3->derecha;
	     			if(arbol2->valor == v){
	     			cout<<"codigo_nodo: "<<arbol2<<" , valor: "<<arbol2->valor<<" , nodo izq: "<<arbol2->izquierda;
	     			if(arbol2->izquierda == NULL){
	     				cout<<"valor_izq: Nodo vacio"<<endl;
					 }else{
					 	cout<<"valor_izq: "<<arbol2->izquierda->valor<<endl;
					 }
					 //ahora por la derecha
					 if(arbol2->derecha == NULL){
					 	cout<<"Codigo_der: "<<arbol2->derecha<<" , Valor_der: Nodo vacio"<<endl;
					 }else{
					 	cout<<"Codigo_der: "<<arbol2->derecha<<" , Valor_der: "<<arbol2->derecha->valor<<endl;
					 }
	     			system("pause");
	     			}
			 }
     		
     		arbol3=arbol3->izquierda;
     		
		 }	 	
		   
		}
	}
	



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

//muestra el arbol usando while 
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
		
     }
}
