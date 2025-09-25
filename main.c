#include <stdio.h>
#include <stdint.h>

// Макрос для удобного вывода числа в двоичном формате (8 бит)
void print_binary_u8(uint8_t n)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%c", (n & (1 << i)) ? '1' : '0');
    }
}

// 1. УСТАНОВКА БИТОВ В ЕДИНИЦУ (x | mask)

uint8_t F1_8(uint8_t x, uint8_t mask)
{
    return x | mask;
}

uint16_t F1_16(uint16_t x, uint16_t mask)
{
    return x | mask;
}

uint32_t F1_32(uint32_t x, uint32_t mask)
{
    return x | mask;
}

// 2. ОБНУЛЕНИЕ БИТОВ (x & ~mask)

uint8_t F2_8(uint8_t x, uint8_t mask)
{
    return x & ~mask;
}

uint16_t F2_16(uint16_t x, uint16_t mask)
{
    return x & ~mask;
}

uint32_t F2_32(uint32_t x, uint32_t mask)
{
    return x & ~mask;
}

// 3. ИНВЕРСИЯ БИТОВ (x ^ mask)

uint8_t F3_8(uint8_t x, uint8_t mask)
{
    return x ^ mask;
}

uint16_t F3_16(uint16_t x, uint16_t mask)
{
    return x ^ mask;
}

uint32_t F3_32(uint32_t x, uint32_t mask)
{
    return x ^ mask;
}

// 4. ЛОГИЧЕСКИЙ СДВИГ ВЛЕВО (x << n)

uint8_t F4_8(uint8_t x, uint8_t n)
{
    return x << n;
}

uint16_t F4_16(uint16_t x, uint16_t n)
{
    return x << n;
}

uint32_t F4_32(uint32_t x, uint32_t n)
{
    return x << n;
}

// 5. ЛОГИЧЕСКИЙ СДВИГ ВПРАВО (x >> n)

uint8_t F5_8(uint8_t x, uint8_t n)
{
    return x >> n;
}

uint16_t F5_16(uint16_t x, uint16_t n)
{
    return x >> n;
}

uint32_t F5_32(uint32_t x, uint32_t n)
{
    return x >> n;
}

// 6. ЦИКЛИЧЕСКИЙ СДВИГ ВЛЕВО

uint8_t F6_8(uint8_t x, uint8_t n)
{
    // Используем 8 вместо sizeof(x)*8 для u8
    return (x << n) | (x >> (8 - n));
}

uint16_t F6_16(uint16_t x, uint16_t n)
{
    return (x << n) | (x >> (16 - n));
}

uint32_t F6_32(uint32_t x, uint32_t n)
{
    return (x << n) | (x >> (32 - n));
}

// 7. ЦИКЛИЧЕСКИЙ СДВИГ ВПРАВО

uint8_t F7_8(uint8_t x, uint8_t n)
{
    return (x >> n) | (x << (8 - n));
}

uint16_t F7_16(uint16_t x, uint16_t n)
{
    return (x >> n) | (x << (16 - n));
}

uint32_t F7_32(uint32_t x, uint32_t n)
{
    return (x >> n) | (x << (32 - n));
}

// ТЕСТОВАЯ ПРОГРАММА (main)

int main()
{
    // Исходное число: 178 (10110010)
    uint8_t x = 0b10110010;
    // Маска для изменения 3, 5, 7-го битов: 10101000
    uint8_t mask = 0b10101000;
    // Количество сдвигов
    uint8_t n = 3;

    printf("ИСХОДНОЕ ЧИСЛО (x): %d (", x);
    print_binary_u8(x);
    printf(")\n");
    printf("МАСКА:             %d (", mask);
    print_binary_u8(mask);
    printf(")\n");
    printf("СДВИГ (n):         %d\n\n", n);

    printf("--- БИТОВЫЕ ОПЕРАЦИИ ---\n");

    // 1. Установка битов
    uint8_t res_set = F1_8(x, mask);
    printf("1. УСТАНОВКА (x | m):  %d (", res_set);
    print_binary_u8(res_set);
    printf(")\n");

    // 2. Обнуление битов
    uint8_t res_clear = F2_8(x, mask);
    printf("2. ОБНУЛЕНИЕ (x & ~m): %d (", res_clear);
    print_binary_u8(res_clear);
    printf(")\n");

    // 3. Инверсия битов
    uint8_t res_invert = F3_8(x, mask);
    printf("3. ИНВЕРСИЯ (x ^ m):   %d (", res_invert);
    print_binary_u8(res_invert);
    printf(")\n\n");

    printf("--- ЛОГИЧЕСКИЕ СДВИГИ (на %d позиций) ---\n", n);

    // 4. Логический сдвиг влево
    uint8_t res_lshift = F4_8(x, n);
    printf("4. ЛОГ. ВЛЕВО (x << n): %d (", res_lshift);
    print_binary_u8(res_lshift);
    printf(")\n");

    // 5. Логический сдвиг вправо
    uint8_t res_rshift = F5_8(x, n);
    printf("5. ЛОГ. ВПРАВО (x >> n): %d (", res_rshift);
    print_binary_u8(res_rshift);
    printf(")\n\n");

    printf("--- ЦИКЛИЧЕСКИЕ СДВИГИ (на %d позиций) ---\n", n);

    // 6. Циклический сдвиг влево
    uint8_t res_rotl = F6_8(x, n);
    printf("6. ЦИКЛ. ВЛЕВО (ROL): %d (", res_rotl);
    print_binary_u8(res_rotl);
    printf(")\n");

    // 7. Циклический сдвиг вправо
    uint8_t res_rotr = F7_8(x, n);
    printf("7. ЦИКЛ. ВПРАВО (ROR): %d (", res_rotr);
    print_binary_u8(res_rotr);
    printf(")\n");

    return 0;
}