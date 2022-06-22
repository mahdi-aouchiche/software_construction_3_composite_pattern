/* add all the test files to run */
#include "../header/op_test.hpp"
#include "../header/rand_test.hpp"
#include "../header/add_test.hpp"
#include "../header/sub_test.hpp"
#include "../header/mult_test.hpp"
#include "../header/div_test.hpp"
#include "../header/pow_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
