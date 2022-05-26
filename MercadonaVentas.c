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
	PILA x_pila = crearFila();
	PRODUCTO x_producto;
	/**
	 * n : cantidad de productos
	 * dineroCliente : es el dinero con el que paga el cliente
	 * total : el dinero total del carrito
	 */
	int n, menu, menuAgregar, dineroCliente, total;
	
	printf("Bienvenido a Mercadona\n");
	//menu
	do
	{
		printf("2)Pagar\n");
		printf("0)Salir\n");
		printf("Que desea hacer: \n");
		printf("1)Agregar producto\n");
		scanf("%d", &menu);
		switch (menu){
			case 1:
				do
				{
					printf("1)Base\n");
					printf("Que producto desea agregar: \n");
					printf("0)Salir\n")
					scanf("%s", &menuAgregar);
					switch (menuAgregar){
						case 1:
							do
							{
								printf("Cantidad de productos a agregar: ");
								scanf("%d", &n);
								if (n < 1)
									printf("Ingrese un valor valido.\n");
							} while (n < 1);
							x_producto.cantidad = n;
							x_producto.id = 1;
							x_producto.valor = 500;
							x_pila = push(x_pila, x_producto)
							break;
					}
				} while (menuAgregar != 0);
				
				break;
			case 2:
				total = totalCarrito(x_pila);
				printf("TOTAL CARRO $%d\n", total);
				do
				{
					printf("Cliente pago con $: ");
					scanf("%d", dineroCliente);
					if (dineroCliente < 1 && dineroCliente < total)
						printf("Ingrese un valor valido.\n");
				} while (dineroCliente < 1 && dineroCliente < total);

				BOLETA x_boleta = caja(total, dineroCliente);
				verBoleta(x_boleta);
				printf("Que tenga buen dia!!\n");
				system("pause");
				return x_boleta;
		}
	} while (menu != 0);

	printf("Que tenga buen dia!!\n");
	system("pause");
	return 0;
}

int totalCarrito(PILA productos){
	PILA aux = productos;
	int suma = 0;
	while (empty(aux) != 1)
	{
		suma += aux.tope->producto.valor * aux.tope->producto.cantidad;
		aux = pop(aux);
	}
	return suma;
}

BOLETA caja(int totalCarrito, int dineroCliente){
	srand(time(NULL));
	int numero = rand () % (10000-20+1) + 20;
	BOLETA b;
	b.id = numero; 
	b.dineroCarrito = totalCarrito;
	b.dineroPago = dineroCliente;
	b.dineroVuelto = dineroCliente + totalCarrito; // Error
    return b;
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