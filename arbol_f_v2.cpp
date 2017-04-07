#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
class nodo {
		//dESDE OTRA CLASE SE PUEDEN acceder a estos atributos
   public:
    nodo(int v, nodo *izq, nodo *der)
    {
       valor = v;
       izquierda = izq;
       derecha = der;
       padre= padre;
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
//variables globales
int contador = 0;

//PROTOTIPOS
void menu();
void mostrar();
nodo *crearnodo(int,nodo *,nodo *);


nodo *arbol = NULL; //incializa el arbol en NULL
nodo *arbol2 = NULL; //incializa el arbol en NULL
nodo *arbol3 = NULL;
//si vais a definir este solo para tipos de nodos con punteros no necesitais seguir usando el "*"
typedef nodo *pnodo;

class lista {
   public:
   	void insertarnodo(nodo *&, int);
   	void mostrararbol(nodo *); //funcion para mostrar el arbol con recursividad
   	void mostrararbol2(nodo *); //FUNCIOIN PARA RECCORER EL arbol con while
   	void buscar(int , nodo *);
   	
   private:
    pnodo primero;
    pnodo actual;
};

//void mostar(){
	


int main(int argc, char** argv) {
	menu();
   system("pause");
   return 0;
}

void menu(){
	int opcion=0,val=0,contador=0;
	ret:
		system("cls");
		cout<<"--------------ARBOLES---------------------"	<<endl;
		cout<<"\n\t  1. Insertar un nodo"<<endl;
		cout<<"\n\t  2. Listar nodos usando while"<<endl;
		cout<<"\n\t  3. Listar nodos usando recursividad"<<endl;
		cout<<"\n\t  4. Buscar un nodo por su valor"<<endl;
		cout<<"\n\t  5. Salir"<<endl<<endl;
		cout<<"\n\t  Ingrese una opcion: ";
		cin>>opcion;
			switch(opcion){
				case 1:
					{
						system("cls");
						cout<<"\t  --------INGRESANDO UN NODO--------"<<endl;
						cout<<"\n\t  Ingrese el valor del nodo: ";
						cin>>val;
						lista Lista;
						Lista.insertarnodo(arbol,val);
						system("pause");
						goto ret;
					}
				
				case 2:
					{ 
						system("cls");
						cout<<"\t --------MOSTRANDO EL ARBOL usando while--------"<<endl;
						lista Lista1;
						Lista1.mostrararbol2(arbol);
						system("pause");
						goto ret;
					}
				case 3: 
					{
						system("cls");
						cout<<"--------MOSTRANDO EL ARBOL RECURSIVO--------"<<endl;
						lista Lista2;
						Lista2.mostrararbol(arbol);
						system("pause");
						goto ret;
						
					}
				case 4:
					{
						system("cls");
						cout<<"-------BUSAR NODO POR SU VALOR--------------------"<<endl<<endl;
						int valor_buscado=0;
						cout<<"ingrese el valor buscado: "; cin>>valor_buscado;
						lista Lista3;
						Lista3.buscar(valor_buscado,arbol);
						goto ret;
						
					}
				case 5:
					{
						exit(0);
					}
				default:
					{
						cout<<"\n\t  La opcion ingresada no existe en el menu ----"<<endl;
						goto ret;						
					}
			}	
}


//funcion para crear nodos nuevos
nodo *crearnodo(int n){
     nodo *nuevo_nodo= new nodo(n,NULL,NULL);
     //nuevo_nodo-> = 
     return nuevo_nodo;
}

//funcion para insertar nodos en el arbol
void lista::insertarnodo(nodo *&arbol, int n){
	
     if(arbol==NULL)
     {		//si el arbol esta vacio
           // nodo *nuevo_nodo=crearnodo(, n);
            //arbol=nuevo_nodo;
            arbol = crearnodo(n);
            return;
    }else //si el arbol tiene al menos un nodo
     {	
	 		//aca preguntamos si quiere ingresar un valor en el nodo izquierdo, derecho o en los dos 
  			cout<<"\n\t------------Seleccione una opcion: ---------"<<endl<<endl;
  			cout<<"\n\t  1. Ingresar nodo a la izquierda "<<endl;
  			cout<<"\n\t  2. Ingresar nodo a la derecha "<<endl;
  			cout<<"\n\t  3. Ingresar nodo a la izquierda y derecha "<<endl;
  			cout<<"\n\t  OPCION: ";
  			int selec=0; cin>>selec;
  			switch(selec){
  				case 1: //ingresamos el valor al nodo izquierdo
  						insertarnodo(arbol->izquierda,n);
						 
  						break;
  				case 2://ingresamos el valor al nodo derecho
  						if(contador == 0){
  							contador = contador+1;
  						insertarnodo(arbol->derecha,n);
						  contador = 0;}
  						
  						break;
  				case 3://ingresamos el valor al nodo izquierdo y derecho  						
  						if (contador == 0){
  						contador = contador+1;
				  		insertarnodo(arbol->izquierda,n);
  						insertarnodo(arbol->derecha,n);
  						contador = 0;
  					}
  						
  						break;
  				default:
  						cout<<"\n\t La opcion ingresada no existe ";
  						break;

			  }//fin del switch	
			 return;		 
    }
     	
    }
//=======
     

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
	     		cout<<"Valor:  "<<arbol->valor<<",  Codigo : "<<arbol<<" , Codigo_izq: "<<arbol->izquierda; //imprime una parte del contenido
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
		     			cout<<"Valor :  "<<arbol2->valor<<" , Codigo_nodo: "<<arbol2<<" , nodo izq: "<<arbol2->izquierda;
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
			cout<<"Valor: "<<arbol3->valor<<" , Codigo_nodo:  "<<arbol3<<" , Codigo izq: "<<arbol3->izquierda;
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
	     			cout<<"Valor: "<<arbol2->valor<<" , Codigo_nodo: "<<arbol2<<" , nodo izq: "<<arbol2->izquierda;
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
        cout<<"Valor: "<<arbol->valor<<" , Codigo_nodo: "<<arbol<<" ,nodo izq:  "<<arbol->izquierda<<" ,nodo der:  "<<arbol->derecha<<endl;
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
     		cout<<"Valor: "<<arbol->valor<<" , Codigo_nodo: "<<arbol<<" , nodo izq: "<<arbol->izquierda<<" ,nodo der: "<<arbol->derecha<<endl;
     		if(arbol3 != arbol->derecha){
			 
			 if(arbol->derecha != NULL){
     			arbol2=arbol->derecha;
     			cout<<"Valor: "<<arbol2->valor<<" , Codigo_nodo: "<<arbol2<<" , nodo izq: "<<arbol2->izquierda<<" ,nodo der: "<<arbol2->derecha<<endl;
			}
			 }
     		arbol=arbol->izquierda;
		 }while(arbol!= NULL);
		 
				
		 while(arbol3 != NULL){
		 	
			cout<<"Valor: "<<arbol3->valor<<" , Codigo_nodo: "<<arbol3<<" , nodo izq: "<<arbol3->izquierda<<" ,nodo der: "<<arbol3->derecha<<endl;     		
     		if(arbol3->derecha != NULL){
     			arbol2=arbol3->derecha;
     			cout<<"Valor "<<arbol2->valor<<" , Codigo_nodo: "<<arbol2<<" , nodo izq: "<<arbol2->izquierda<<" ,nodo der: "<<arbol2->derecha<<endl;
			 }
     		
     		arbol3=arbol3->izquierda;
     		
		 }
		
     }
}
