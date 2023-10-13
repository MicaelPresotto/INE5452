#include <iostream>
#include <cmath>

double func(double x, double p, double q, double r, double s, double t, double u){
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double bissection(double a, double b, double erro, double p, double q, double r, double s, double t, double u){
    if(func(a, p, q, r, s, t, u) * func(b, p, q, r, s, t, u) > 0){
        return NAN;
    }
    if(func(a, p, q, r, s, t, u) == 0.0){
        return a;
    }
    if(func(b, p, q, r, s, t, u) == 0.0){
        return b;
    }
    while((b-a)/2 > erro){
        double x = (a+b)/2;
        if(func(x,p,q,r,s,t,u) == 0.0){
            return x;
        }else if(func(x,p,q,r,s,t,u) * func(a,p,q,r,s,t,u) < 0){
            b = x;
        }else{
            a = x;
        }
    }
    return (a+b)/2;
}

int main(void){
    double p,q,r,s,t,u;
    double erro = 1e-10;
    double a = 0;
    double b = 1;
    
    while (std::cin >> p >> q >> r >> s >> t >> u) {
        double x = bissection(a, b, erro, p, q, r, s, t, u);
        if (std::isnan(x)) {
            std::cout << "No solution" << std::endl;
        } else {
            printf("%.4lf\n", x);
        }
    }

    return 0;
}
