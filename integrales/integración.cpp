#include<iostream>
#include<cmath>
#include<fstream>
double funcion(double x){
    return 100*x*x*cos(20*x);
}
double simpson(double a, double b, int N){
    double h=(b-a)/N;
    double suma=0.0;
    for (int i=1;i<(N-1);i++){
        double xi=a+i*h;
        if (i%2==0){
            suma+=2*funcion(xi);
        }
        else{
            suma+=4*funcion(xi);
        }
    }
    return (h/3)*(funcion(a)+suma+funcion(b));
}
double trapecio(double a, double b, int N){
    double h=(b-a)/N;
    double suma=0.0;
    for (int i=1;i<(N-1);i++){
        double xi=a+i*h;
        suma+=funcion(xi);
    }
    return (h*0.5)*(funcion(a)+2*suma+funcion(b));
}
double Rectangular(double a, double b, int N){
    double h=(b-a)/N;
    double suma=0.0;
    for(int i=0;i<N;i++){
        double xi=a+i*h;
        suma+=funcion(xi);
    }
    return h*suma;
}
int main(){
    std::ofstream datafile("Datos_integrales.dat");
    for(int N=1;N<=10000; N++){
        double integral1=simpson(0.0,1.0,N);
        double integral2=trapecio(0.0,1.0,N);
        double integral3=Rectangular(0.0,1.0,N);
        double integral_exacta=4.7459;
        datafile<<N<<" "<<integral3<<" "<<integral2<<" "<<integral1<<" "<<integral_exacta<<std::endl;
    }
    datafile.close();
    std::ofstream scriptfile("grafico_integrales.gp");
    scriptfile<<"set term png \n";
    scriptfile<<"set output 'grafico_integrales_por_3_métodos.png' \n";
    scriptfile<<"set xlabel 'N'\n";
    scriptfile<<"set ylabel 'Integral'\n";
    scriptfile<<"set logscale x\n";
    scriptfile<<"plot 'Datos_integrales.dat' u 1:2 w l title 'Integral por el método rectangular','' u 1:3 w l title 'Integral por el método trapezoidal' ,'' u 1:4 w l title 'Integral por el método de Simpson','' u 1:5 w l title 'Integral exacta'";
    scriptfile.close();
    system("gnuplot grafico_integrales.gp");
    return 0;
}