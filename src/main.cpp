#include "upsi.hpp"

#include "cuckoofilter.h"

using namespace std;

using CuckooFilter = cuckoofilter::CuckooFilter<
    uint64_t *, 32, cuckoofilter::SingleTable,
    cuckoofilter::TwoIndependentMultiplyShift128>;

void test() {
  u64 ns = 1 << 20;
  vector<block> elements(ns);
  for (u64 i = 0; i < ns; ++i) {
    elements[i] = oc::toBlock(i);
  }

  CuckooFilter f0(ns);
  cout << f0.Contain((u64 *) &elements[1]) << endl;
  for (u64 i = 0; i < ns - 1; ++i) {
    f0.Add((u64 *) &elements[i]);
  }
  cout << f0.Contain((u64 *) &elements[1]) << endl;

  cout << f0.Info() << endl;
  vector<u8> data = f0.serialize();
  cout << data.size() << endl;
  auto param = f0.GetTwoIndependentMultiplyShiftParams();

  CuckooFilter f1(ns);
  cout << f1.Info() << endl;
  cout << f1.Contain((u64 *) &elements[1]) << endl;
  f1.deserialize(data);
  f1.SetTwoIndependentMultiplyShiftParams(param);
  cout << f1.Info() << endl;
  cout << f1.Contain((u64 *) &elements[1]) << endl;
  cout << f1.Contain((u64 *) &elements[ns - 1]) << endl;
}

int main(int argc, char **argv) {
  upsi::main(argc, argv);
}
