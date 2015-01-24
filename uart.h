#include "interrupt.h"

#ifndef USART0_RX_vect_num
#include <avr/io.h>
#endif

#ifndef F_CPU
//#error Warum zur Hoelle wird F_CPU hier nicht erkannt
#define F_CPU 8000000
#endif

#include "ringbuffer.h"

constexpr uint64_t calcBaudrate(uint64_t baudrate){
// (((F_CPU) + 8 * (BAUD)) / (16 * (BAUD)) -1)
	return (F_CPU + 8 * baudrate) / (16 * baudrate) - 1;
}

template <int uartNum>
class uart{
	int testMichDoch; /* Test - Kann wieder gelöscht werden */
	/* Register */

	ringbuffer<100> sendBuffer;
	ringbuffer<100> receiveBuffer;

	class uartSendInterrupt : public interrupt {
		uart *ownerUART;
		void serviceRoutine();
	public:
		uartSendInterrupt(int intNum, uart *ownerUART);
	} thisUartSendInterrupt;
	friend uartSendInterrupt;

	class uartReceiveInterrupt : public interrupt {
		uart *ownerUART;
		void serviceRoutine();
	public:
		uartReceiveInterrupt(int intNum, uart *ownerUART);
	} thisUartReceiveInterrupt;
	friend uartReceiveInterrupt;
public:
	uart();
	int setBaud(uint16_t baudrate);
	int sendByte(uint8_t byte);
//	int u2x();
	int init();
//	int byteWidth(uint8_t width);
//	int twoStopBits();
	int sendNextByte();
};

template<int uartNum>
uart<uartNum>::uartSendInterrupt::uartSendInterrupt(int intNum, uart *ownerUART) : 
		ownerUART(ownerUART){
	record(intNum, this);
}

template<int uartNum>
void uart<uartNum>::uartSendInterrupt::serviceRoutine(){
	ownerUART->sendNextByte();
}

template<int uartNum>
uart<uartNum>::uartReceiveInterrupt::uartReceiveInterrupt(int intNum, uart *ownerUART) : 
		ownerUART(ownerUART){
	record(intNum, this);
}

template<int uartNum>
void uart<uartNum>::uartReceiveInterrupt::serviceRoutine(){
	ownerUART->testMichDoch = 5;
}

#define UART_RX_OFFSET USART1_RX_vect_num - USART0_RX_vect_num
#define UART_TX_OFFSET USART1_TX_vect_num - USART0_TX_vect_num
template<int uartNum>
uart<uartNum>::uart() : 
		thisUartSendInterrupt(USART0_TX_vect_num + UART_TX_OFFSET * uartNum, this),
		thisUartReceiveInterrupt(USART0_RX_vect_num + UART_RX_OFFSET * uartNum, this){
	init();
}

template<int uartNum>
int uart<uartNum>::setBaud(uint16_t baudrate){
	switch(uartNum){
	    case 0:
	    	UBRR0 = calcBaudrate(baudrate);
		break;
	    case 1:
	    	UBRR1 = calcBaudrate(baudrate);
		break;		
	}
	return 0;

}

template<int uartNum>
int uart<uartNum>::init(){
	switch(uartNum){
	    case 0:
		UCSR0B = (1<<RXCIE0)|(1<<TXEN0)|(1<<RXEN0);
		break;
	    case 1:
		UCSR1B = (1<<RXCIE1)|(1<<TXEN1)|1<<(RXEN1);
		break;		
	}
	return 0;
}

template<int uartNum>
int uart<uartNum>::sendNextByte(){
	switch(uartNum){
	    case 0:
	   	UDR0 = sendBuffer.readValue();
		break;
	    case 1:
	    	UDR1 = sendBuffer.readValue();
		break;		
	}
	return 0;
}

template<int uartNum>
int uart<uartNum>::sendByte(uint8_t byte){
	switch(uartNum){
	    case 0:	    
		if (!(UCSR0A & (1<<UDRE0))){
			/* if there are some outstanding Data in UDR register, don't
			   idle while waiting. Activate interrupt operation and write
			   actual data in the queue */
			if (sendBuffer.readFreeBytes() == 0){
				/* no space left in Buffer */
				return 1;
			}
			sendBuffer.writeValue(byte);
			/* enable interrupt */
			UCSR0B |= (1<<TXCIE0);
			return 0;
		}else{
			UDR0 = byte;
			return 0;
		}		
		break;
	    case 1:
		if (!(UCSR1A & (1<<UDRE1))){
			/* if there are some outstanding Data in UDR register, don't
			   idle while waiting. Activate interrupt operation and write
			   actual data in the queue */
			if (sendBuffer.readFreeBytes() == 0){
				/* no space left in Buffer */
				return 1;
			}
			sendBuffer.writeValue(byte);
			/* enable interrupt */
			UCSR1B |= (1<<TXCIE1);
			return 0;
		}else{
			UDR1 = byte;
			return 0;
		}
		break;		
	}

	return 0;
}