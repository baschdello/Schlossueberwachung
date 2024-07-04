#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
ISR (TIM0_OVF_vect) {
	PORTB ^= (1<<PB3);
	TCNT0 = 180;
}
int main(void)
{
	DDRB |= (1<<PB3);
	uint16_t i = 0;
	TCCR0B |= ((1<<CS00)); // no prescaling
	TIMSK0 |= (1<<TOIE0); // interrupt enable
	sei();	// global interrupts

	while(1) {
		/*if(i++ >= 2) {
			PORTB ^= (1<<PB3);
			i = 0;
		}*/
	}
	return 0;
}
