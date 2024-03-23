#include<iostream>
#include<cmath>
#include<fstream>

//Funcion para integrar
double funcion(double x){
    return 100*pow(x,2)*cos(20*x);
}

//Calculo de la integral aproximada bajo cuadratura rectangular 

double cuadraturarectangular(double a, double b, int N){
    double h=(b-a)/N;
    double suma=0.0;
    for(int i=0;i<N;i++){
        double xi=a+i*h;
        suma+=funcion(xi);
    }
    return h*suma;
}


int main(){

std::ofstream datafile("resultados_cuadratura_rectangular.dat");

for(int N=1; N<=10000; ++N){
    double integral=cuadraturarectangular(0.0,1.0,N);
    double integral_exacta=4.7459;
    datafile<<N<<" "<<integral<<" "<<integral_exacta<<std::endl;
    }
    


datafile.close();

std::ofstream scriptFile1("Grafico_integral_vs_cuadratura_rectangular.gp");
scriptFile1<<"set term png\n";
scriptFile1<<"set output 'Grafico_integral_vs_cuadratura_rectangular.png'\n";
scriptFile1<<"set xlabel 'N'\n";
scriptFile1<<"set ylabel 'Integral'\n";
scriptFile1<<"set logscale x\n";
scriptFile1<<"plot 'resultados_cuadratura_rectangular.dat' u 1:2 w l title 'Integral aproximada','' u 1:3 w l title 'Valor exacto'";
scriptFile1.close();

//generar datos para graficar y pintar los rectangulos

std::ofstream datafile2("Datos_cuadratura_rectangular.gp");
int N_plot=10;
double h_plot=(1.0-0.0)/N_plot;
for(double x=0.0; x<=1.0; x+=h_plot){
    datafile2<<x<<" "<<funcion(x)<<std::endl;
    datafile2<<x<<" "<<0.0<<std::endl;
    datafile2<<std::endl;
}
datafile2.close();
std::ofstream scriptFile2("Grafico_rectangulos_cuadratura_rectangular.gp");
scriptFile2<<"set term png\n";
scriptFile2<<"set output 'Grafico_funcion_rectangulos_cuadratura_rectangular.png'\n";
scriptFile2<<"set xlabel 'N'\n";
scriptFile2<<"set ylabel 'Valor de la funcion F(x)'\n";
scriptFile2<<"set logscale x\n";
scriptFile2<<"plot 'Datos_cuadratura_rectangular.gp' w l title 'funcion','' w boxes title 'Rectangulo'";
scriptFile2.close();

//ejecutar gnuplot
system("gnuplot Grafico_integral_vs_cuadratura_rectangular.gp");
system("gnuplot Grafico_rectangulos_cuadratura_rectangular.gp");
return 0;
}