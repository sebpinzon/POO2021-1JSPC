#include "tienda.h"
#include "venta.h"

//CONSTRCUTORES TIENDA

Tienda::Tienda()
{
    this->nombre = "La Farra";
    this->nombreDueno = "POO";
    this->setDummyData();
}

void Tienda::setDummyData()
{
    this->listaCliente.push_back(Cliente("Luisa", "lufe089@gmail.com", 1020, "20202"));
    this->listaProductos.push_back(Producto("Pantene", "Shampoo", 01, 10, 8520));
}

//METODOS TIENDA

void Tienda::mostrarTodosProducto()
{

    //  list<Clase_a_recorrer>:: iterator nombre_iterador = nombre_lista_de_Clase.begin(); it != nombre_lista_de_Clase.end(); i++;

    for (list<Producto>::iterator producto = listaProductos.begin(); producto != listaProductos.end(); producto++)
    {
        producto->mostrarProducto();
    }
}

void Tienda::mostrarTodosCliente()
{

    for (list<Cliente>::iterator it = listaCliente.begin(); it != listaCliente.end(); it++)
    {
        it->mostrarCliente();
    }
}

void Tienda::agregarProducto()
{
    string marca, tipoProducto;
    int codigo = cantidad_productos, existencia;
    float valorProducto;

    cout << "Digite marca: " << endl;
    cin >> marca;

    cout << "Digite tipo del producto: " << endl;
    cin >> tipoProducto;

    cout << "Digite existencia: " << endl;
    cin >> existencia;

    cout << "Digite valor del producto: " << endl;
    cin >> valorProducto;

    listaProductos.push_back(Producto(marca, tipoProducto, codigo, existencia, valorProducto));

    cantidad_productos = codigo++;
}


Producto Tienda::buscarProducto(int codigo)
{
   
    for (list<Producto>::iterator producto = listaProductos.begin(); producto != listaProductos.end(); producto++)
    {
        if (producto->getCodigoProducto() == codigo )
        {
            return producto;
        }
    }

    cout << "Producto no encontrado \n" << endl;
    cout << "Desea agregar uno nuevo? (si=1 / n=0): " << endl;
    cin >> opcion;

    switch(opcion)
    {
        case 0:
            break;
        case 1:
            agregarProducto();
            break;
        default:
            cout << "Seleccione una opcion valida\n" << endl;
            break;

    }
}

void Tienda::agregarCliente()
{
    string nombre;
    string email;
    string telefono;
    int id = this->cantidad_clientes;

    cout << "Digite nombre: " << endl;
    cin >> nombre;

    cout << "Digite email: " << endl;
    cin >> email;

    cout << "Digite telefono: " << endl;
    cin >> telefono;

    listaCliente.push_back(Cliente(nombre, email, id, telefono));

    this->cantidad_clientes = id++;
}

Cliente Tienda::buscarCliente(string nombre)
{
    int opcion;
    for (list<Cliente>::iterator cliente = listaCliente.begin(); cliente != listaCliente.end(); cliente++)
    {
        if (cliente->getNombre() == nombre )
        {
            return cliente;
        }
    }

    cout << "Cliente no encontrado \n" << endl;
    cout << "Desea agregar uno nuevo? (si=1 / n=0): " << endl;
    cin >> opcion;

    switch(opcion)
    {
        case 0:
            break;
        case 1:
            agregarCliente();
            break;
        default:
            cout << "Seleccione una opcion valida\n" << endl;
            break;

    }
}

Venta Tienda::vender()
{
    string fecha, nombre;
    int codigo,cantidad;
    float valorTotal, IVATotal;
    Cliente cliente;
    bool stop=true, stopp=true;

    cout << "Digite la fecha: " << endl;
    cin >> fecha;
    cout << "Digite nombre del cliente: " << endl;
    cin >> nombre;

    cliente = buscarCliente(nombre);

    Venta venta(fecha, cliente, cantidad_ventas);

    while (stop)
    {
        cout << "Digite el codigo del producto: " << endl;
        cin >> codigo;
        cout << "Digite la cantidad del producto: " << endl;
        cin >> cantidad;

        producto = buscarProducto(codigo);

        DetalleVenta detalle_venta(producto, cantidad);

        venta.agregarDetalleVenta(detalle_venta);

        while (stopp)
        {
            cout << "Desea agregar otro producto? (si=1 / no=0): " << endl;
            cin >> opcion;
            switch(opcion)
            {
                case 0:
                    stop = false;
                    stopp = false;
                    break;
                case 1:
                    cout << "Reiniciando proceso" << endl;
                    stopp = false;
                    break;
                default:
                    cout << "Seleccione una opcion valida" << endl;
                    break;

            }  
        }
        
        
    }

    venta.finalizarVenta();

    return venta;
}