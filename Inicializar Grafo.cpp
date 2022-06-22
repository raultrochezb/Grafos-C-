#ifndef GRAFO_H
#define GRAFO_H
#include<iostream>
#include <queue>
#include <list>
#include <stack>
using namespace std;

class Arista;

class Vertice{
	public:
		
		Vertice *sig;
		Arista *ady;
		string nombre;
		friend class Grafo;
};

class Arista{
	public:
		
		Arista *sig;
		Vertice *ady;
		int peso;
		friend class Grafo;
};

class Grafo{
	
	public:
		Vertice *h;
		
		void inicializar(){
			h = NULL;
		}
		
		
		bool vacio(){
			if(h == NULL){
				return true;
			}else{
				return false;
			}
		}
		
		
		int tamanio(){
			int cont;
			Vertice *aux;
			aux = h;
			
			while(aux != NULL){
				cont++;
				aux = aux->sig;
			}
			return cont;
		}
		
		Vertice *getVertice(string nombre){
			Vertice *aux;
			aux = h;
			
			while(aux != NULL){
				if(aux->nombre == nombre){
					return aux;
				}
				aux = aux->sig;
			}
			return NULL;
		}
		
		void insertarArista(Vertice *origen, Vertice *destino, int peso){
			Arista *nueva = new Arista;
			nueva->peso = peso;
			nueva->sig = NULL;
			nueva->ady = NULL;
			
			Arista *aux;
			aux = origen->ady;
			
			if(aux == NULL){
				origen->ady = nueva;
				nueva->ady = destino;
			}else{
				while(aux->sig != NULL){
					aux = aux->sig;
				}
				aux->sig = nueva;
				nueva->ady = destino;
			}
			
			
		}
		
		void insertarVertice(string nombre){
			Vertice *aux;
			Vertice *nuevo = new Vertice;
			nuevo->nombre = nombre;
			nuevo->sig = NULL;
			nuevo->ady = NULL;
			
			if(vacio()){
				h = nuevo;
			}else{
				aux = h;
				while(aux->sig != NULL){
					aux = aux->sig;
				}
				aux->sig = nuevo;
			}
		}
		
		
		void listaAdyacencia(){
			Vertice *auxVer;
			Arista *auxAr;
			
			auxVer = h;
			while(auxVer != NULL){
				cout<<auxVer->nombre<<"->";
				auxAr = auxVer->ady;
				
				while(auxAr != NULL){
					cout<<auxAr->ady->nombre<<"->";
					auxAr = auxAr->sig;
				}
				auxVer = auxVer->sig;
				cout<<endl;
			}
		}
		
		
		void eliminarArista(Vertice *origen, Vertice *destino){
			Arista *actual, *anterior;
			int  band = 0;
			actual = origen->ady;
			
			if(actual == NULL){
				cout<<"El vertice origen no tiene aristas"<<endl;
			}else if(actual->ady == destino){
				origen->ady = actual->sig;
				delete(actual);
			}else{
				while(actual != NULL){
					if(actual->ady == destino){
						band = 1;
						anterior->sig = actual->sig;
						delete(actual);
						break;
					}
					anterior = actual;
					actual = actual->sig;	
				}
				
				if(band == 0){
					cout<<"Esos dos vertices no estan conectados"<<endl;
				}
			}
		} 
		
		
		void anular(){
			Vertice *aux;
			
			while(h != NULL){
				aux = h;
				h = h->sig;
				delete(aux);
			}	
		}
		
		
		void eliminarVertice(Vertice *vertice){
			Vertice *actual, *anterior;
			Arista *aux;
			
			actual = h;
			
			while(actual != NULL){
				aux = actual->ady;
				while(aux != NULL){
					if(aux->ady == vertice){
						eliminarArista(actual, aux->ady);
						break;
					}
					aux = aux->sig;
				}
				actual = actual->sig;
			}
			
			actual = h;
			
			if(h == vertice){
				h = h->sig;
				delete(actual);
			}else{
				while(actual != vertice){
					anterior = actual;
					actual = actual->sig;
				}
				anterior->sig = actual->sig;
				delete(actual);
			}
		}
		
		
};
void Grafo::RecorridoAnchura(Vertice *origen)
{
	int band, band2;
	Vertice *actual;
	queue<Vertice*>cola;
	list<Vertice*>lista;
	list<Vertice*>::iterator i;
	
	cola.push(origen);
	while(!Cola.empty())
	{
		band = 0;
		actual = cola.front();
		cola.pop();
		
		for(i=lista.begin(); i != lista.end(); i++)
		{
			if(*i == actual)
			{
				band = 1;
			}
		}
		if(band == 0)
		{
			cout<<actual->nombre<<", ";
			lista.push_back(actual);
			
			Arista *aux;
			aux = actual->ady;
			while(aux != NULL)
			{
				band2 = 0;
				for(i=lista.begin(); i!=lista.end(); i++)
				{
					if(aux->ady == *i)
					{
						band2 = 1;	
					}
				}
				if(band2 == 0)
				{
					cola.push(aux->ady);
				}
				aux = aux->sig;
			}
		}
		
	}
	
}

