/*
 * Code snippets for bit level and  operations on microcontroller registers
 */

#include <stdint.h>
#include <stdio.h>

int main() {
  uint32_t a = 0x00000000;
  uint8_t bit = 6;
  
  // one bit up
  a |= (1U << bit);
  printf("%b\n", a);
  // one bit down
  a &= ~(1U << bit);
  printf("%b\n", a);
  // toggling a bit with xor
  a ^= (1U << bit);

  // for more than a bit, in general one must blank first, and write then.
  // Writing hex B to the fourth hex digit
  a &= ~(0xFU << 16);
  a |= (0xBU << 16);
  printf("%x\n", a);
  
  return 0;
}
