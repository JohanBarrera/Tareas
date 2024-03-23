#include<iostream>
#include<fstream>
#include<cmath>

double analitica(double x){
    double y;
    y=(-1)/((x*x/4+1/2*x-1));
    return y;
}

double d_f(double x,double y){
return 0.5*(1+x)*pow(y,2);
}

double d_2_f(double x, double y){
return 0.5*pow(y,2)+(1+x)*y*d_f(x,y);
}

double d_3_f(double x,double y){
return 2*y*d_f(x,y)+(1+x)*pow(d_f(x,y),2)+(1+x)*y*d_2_f(x,y);
}

double sol_taylor(double x0,double y0, double h){
    double y_i;
    y_i=y0+h*d_f(x0,y0)+0.5*pow(h,2)*d_2_f(x0,y0)+(1/6)*pow(h,3)*d_3_f(x0,y0);
    return y_i;
}

int main(){
    double x0, y0;
    std::cout<<"Bienvenido a el metodo EDO de Taylor"<<std::endl;
    std::cout<<"Ingrese el valor de x_0:"<<std::endl;
    std::cin>>x0;
    std::cout<<"Ingrese el valor de y_0:"<<std::endl;
    std::cin>>y0;

    //Recuerde que el intervalo es [0,1]
    
    //Realizar el metodo de Taylor con h=0.01 y h=0.001

    //Almacenar en un archivo .txt o .dat junto con la solución exacta.

    //El script para graficar. Y exporte la grafica en png o jpg, 
    //hagale un toque personal

}