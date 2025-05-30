#include "debug.h"

const uint8_t segment_map[10][7] = {
    {1,1,1,1,1,1,0}, // 0
    {0,1,1,0,0,0,0}, // 1
    {1,1,0,1,1,0,1}, // 2
    {1,1,1,1,0,0,1}, // 3
    {0,1,1,0,0,1,1}, // 4
    {1,0,1,1,0,1,1}, // 5
    {1,0,1,1,1,1,1}, // 6
    {1,1,1,0,0,0,0}, // 7
    {1,1,1,1,1,1,1}, // 8
    {1,1,1,1,0,1,1}  // 9
};

void display_digit(uint8_t digit)
{
    // Inverses Mapping wegen common-anode (LOW = an)
    if (digit > 9) return;

    // Setze alle Segmentpins aus
    GPIO_WriteBit(GPIOC, GPIO_Pin_4, segment_map[digit][0] ? Bit_RESET : Bit_SET); // a
    GPIO_WriteBit(GPIOC, GPIO_Pin_0, segment_map[digit][1] ? Bit_RESET : Bit_SET); // b
    GPIO_WriteBit(GPIOD, GPIO_Pin_2, segment_map[digit][2] ? Bit_RESET : Bit_SET); // c
    GPIO_WriteBit(GPIOC, GPIO_Pin_7, segment_map[digit][3] ? Bit_RESET : Bit_SET); // d
    GPIO_WriteBit(GPIOC, GPIO_Pin_6, segment_map[digit][4] ? Bit_RESET : Bit_SET); // e
    GPIO_WriteBit(GPIOC, GPIO_Pin_3, segment_map[digit][5] ? Bit_RESET : Bit_SET); // f
    GPIO_WriteBit(GPIOD, GPIO_Pin_3, segment_map[digit][6] ? Bit_RESET : Bit_SET); // g
}

void select_digit(uint8_t digit)
{
    // Clear all digit control lines first
    GPIO_WriteBit(GPIOC, GPIO_Pin_5, Bit_RESET);
    GPIO_WriteBit(GPIOC, GPIO_Pin_2, Bit_RESET);
    GPIO_WriteBit(GPIOC, GPIO_Pin_1, Bit_RESET);
    GPIO_WriteBit(GPIOD, GPIO_Pin_4, Bit_RESET);

    // Enable only the selected digit
    switch (digit) {
        case 0:
            GPIO_WriteBit(GPIOC, GPIO_Pin_5, Bit_SET);
            break;
        case 1:
            GPIO_WriteBit(GPIOC, GPIO_Pin_2, Bit_SET);
            break;
        case 2:
            GPIO_WriteBit(GPIOC, GPIO_Pin_1, Bit_SET);
            break;
        case 3:
            GPIO_WriteBit(GPIOD, GPIO_Pin_4, Bit_SET);
            break;
        default:
            // Invalid index, do nothing
            break;
    }
}
void display_number(uint16_t value)
{
    if (value > 9999) value = 9999;

    // Extract digits (from most significant to least significant)
    uint8_t digits[4] = {
        (value / 1000) % 10,
        (value / 100) % 10,
        (value / 10) % 10,
        value % 10
    };

    for (int i = 0; i < 4; i++) {
        select_digit(i);           // Enable digit i
        display_digit(digits[i]);  // Set segment pattern for that digit
        Delay_Ms(1);               // On-time = 2 ms ¡ú 1/10 multiplex cycle
    }
    GPIO_WriteBit(GPIOC, GPIO_Pin_5, Bit_RESET);
    GPIO_WriteBit(GPIOC, GPIO_Pin_2, Bit_RESET);
    GPIO_WriteBit(GPIOC, GPIO_Pin_1, Bit_RESET);
    GPIO_WriteBit(GPIOD, GPIO_Pin_4, Bit_RESET);
    Delay_Ms(9);
}