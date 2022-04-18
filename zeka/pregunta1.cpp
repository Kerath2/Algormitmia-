#include <iostream>
#include <iomanip>
using namespace std;


int main(){
  int opcion;
  int numeroTablets;
  int categoria;
  double precioTablet;
  int salir = 0;

  double montoBruto, montoImp , montoTotal;

  while(!salir){
    cout << "Ingrese una opcion(1 procesar o 2 salir): ";
    cin >> opcion;

    switch(opcion){
      case 1:
        cout << "Eligió la opcion de procesar\n";
        cout << "Ingrese el numero de tablets a comprar: ";
        cin >> numeroTablets;
        if(numeroTablets > 0){

        }else{
          cout << "El numero de tablets debe ser positivo\n";
          salir = 1;
        }
        cout << "Ingrese la categoria (1,2,3): ";
        cin >> categoria;
        if(categoria == 1 || categoria == 2 || categoria ==3){
        
        }else{
          cout <<"La categoria debe ser 1, 2 o 3 \n";
          salir = 1;
        }
        cout << "Ingrese el precio de la tablet: ";
        cin >> precioTablet;
        if(precioTablet>0){
        
        }else{
          cout << "El precio de la tablet debe ser un valor prositivo\n";
          salir = 1;
        }
        switch (categoria) {
          case 1:
           montoBruto = precioTablet * numeroTablets;
           montoImp =  montoBruto *(0.08);
           montoTotal = montoBruto + montoImp;
          break;
          case 2:
           montoBruto = precioTablet * numeroTablets;
           montoImp =  montoBruto *(0.11);
           montoTotal = montoBruto + montoImp;
          break;
          case 3:
           montoBruto = precioTablet * numeroTablets;
           montoImp =  montoBruto *(0.13);
           montoTotal = montoBruto + montoImp;
          break;
        }
        cout << "Se calcularon los siguientes montos: \n";
        cout << "El monto bruto es: "<<fixed<<setprecision(2) << montoBruto <<endl;
        cout << "El monto de imporatacion es: "<<fixed<<setprecision(2) << montoImp <<endl;
        cout << "El monto TOTAL es: "<<fixed<<setprecision(2) << montoTotal <<endl;
        cout <<"-----------------------------------------------------------------\n";
     break;
      case 2:
      salir = 1;
     break;
  }
  }
return 0;
}
