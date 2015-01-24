#define F_CPU 8000000
#include <avr/io.h>
#include "uart.h"
#include <avr/interrupt.h>
#include <util/delay.h>


int main(){
	sei();
	uart<0> serial;
	uart<1> soreal;
	serial.setBaud(9600);
	soreal.setBaud(9600);
	serial.init();
	while(42){
		serial.sendByte(42);
		soreal.sendByte(23);
		_delay_ms(10);
	}
}