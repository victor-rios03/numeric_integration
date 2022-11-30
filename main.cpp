#include <iostream>
#include <cmath>
#include <random>

using namespace std;

double a;
double b;
int n;


double function(double x)
{
    return sin(x);
}

double rectangle_method(double h, double value[])
{
    double sum = 0;
    for(int i=0; i<n; i++) {
        //cout << value[i] << endl;
        sum += function(value[i]);
    }

    cout << "Integral aproximada numericamente con el metodo de rectangulos con n = " << n << endl;
    cout << h*sum << endl;

    return h*sum;
}

double trapezoid_method(double h, double value[])
{
    double sum = 0;

    for (int i=1; i<n; i++) {
        sum += function(value[i]);
    }

    sum = function(value[0]) + 2*(sum) + function(value[n]);

    cout << "Integral aproximada numericamente con el metodo de trapecios con n = " << n << endl;
    cout << h/2*(sum) << endl;

    return h/2*sum;
}

double simpson_method_one_third(double h, double value[])
{
    double sum_even = 0;
    double sum_odd = 0;
    double sum;

    for (int i=1; i<=n/2-1; i++) {
        sum_even += function(value[2*i]);
    }

    for (int i=1; i<=n/2; i++) {
        sum_odd += function(value[2*i-1]);
    }

    sum = function(value[0]) + 4 * sum_odd + 2 * sum_even + function(value[n]);


    cout << "Integral aproximada numericamente con el metodo de simpson 1/3 con n = " << n << endl;
    cout << h/3*sum << endl;

    return h/3*sum;
}

double simpson_method_third_eight(double h, double value[])
{
    double sum_0 = 0;
    double sum_1 = 0;
    double sum;

    for (int i=1; i<=n-1; i++) {
        if (i%3 != 0) {
            sum_0 += function(value[i]);
        }
    }

    for (int i=1; i<=n/3-1; i++) {
        sum_1 += function(value[3*i]);
    }

    sum = function(value[0]) + 3 * sum_0 + 2 * sum_1 + function(value[n]);

    cout << "Integral aproximada numericamente con el metodo de simpson 3/8 con n = " << n << endl;
    cout << 0.375*h*sum << endl;

    return 0.375*h*sum;
}

double f_rand()
{
    random_device re;
    uniform_real_distribution<double> unif(a,b);
    return unif(re);
}

double montecarlo_method(double h)
{
    double sum = 0;
    double random;
    for (int i=1; i<=n; i++) {
        random = f_rand();
        cout << random << endl;
        sum+= function(random);
    }
    cout << "Integral aproximada numericamente con el metodo de montecarlo con n = " << n << endl;
    cout << h*sum << endl;

    return h*sum;
}

int main()
{
    double h;

    cout << "Extremo maximo de la integral" << endl;
    cin >> b;
    cout << "Extremo minimo de la integral" << endl;
    cin >> a;
    cout << "Numero de pasos de la intergal" << endl;
    cin >> n;

    h = (b-a)/n;


    double value[n+1];

    for (int i=0; i<=n; i++) {
        value[i] = a + i*h;
        //cout << i << ' ' << value[i] << endl;
    }

    rectangle_method(h, value);

    trapezoid_method(h, value);

    simpson_method_one_third(h, value);

    simpson_method_third_eight(h, value);

    montecarlo_method(h);

    return 0;
}


