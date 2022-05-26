#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct s_boleta{
    int id, dineroCarrito, dineroPago, dineroVuelto;
} BOLETA;

/* Estructura para representar un producto */
typedef struct s_producto{
    int id,valor, cantidad;
} PRODUCTO;

/* Nodo para guardar un producto y el nexo con el siguiente producto */
typedef struct s_elemento{
	PRODUCTO producto;
	struct s_elemento *siguiente;
} *ELEMENTO;

/* Estructura para la pila */
typedef struct s_pila{
	ELEMENTO tope;
} PILA;

/* Estructura para la fila */
typedef struct s_fila_enlazada{
	ELEMENTO elementos;
	struct s_elemento *frente, *ultimo;
} FILA;

/* Operaciones de pila */
PILA crearPila();
/* Retorna 1 si la pila está vacía y un -1 eoc */
int empty(PILA);
/* Agrega un elemento a la pila */
PILA push(PILA, PRODUCTO);
/* Extrae el tope de la pila */
PILA pop(PILA);
/* Retorna el tope de la pila SIN extraerlo */
PRODUCTO top(PILA);

/* Operaciones de fila */
FILA crearFila();
/* Retorna 1 si la fila está vacía y un 0 eoc */
int esVacia(FILA);
/* Agrega un elemento a la fila */
FILA agregar(FILA, PRODUCTO);
/* Extrae el frenet de la fila */
FILA extraer(FILA);
/* Retorna el elemento del frente de la fila SIN EXTRAER */
PRODUCTO verFrente(FILA);

/* Función a implementar en la evaluación */
BOLETA caja(int, int);
int totalCarrito(PILA);
void verBoleta(BOLETA);
/* Funcion principal */
int main(){
	
	return 0;
}

int totalCarrito(PILA productos){
	
}

BOLETA caja(int totalCarrito, int dineroCliente){
	
}

void verBoleta(BOLETA b){
	printf("----------------------------------------------\n");
	printf("--------------BOLETA--Mercadona---------------\n");
	printf("ID: %d\n", b.id);
	printf("Total carrito: %d\n", b.dineroCarrito);
	printf("Monto pagado: %d\n", b.dineroPago);
	printf("Vuelto: %d\n", b.dineroVuelto);
	printf("----------------------------------------------\n");
}

PILA crearPila(){
	PILA nueva;
	nueva.tope = NULL;
	return nueva;
}

int empty(PILA p){
	return (p.tope==NULL?1:-1);
}

PILA push(PILA p, PRODUCTO pro){
	ELEMENTO nuevo;
	nuevo = (ELEMENTO) malloc(sizeof(struct s_elemento));
	nuevo->producto = pro;
	nuevo->siguiente = p.tope;	
	/* Modifica el tope de la pila */
	p.tope = nuevo;
	return p;
}

PILA pop(PILA p){	
	p.tope = p.tope->siguiente;	
	return p;		
}

PRODUCTO top(PILA p){
	return p.tope->producto;
}

FILA crearFila(){
	FILA nueva;
	nueva.elementos = NULL;
	nueva.frente = NULL;
	nueva.ultimo = NULL;
	return nueva;
}

int esVacia(FILA f){
	return (f.frente == NULL)?1:0;
}

FILA agregar(FILA f, PRODUCTO nuevo){
	ELEMENTO nodo; 

	nodo = (ELEMENTO) malloc(sizeof(struct s_elemento));
	nodo->producto = nuevo;
	nodo->siguiente = NULL;	
	if (f.ultimo != NULL){
		f.ultimo->siguiente = nodo;
		f.ultimo = nodo;
	}
	else{
		f.elementos = nodo;
		f.frente = nodo; f.ultimo = nodo;
	}
	return f;
}

FILA extraer(FILA f){		
	f.frente = f.frente->siguiente;
	return f;		
}

PRODUCTO verFrente(FILA f){
	return f.frente->producto;
}