/* This library provides a ringbuffer memory structure with a flexible size.
 * In the current state of implementation, there is only the possibility to
 * read saved data once. You can only access data in the order written to the
 * memory. There are only two methods available, one for reading, one for
 * writing. For future extentions, it would be nice to determine the data
 * type of the variable for the array size, by this size in preprocessor soft-
 * ware.
 *
 * To initialize a new ringbuffer, you need to give them the information about
 * the data type and size by:
 *
 * 	ringbuffer<${DATA_TYPE}, ${SIZE}> varname;
 */
#include <avr/io.h>

template<uint8_t size>
class ringbuffer{
	uint8_t freeBytes = size;
	uint8_t writePosition = 0;
	uint8_t array[size];
public:
	ringbuffer();
	int writeValue(uint8_t byte);
	uint8_t readValue();
	uint8_t outstandingValues();
	uint8_t readFreeBytes();
};

/* Constructor for this memory structure */
template<uint8_t size>
ringbuffer<size>::ringbuffer(){
}

/* Method for writing Values to the structure */
template<uint8_t size>
int ringbuffer<size>::writeValue(uint8_t byte){
	if(freeBytes != 0){
		array[writePosition++] = byte;
		uint8_t tmp = writePosition % size;
		writePosition = tmp;
		--freeBytes;
		return 0;
	}else{
		/* no space left in array! */
		return 1;
	}
}

/* method for reading values from this structure */
template<uint8_t size>
uint8_t ringbuffer<size>::readValue(){
	/* no reasonable error handling in absentia of readable values! */
	uint8_t tmp = (writePosition + freeBytes++) % size;
	return array[tmp];
}

/* return the number of unread values */
template<uint8_t size>
uint8_t ringbuffer<size>::outstandingValues(){
	return size - freeBytes;
}

template<uint8_t size>
uint8_t ringbuffer<size>::readFreeBytes(){
	return freeBytes;
}