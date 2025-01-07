#include <iostream>
#include <string>
using namespace std;
//estructura de cada posición del arreglo
 struct pelicula{
 	string clave;
 	string proveedor;
 	string nombre;
 	int cantidad;
 	float precio;
 	float calificacion;
 };
 //función que permite obtener la longitud de un string
 int longitud(string a){
 	 int i = 0;
	 while(a[i]!='\0'){
	 	i=i+1;
	 }
	 return i;
 }
 //función que genera la clave a partir del proveedor y el índice
  string generarClave(string proveedor, int i){
 	string clave = "";
 	int numeroprod = i + 1; //siempre el valor del índice es uno menos que el del producto
 	for(int i = 0; i<2; i++){
 		char caracter = proveedor[i]; // extrae los dos primeros caracteres del string proveedor
 		if(caracter>=97 && caracter<=122){ //revisa si son minúsculas
 			caracter = caracter - 32; // y las pasa a mayúsculas
		 }
 		clave = clave + caracter; //las concatena en clave
	 }
	if(i<9){
 	char numero = '0'+numeroprod; // sumando a '0' un número de una sola posición lo convertimos a char
	clave = clave+ '0'+'0'+numero;
	}else{
		char numero1 = '0' + numeroprod/10;
		char numero2 = '0' + numeroprod%10;
	clave = clave+ '0'+numero1+numero2;
	}
	return clave;
 }
 
 void mostrarProducto(pelicula a){ //imprime todos los campos del struct tipo película que se le pase como parámetro
 	cout<<"Proveedor: "<< a.proveedor<<"\n";
 	cout<<"Nombre: "<< a.nombre<<"\n";
 	cout<<"Cantidad: "<< a.cantidad<<"\n";
 	cout<<"Precio en pesos: "<< a.precio<<"\n";
 	cout<<"Calificacion: "<< a.calificacion<<"\n";
 }
 
 void altaProducto(pelicula productos[], int &i){ // se pasa el índice por referencia para poderlo aumentar al final
 
 	pelicula aux; //auxiliar para no escribir directamente en el arreglo y permitir verificar al final
 	
 	aux.cantidad = 0;
 	aux.precio = 0;
 	aux.calificacion = 0;

 	cout<<"Alta de producto: \n";
 	cout<<"Especifique proveedor: \n";
 	cin.ignore();
 	getline(cin, aux.proveedor);
 	while(longitud(aux.proveedor)<2 || aux.proveedor[0]==' ' || aux.proveedor[1]==' ' || aux.proveedor[0]<65 || (aux.proveedor[0]>92 && aux.proveedor[0]<97) || aux.proveedor[0]>122 || aux.proveedor[1]<65 || (aux.proveedor[1]>92 && aux.proveedor[1]<97) || aux.proveedor[1]>122){
 		//validamos que tenga dos caracteres, que no sean espacios y que sean letras
		cout<<"El proveedor debe tener al menos dos letras, ingrese proveedor: \n";
 		getline(cin, aux.proveedor); 	
 	}
 	cout<<"Especifique nombre o titulo de la pelicula: \n";
 	getline(cin, aux.nombre);
 	while(longitud(aux.nombre)<1 || aux.nombre[0]==' '){
 		//validamos que no esté vacío o sea un espacio
 		cout<<"El nombre no puede estar vacio, ingrese nombre: \n";
 		getline(cin, aux.nombre);
	}
 	cout<<"Especifique cantidad: \n";
 	cin>>aux.cantidad;
 	while(aux.cantidad<0){
 		//validamos que la cantidad sea positiva
 		cout<<"La cantidad no puede ser negativa, ingrese cantidad: \n";
 		cin>>aux.cantidad;
	}
 	cout<<"Especifique precio en pesos: \n";
 	cin>>aux.precio;
 	while(aux.precio<0){
 		//validamos que el precio sea positivo
 		cout<<"El precio no puede ser negativo, ingrese precio: \n";
 		cin>>aux.precio;
	}
 	cout<<"Especifique calificacion: \n";
 	cin>>aux.calificacion;
 	while(aux.calificacion<=0 || aux.calificacion>10){
 		//validamos que la calificación entre en el rango de 1 a 10
 		cout<<"La calificacion debe estar entre 1 y 10, ingrese calificacion: \n";
 		cin>>aux.calificacion;
	}
	 
	 cout<<"\n\nSon correctos los campos? S/N \n\n"; //permitimos que el usuario vea un resumen de todo lo que ingresó y lo valide
	 mostrarProducto(aux); // le mostramos el producto
	 cout<<"\n\n";
	 char a;
	 cin>>a; //leemos la decisión del usuario
	 while((a!='S') && (a!='N')){ //seguimos leyendo hasta que haya una entrada válida
	 	cin>>a;
	}
	 if(a=='S'){ //si la respuesta fue positiva se copia el producto al arreglo
	 	productos[i].clave = generarClave(aux.proveedor, i); //se le genera una clave única al producto
	 	productos[i].proveedor = aux.proveedor;
	 	productos[i].nombre = aux.nombre;
	 	productos[i].cantidad = aux.cantidad;
	 	productos[i].precio = aux.precio;
	 	productos[i].calificacion = aux.calificacion;
		cout<<"\n\nProducto dado de alta de manera exitosa con clave: "<<productos[i].clave<<"\n\n"; //le mostramos al usuario cuál es la clave generada
		i = i + 1; //aumentamos el contador para poder seguir dando de alta sin entrar en conflicto
		return; //regresamos a la función del menú
	}else{
	 	cout<<"Alta cancelada\n\n"; // si la respuesta no fue positiva se cancela la operación y se regresa a la función del menú
	 	return;
	}	
 }
 
 void modifProducto(pelicula productos[]){
 	int indice = -1;
 	bool existe = false; //no necesariamente existe la clave
 	string claveingresada;
	cout<<"\nIngrese la clave del producto a editar: \n\n";
 	cin.ignore();
 	getline(cin, claveingresada);
 	while(indice < 50 && existe == false){ //aumentamos el contador hasta que aparezca la clave o lleguemos al final del arreglo
 		indice++;
 		if(productos[indice].clave == claveingresada){
 			existe = true;
		 }
	 }
	if(existe == true){
		//muestra los datos del producto y vuelve a pedir los datos editables
		mostrarProducto(productos[indice]);
		cout<<"\n\n";
		cout<<"Inserte nuevos datos: \n\n";
		cout<<"Especifique nombre o titulo de la pelicula: \n";
 		getline(cin, productos[indice].nombre);
 		while(longitud(productos[indice].nombre)<1 || productos[indice].nombre[0]==' '){
 			cout<<"El nombre no puede estar vacio, ingrese nombre: \n";
 			getline(cin, productos[indice].nombre);
	 	}
 		cout<<"Especifique cantidad: \n";
 		cin>>productos[indice].cantidad;
 		while(productos[indice].cantidad<0){
 			cout<<"La cantidad no puede ser negativa, ingrese cantidad: \n";
 			cin>>productos[indice].cantidad;
	 	}
 		cout<<"Especifique precio en pesos: \n";
 		cin>>productos[indice].precio;
 		while(productos[indice].precio<0){
 			cout<<"El precio no puede ser negativo, ingrese precio: \n";
 			cin>>productos[indice].precio;
	 	}
 		cout<<"Especifique calificacion: \n";
 		cin>>productos[indice].calificacion;
 		while(productos[indice].calificacion<=0 || productos[indice].calificacion>10){
 			cout<<"La calificacion debe estar entre 1 y 10, ingrese calificacion: \n";
 			cin>>productos[indice].calificacion;
	 	}
	 	cout<<"\nProducto modificado con exito\n\n";
	}else{
		cout<<"\nLa clave introducida no existe en el catalogo\n\n"; // si llegamos al final del arreglo y nunca apareció la clave, no está en el catálogo
		return;
	}
 }
 
 void mostrarCatalogo(pelicula productos[]){ //recorre todo el arreglo imprimiendo cada campo hasta que llegue al final o encuentre una clave vacía
 	int i = 0;
 	cout<<"\nCatalogo de productos: \n\n";
 	while(i<50 && productos[i].clave!=""){
 		cout<<"Clave: "<<productos[i].clave;
 		cout<<"\n";
 		mostrarProducto(productos[i]);
 		cout<<"\n\n";
 		i = i + 1;
	 }
	if(i==0){
		cout<<"El catalogo esta vacio, ingrese datos\n\n"; //si la primera clave está vacía y no entró al ciclo, por tanto nunca aumentó el contador, entonces no hay productos dados de alta
	}
	return;
 }
 
 void existenciaProductos(pelicula productos[]){ //recorre el arreglo de la misma forma que la anterior, solo que imprime si la cantidad es menor a la ingresada por el usuario
 	int cantidadIngresada;
 	cout<<"Ingrese el numero de existencias a revisar: \n";
 	cin>>cantidadIngresada;
 	cout<<"\nProductos cuya existencia es menor a "<<cantidadIngresada<<":\n\n";
 	int i = 0;
 	bool existen = false;
 	while(i<50 && productos[i].clave!=""){
 		if(productos[i].cantidad < cantidadIngresada){
 		cout<<"Clave: "<<productos[i].clave;
 		cout<<"\n";
 		mostrarProducto(productos[i]);
 		existen = true;
 		cout<<"\n";
 		}
 		i++;
	}
	if(existen == false){
		cout<<"Ninguno\n\n";
	}
 }
 
 void productosProveedor(pelicula productos[]){ //mismo recorrido del arreglo, pero ahora imprime si el proveedor coincide
 	string proveedorIngresado;
 	cout<<"Ingrese el proveedor a revisar: \n";
 	cin.ignore();
 	getline(cin, proveedorIngresado);
 	cout<<"\nProductos que pertenecen al proveedor "<<proveedorIngresado<<":\n\n";
 	int i = 0;
 	bool existen = false;
 	while(i<50 && productos[i].clave!=""){
 		if(productos[i].proveedor == proveedorIngresado){
 		cout<<"Clave: "<<productos[i].clave;
 		cout<<"\n";
 		mostrarProducto(productos[i]);
 		existen = true;
 		cout<<"\n";
 		}
 		i++;
	}
	if(existen == false){
		cout<<"Ninguno\n\n";
	}
 }

 void productosPrecio(pelicula productos[]){ //mismo recorrido del arreglo, pero ahora imprime si el precio es mayor al ingresado por el usuario
 	float precioIngresado;
 	cout<<"Ingrese el precio a revisar: \n";
 	cin>>precioIngresado;
 	cout<<"\nProductos que cuestan mas de "<<precioIngresado<<" pesos:\n\n";
 	int i = 0;
 	bool existen = false;
 	while(i<50 && productos[i].clave!=""){
 		if(productos[i].precio > precioIngresado){
 		cout<<"Clave: "<<productos[i].clave;
 		cout<<"\n";
 		mostrarProducto(productos[i]);
 		existen = true;
 		cout<<"\n";
 		}
 		i++;
	}
	if(existen == false){
		cout<<"Ninguno\n\n";
	}
 }

  void mostrarMenu(pelicula productos[], int &contadorprod){	//muestra el menú principal
	int opcion;
	while(true){ //cicla a propósito para mantener el menú en pantalla
	cout<<"  %%%%%%%%%%%%%%%%%%%%%%%%%%            Bienvenido a PEPOBUSTER            %%%%%%%%%%%%%%%%%%%%%%%%%%";
	cout<<"\n";
	cout<<"          %%%%%%%%%%%%%%%%%%%%%%%%%%        MENU PRINCIPAL        %%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout<<"                                        Seleccione una opcion: \n\n";
	cout<<"                      1. Alta de producto\n";
	cout<<"                      2. Modificar un producto\n";
	cout<<"                      3. Mostrar catalogo\n";
	cout<<"                      4. Productos cuya existencia sea menor a un numero determinado\n";
	cout<<"                      5. Productos que pertenezcan a un proveedor especifico\n";
	cout<<"                      6. Productos que cuesten mas de un precio determinado\n";
	cout<<"                      7. Salir\n";
	cin>>opcion;
	switch(opcion){
			case 1:
				altaProducto(productos, contadorprod);
				break;
			case 2:
				modifProducto(productos);
				break;
			case 3:
				mostrarCatalogo(productos);
				break;
			case 4:
				existenciaProductos(productos);
				break;
			case 5:
				productosProveedor(productos);
				break;
			case 6:
				productosPrecio(productos);
				break;
			case 7:
				return; //el caso 7 sale de la función por ser la opción de salir, los demás hacen break para volver al menú
			default:
				cout<<"Ingrese una opcion valida: \n"; //si no entra alguna de las opciones lo vuelve a pedir hasta que lo haga
				break;
		}
	}
 }
 


 int main(){
	pelicula productos[50]; //declara el arreglo sobre el que funciona todo el inventario
	int contadorprod = 0; //valor inicial del contador
	mostrarMenu(productos, contadorprod); //muestra el menú principal, cuando la opción 7 sale del menú acaba el main
	return 0;
}