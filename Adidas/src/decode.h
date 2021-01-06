#ifndef DECODE_H_
#define DECODE_H_

#include <stdint.h>

#define LOWMASK 'ob1111' 
#define P0MASK '0b111'
#define P1MASK '0b1011' 
#define P2MASK '0b1110'
#define P0CHECKMASK '0b10000'
#define P1CHECKMASK '0b100000'
#define P2CHECKMASK '0b1000000'
#define ZEROONEFALSEMASK 'ob1'
#define ZEROTWOFALSEMASK 'ob100'
#define ONETWOFALSEMASK '0b1000'
#define ALLFALSEMASK '0b10'

/*!
 * Combines the nibbles located at the 4-least-significant bits of
 * parameters 'low' and 'high' into one byte.
 *
 * @param high: A nibble that contains the 4 most-significant bits
 * @param low:  A nibble that contains the 4 most-significant bits
 *
 * @return: A byte that combines the high and low nibble.
 */
uint8_t decode_combine_nibbles(uint8_t high, uint8_t low);

/*!
 * Decodes a nibble from a byte that contains the nible (4-bits) and
 * corresponding parity bits (3-bits). See assignment for more details.
 *
 * @param in:     A bytes that contains a nibble and parity bits.
 * @param nibble: The address to which the decoded nibble
 *                of 'in' will be written.
 *
 */
void decode_byte(uint8_t in, uint8_t* nibble);

#endif
