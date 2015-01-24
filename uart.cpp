#include "uart.h"

/*
uart::uart(int uart) : 
		thisUartSendInterrupt(USART0_TX_vect_num + UART_TX_OFFSET * uart, this),
		thisUartReceiveInterrupt(USART0_RX_vect_num + UART_RX_OFFSET * uart, this),
		uartNumber(uart){
//	uartNumber = uart;
//	asm("nop");
}
*/
//uart::uart(int uart) : 
//		thisUartSendInterrupt(USART0_TX_vect_num + UART_TX_OFFSET * uart, this),
//		thisUartReceiveInterrupt(USART0_RX_vect_num + UART_RX_OFFSET * uart, this),
//		uartNumber(uart){
////	uartNumber = uart;
////	asm("nop");
//}

//uartSendInterrupt::uartSendInterrupt(int intNum, uart *ownerUART) : 
//		ownerUART(ownerUART){
//	record(intNum, this);
//}
//
//void uartSendInterrupt::serviceRoutine(){
//	ownerUART->SendNextByte();
//}

//uartReceiveInterrupt::uartReceiveInterrupt(int intNum, uart *ownerUART) : 
//		ownerUART(ownerUART){
//	record(intNum, this);
//}
//
//void uartReceiveInterrupt::serviceRoutine(){
//	ownerUART->SendNextByte();
//}
//
//int uart::sendByte(uint8_t byte){
//	while (!(UCSR0A & (1<<UDRE0)));
//	UDR0 = byte;
//}
//
//int uart::setBaud(uint16_t baudrate){
//	(uartNumber == 1 ? UBRR1 : UBRR0) = F_CPU / (8 * baudrate) - 1;
//}
//
//int uart::u2x(){
//	(uartNumber == 1 ? UCSR1A : UCSR0A) |= (1<<(uartNumber == 1 ? U2X1 : U2X0));
//	return 0;
//}
//
//int uart::init(){
//	if (uartNumber == 0){
//		*UCSRA = UCSR0A;
//		*UCSRB = UCSR0B;
//		*UCSRC = UCSR0C;
//		*UBRRL = UBRR0L;
//		*UBRRH = UBRR0H;
//	}else if(uartNumber == 1){
//		*UCSRA = UCSR1A;
//		*UCSRB = UCSR1B;
//		*UCSRC = UCSR1C;
//		*UBRRL = UBRR1L;
//		*UBRRH = UBRR1H;		
//	}
////	(uartNumber == 1 ? UCSR1B : UCSR0B) |= (uartNumber == 0 ? ((1<<RXCIE0)|(1<<TXEN0)|1<<(RXEN0)) : ((1<<RXCIE1)|(1<<TXEN1)|1<<(RXEN1)));
//	*UCSRB |= (uartNumber == 0 ? ((1<<RXCIE0)|(1<<TXEN0)|1<<(RXEN0)) : ((1<<RXCIE1)|(1<<TXEN1)|1<<(RXEN1)));
//	return 0;
//}
//
//int uart::byteWidth(uint8_t width){
//	/* Accept only values between 5 and 8 bits */
//	(uartNumber == 1 ? UCSR1B : UCSR0B) |= ((width - 5)<<(uartNumber == 1 ? UCSZ10 : UCSZ00));
//}
//
//int uart::twoStopBits(){
//	(uartNumber == 1 ? UCSR1B : UCSR0B) |= (1<<(uartNumber == 1 ? USBS1 : USBS0));
//}