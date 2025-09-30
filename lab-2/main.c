#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <time.h>

int avg(int n, ...)
{
    int result = 0;
    va_list ns;      // указатель va_list
    va_start(ns, n); // устанавливаем указатель
    for (int i = 0; i < n; i++)
    {
        result += va_arg(ns, int); // получаем значение текущего параметра типа int
    }
    va_end(ns); // завершаем обработку параметров
    return result / n;
}

// Функция вычисления выражения t
double calculate_t(double x, double y, double z)
{
    const double znamen = 10000000.0 + pow(log10(4.0), 0.25);
    double chisl = (x * y * z) - (y * fabs(x + sqrt(z)));
    return chisl / znamen;
}

double solve_lab_task(double x, double y, double z,
                      double (*func)(double, double, double))
{
    printf("Применяем переданную функцию-выражение к (x, y, z) = (%.2f, %.2f, %.2f)\n", x, y, z);
    return func(x, y, z);
}

void demonstrate_oob_and_pointers()
{
    printf("\n--- Задание 4: Выход за границы массива (Осторожно: UB!) ---\n");

    char arr1[10] = {'1234567890'};
    char arr2[10] = {'qwertyuiot'}; 
    arr1[10] = '#';

    printf("Значение arr2[0] после индексации arr1[10]: %c\n", arr2[0]);


    
}

int main(void)
{
    printf("%d \n", avg(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10));

    double val_x = 3.0, val_y = 2.0, val_z = 4.0;
    double result_t = solve_lab_task(val_x, val_y, val_z, calculate_t);
    printf("3) Результат вычисления t: %e\n", result_t);
    demonstrate_oob_and_pointers();
    return 0;
}