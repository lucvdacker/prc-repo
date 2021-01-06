#ifndef ENCODE_H_
#define ENCODE_H_

#include <stdbool.h>
#include <stdint.h>

#define LOWMASK 'ob1111' 
#define P0MASK '0b111'
#define P1MASK '0b1011' 
#define P2MASK '0b1110'

/*!
 * Split a byte 'value' into two nibbles (4-bits) named 'low' and 'high'.
 * See assignment for more details.
 *
 * @param value: A byte that will be encoded.
 * @param low:   The address to which the 4 least-significant-bits
 *               of 'value' will be written.
 * @param high:  The address to which the 4 most-significant-bits
 *               of 'value' will be written.
 */
void encode_get_nibbles(uint8_t value, uint8_t* low, uint8_t* high);

/*!
 * Encodes a the byte 'value' into two bytes named 'low' and 'high'.
 * The encoded bytes contain the parity bits. See assignment for more details.
 *
 * @param value: A byte that will be encoded.
 * @param low:   The address to which the encoded value of the
 *               4 least-significant-bits of 'value' will be written.
 * @param high:  The address to which the encoded value of the
 *               4 most-significant-bits of 'value' will be written.
 */
void encode_value(uint8_t input, uint8_t* high, uint8_t* low);

int calculateParity(uint8_t toEncode);

#endif
