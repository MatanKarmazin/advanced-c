#include <stdio.h>

typedef struct complex {
    double real;
    double img;
} Complex;

void getComplex(Complex *num) {
    printf("Please enter a complex number: ");
    scanf("%lf", &(num->real));
    scanf("%lf", &(num->img));
}

void printComplex(Complex *num) {
    if (num->img > 0) {
        printf("%lf + %lfi", num->real, num->img);
    } else {
        num->img *= -1;
        printf("%lf - %lfi", num->real, num->img);
    }
}

Complex sumComplex(Complex *num1, Complex *num2) {
    Complex sum;
    sum.real = num1->real + num2->real;
    sum.img = num1->img + num2->img;
    return sum;
}

Complex subComplex(Complex *num1, Complex *num2) {
    Complex sub;
    sub.real = num1->real - num2->real;
    sub.img = num1->img - num2->img;
    return sub;
}

Complex multComplex(Complex *num1, Complex *num2) {
    Complex mult;
    mult.real = num1->real * num2->real - num1->img * num2->img;
    mult.img = num1->img * num2->real + num1->real * num2->img;
    return mult;
}

int main() {
    Complex num1, num2;
    getComplex(&num1);
    getComplex(&num2);
    printComplex(&num1);
    printComplex(&num2);
    sumComplex(&num1, &num2);
    subComplex(&num1, &num2);
    multComplex(&num1, &num2);
    return 0;
}