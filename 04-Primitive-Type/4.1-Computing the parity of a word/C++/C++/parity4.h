#ifndef PARITY4_H_
#define PARITY4_H_

namespace Parity4 {

// @include
short Parity(unsigned long x) {
  x ^= x >> 32;
  x ^= x >> 16;
  x ^= x >> 8;
  x ^= x >> 4;
  x ^= x >> 2;
  x ^= x >> 1;
  return x & 0x1;
}
// @exclude

}  // namespace Parity4

#endif  // PARITY4_H_