#ifndef PARITY3_H_
#define PARITY3_H_

#include <array>
#include "parity1.h"
using std::array;

namespace Parity3 {

array<short, 1 << 16> BuildTable() {
  array<short, 1 << 16> result;
  for (int i = 0; i < (1 << 16); ++i) {
    result[i] = Parity1::Parity(i);
  }
  return result;
}

static array<short, 1 << 16> precomputed_parity = BuildTable();

// @include
short Parity(unsigned long x) {
  const int kMaskSize = 16;
  const int kBitMask = 0xFFFF;
  return precomputed_parity[x >> (3 * kMaskSize)] ^
         precomputed_parity[(x >> (2 * kMaskSize)) & kBitMask] ^
         precomputed_parity[(x >> kMaskSize) & kBitMask] ^
         precomputed_parity[x & kBitMask];
}
// @exclude

}  // namespace Parity3

#endif  // PARITY3_H_