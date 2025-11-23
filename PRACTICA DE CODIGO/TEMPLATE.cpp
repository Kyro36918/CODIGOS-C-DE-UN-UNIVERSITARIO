#include <iostream>
#include <vector>
#include <limits>

namespace util{
    void pausar(){
        
        std::cout << "ENTER PARA CONTINUAR..\n";
        std::string paus;
        std::getline(std::cin, paus);
    }
}

template <typename K>
class Almacen{
    private:
    std::vector<K> almacenador;
    
    public:

    void recibir(const K& elemento) {almacenador.push_back(elemento);}

    void mostrar() const{
        int indice = 1;
        for (const auto& elem : almacenador)
        {
            std::cout << indice << ". '" << elem << "'\n";
            indice++;
        }
    }
    bool buscar(const K& elemento) const{
        for(auto const& elem : almacenador){
            if (elem == elemento)
            {
                return true;
            }
        }
        return false;
    }
};

class producto{
    private:
    std::string nombre;
    double precio;

    public:
    producto(std::string n, double p):nombre(n), precio(p){}

    bool operator == (const producto& otros) const{
        return nombre == otros.nombre;
    }

    friend std::ostream& operator <<(std::ostream& tip_dat, const producto& impri){
        tip_dat << impri.nombre << " / " << impri.precio;
        return tip_dat;
    }


};

int main(){
    Almacen<int> almacen_entero;

    almacen_entero.recibir(10);
    almacen_entero.recibir(20);
    almacen_entero.recibir(30);

    bool encontrado = almacen_entero.buscar(20);
    std::cout << "encontrado numero 20? " << (encontrado? "si":"no") << "\n";

    almacen_entero.mostrar();

    Almacen<std::string> almacen_string;

    almacen_string.recibir("lapiz");
    almacen_string.recibir("borrador");
    almacen_string.recibir("sacapuntas");

    bool encontrar = almacen_string.buscar("lapicero");
    std::cout << "hay lapicero? " << (encontrar? "SI":"NO") << "\n";

    almacen_string.mostrar();

    Almacen <producto> mi_pro;
    mi_pro.recibir(producto("pan", 2.5));
    mi_pro.recibir(producto("coche", 2000));
    mi_pro.recibir(producto("goma", 0.23));

    bool buscas = mi_pro.buscar(producto("pan", 0));
    std::cout << "hay pan? " << (buscas? "SI":"NO") << "\n";

    mi_pro.mostrar();

    util::pausar();

}