### Fuller Feedback for Lab 08

Run on February 21, 17:24:06 PM.


#### System Files and Lab Directory Structure

+ Pass: Check that directory "googletest" exists.

+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab08_google_tests" exists.

+ Pass: Make directory "Lab08_Testing".

+ Pass: Change into directory "Lab08_Testing".


#### Essential Files Exist

+ Pass: Check that file "../labs/lab08_google_tests/date_unittest.cc" exists.


### Testing correct implementation

+ Pass: Copy directory "Lab08 files.".



+ Pass: Copy directory "Files for correct version".



+ Pass: Change into directory "correct".

+ Fail: Check that make compiles.

    Make compile fails with errors:.
<pre>g++ -isystem ../../googletest/include -g -Wall -Wextra -pthread -c ./date.cc
g++ -isystem ../../googletest/include -g -Wall -Wextra -pthread -c ./date_unittest.cc
./date_unittest.cc: In member function virtual void DateTest_PrintUsDateTest_Test::TestBody():
./date_unittest.cc:189:3: error: output1 was not declared in this scope
   output1 = testing::internal::GetCapturedStdout();
   ^~~~~~~
./date_unittest.cc:193:3: error: output2 was not declared in this scope
   output2 = testing::internal::GetCapturedStdout();
   ^~~~~~~
./date_unittest.cc:197:3: error: output3 was not declared in this scope
   output3 = testing::internal::GetCapturedStdout();
   ^~~~~~~
In file included from ../../googletest/include/gtest/gtest.h:1874:0,
                 from ./date_unittest.cc:1:
./date_unittest.cc:199:3: error: template argument 1 is invalid
   EXPECT_EQ(output1, expected_out_1);
   ^
./date_unittest.cc:200:3: error: template argument 1 is invalid
   EXPECT_EQ(output2, expected_out_2);
   ^
./date_unittest.cc:201:3: error: template argument 1 is invalid
   EXPECT_EQ(output3, expected_out_3);
   ^
Makefile:85: recipe for target 'date_unittest.o' failed
make: *** [date_unittest.o] Error 1
</pre>



+ Skip: Check that file "date_unittest" exists.

  This test was not run because of an earlier failing test.

+ Skip: Get all google tests.

  This test was not run because of an earlier failing test.


#### Results

+ Skip: Check that a GoogleTest test passes.

  This test was not run because of an earlier failing test.

+ Skip: Check that a GoogleTest test passes.

  This test was not run because of an earlier failing test.

+ Skip: Check that a GoogleTest test passes.

  This test was not run because of an earlier failing test.

+ Skip: Check that a GoogleTest test passes.

  This test was not run because of an earlier failing test.

+ Skip: Check that a GoogleTest test passes.

  This test was not run because of an earlier failing test.

+ Skip: Check that a GoogleTest test passes.

  This test was not run because of an earlier failing test.

+ Skip: Check that a GoogleTest test passes.

  This test was not run because of an earlier failing test.

+ Skip: Check that a GoogleTest test passes.

  This test was not run because of an earlier failing test.

+ Skip: Check that a GoogleTest test passes.

  This test was not run because of an earlier failing test.

+ Skip: Check that a GoogleTest test passes.

  This test was not run because of an earlier failing test.


### Testing Mutants


#### Testing Mutant 1 for failure

+ Pass: At least one test failed for Mutant 1


#### Testing Mutant 2 for failure

+ Pass: At least one test failed for Mutant 2


#### Testing Mutant 3 for failure

+ Pass: At least one test failed for Mutant 3


#### Testing Mutant 4 for failure

+ Pass: At least one test failed for Mutant 4


#### Testing Mutant 5 for failure

+ Pass: At least one test failed for Mutant 5


#### Testing Mutant 6 for failure

+ Pass: At least one test failed for Mutant 6


#### Testing Mutant 7 for failure

+ Pass: At least one test failed for Mutant 7


#### Testing Mutant 8 for failure

+ Pass: At least one test failed for Mutant 8


#### Testing Mutant 9 for failure

+ Pass: At least one test failed for Mutant 9