void Grafo::RecorridoProfundidad(Vertice *origen)
{
	int band, band2;
	Vertice *actual;
	stack<Vertice*>pila;
	list<Vertice*>lista;
	list<Vertice*>::iterator i;
	
	pila.push(origen);
	
	while(!pila.empty())
	{
		band = 0;
		actual = pila.top();
		pila.pop();	
		
		for(i=lista.begin(); i!=lista.end(); i++)
		{
			
			if(*i == actual)
			{
				band = 1;	
			}
		}
		if(band == 0)
		{
			cout<<actual->nombre<<", ";
			lista.push_back(actual);
			
			Arista *aux;
			aux = actual->ady;
			
			while(aux != NULL)
			{
				band2 = 0;
				for(i=lista.begin(); i!=lista.end(); i++)
				{
					if(*i == aux->ady)
					{
						band2 = 1;
					}
				}
				if(band2 == 0)
				{
					pila.push(aux->ady)
				}
				aux = aux->sig;
			}
		}
	}
}
int main(){
	
	Grafo g;
	
	g.inicializar();
	g.insertarVertice("Cortes");
	g.insertarVertice("Francisco Morazan");
	g.insertarVertice("Atlantida");
	g.insertarVertice("Olancho");
	g.insertarVertice("Santa Barbara");
	g.insertarVertice("Copan");
	
	g.insertarArista(g.getVertice("Cortes"), g.getVertice("LEMPIRA"), 300);
	g.insertarArista(g.getVertice("Cortes"), g.getVertice("OCOTEPEQUE"), 200);
	g.insertarArista(g.getVertice("Cortes"), g.getVertice("Copan"), 200);
	g.insertarArista(g.getVertice("Copan"), g.getVertice("Olancho"), 350);
	g.insertarArista(g.getVertice("Copan"), g.getVertice("Atlantida"), 500);
	g.insertarArista(g.getVertice("Francisco Morazan"), g.getVertice("Santa Barbara"), 200);
	g.insertarArista(g.getVertice("Atlantida"), g.getVertice("Copan"), 500);
	g.insertarArista(g.getVertice("Atlantida"), g.getVertice("YORO"), 200);
	g.insertarArista(g.getVertice("Olancho"), g.getVertice("COMAYAGUA"), 200);
	g.insertarArista(g.getVertice("Olancho"), g.getVertice("Francisco Morazan"), 250);
	g.insertarArista(g.getVertice("Santa Barbara"), g.getVertice("GRACIAS A DIOS"), 100);
		
	g.listaAdyacencia();
	cout<<endl;
	cout<<"El tamanio de la lista es de: "<<g.tamanio()<<endl;
	cout<<endl;
	cout<<"--- Arista Eliminada ---"<<endl;
	g.eliminarArista(g.getVertice("Cortes"), g.getVertice("Francisco Morazan"));
	g.listaAdyacencia();
	cout<<endl;
	cout<<"--- Vertice Eliminado ---"<<endl;
	g.eliminarVertice(g.getVertice("Cortes"));
	g.listaAdyacencia();
	
	
}
