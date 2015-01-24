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

#include "ringbuffer.h"

