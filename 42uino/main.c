#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    /* DDRB |= (1 << PB3);  // Digital pin 13 (D13) --> builtin LED */
    DDRH |= (1 << PH6);
    /* DDRB |= (1 << PB1);  // Digital pin 9 (D9) */ 

    while (1) {
        /* PORTB |= (1 << PB3); */
        PORTH |= (1 << PH6);
        /* PORTB |= (1 << PB1); */
        _delay_ms(100);
        /* PORTB &= ~(1 << PB3); */
        PORTH &= ~(1 << PH6);
        /* PORTB &= ~(1 << PB1); */
        _delay_ms(100);
    }
}


