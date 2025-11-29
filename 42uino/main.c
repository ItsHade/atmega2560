#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    DDRB |= (1 << PB5);  // Digital pin 13 (D13) --> builtin LED */
    DDRB |= (1 << PB1);  // Digital pin 9 (D9) */ 

    while (1) {
        PORTB ^= (1 << PB5);
        PORTB ^= (1 << PB1);
        _delay_ms(100);
    }
}


