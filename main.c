#include <stdio.h>
#include <math.h>

void ZeroBisseccao() {
    double a = -1; //intervalo inicial
    double b = 2;
    double tol = 0.5 * pow(10, -9); //tolerancia de erro
    double erroRel;
    double x;

    int cont = 1;
    do {
        double xAnterior = x;
        x = (a + b) / 2;

        double fDeA = a + cos(a);
        double fDeB = b + cos(b);
        double fDeX = x + cos(x);

        if (fDeA * fDeX <= 0) {
            b = x;
            fDeB = fDeX;
            erroRel = fabs( (x - xAnterior) / x);
        } else {
            a = x;
            fDeA = fDeX;
            erroRel = fabs( (x - xAnterior) / x);
        }
        cont++;
    }
    while (erroRel > tol);

    printf("Para o metodo da bisseccao para x + cos(x) o valor encontrada foi de %f apos %d iteracoes", x, cont);

}

void ZeroNewton() {
    double tol = 0.5 * pow(10, -9); //tolerancia de erro
    double erroRel;
    double x = -1; //chute inicial

    int cont = 1;
    do {
        double xAnterior = x;
        
        double fDeX = xAnterior + cos(xAnterior);
        double dfDeX = 1 - sin(xAnterior); //derivada 
        
        x = xAnterior - (fDeX / dfDeX);
        
        erroRel = fabs( (x - xAnterior) / x);
        
        cont++;
    }
    while (erroRel > tol);

    printf("Para o metodo de newton-raphson para x + cos(x) o valor encontrada foi de %f apos %d iteracoes", x, cont);
}

int main () {
    ZeroBisseccao();
    printf("\n\n");
    ZeroNewton();

    getchar();
    return 0;
}