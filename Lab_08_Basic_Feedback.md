### Basic Feedback for Lab 08

Run on February 22, 15:39:12 PM.


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
ar rv gtest_main.a gtest-all.o gtest_main.o
r - gtest-all.o
r - gtest_main.o
g++ -isystem ../../googletest/include -g -Wall -Wextra -pthread date.o date_unittest.o gtest_main.a -o date_unittest
gtest_main.a: error adding symbols: Archive has no index; run ranlib to add one
collect2: error: ld returned 1 exit status
Makefile:88: recipe for target 'date_unittest' failed
make: *** [date_unittest] Error 1
</pre>



+ Skip: Check that file "date_unittest" exists.

  This test was not run because of an earlier failing test.

+ Skip: Get all google tests.

  This test was not run because of an earlier failing test.


#### Results


### Testing Mutants


***Note: This is just the basic feedback.  The feedback that includes the following mutants is run daily as a batch process (click link below)***


Link to full feedback: [Lab_08_Feedback.md](Lab_08_Feedback.md)



 __Below are the mutants that your tests will need to find for the Feedback__:


 * __Mutant:__ Dates constructed with epoch are about 70 years in the future


 * __Mutant:__ Days between calculation seems to be much larger than it should be.


 * __Mutant:__ Dates from GetDate are missing a character


 * __Mutant:__ Todays date month off by one


 * __Mutant:__ 1/1/2016 to 3/1/2016 is 60 days, but this version returns 59


 * __Mutant:__ Dates from GetUsDate are not in the right format (same as GetDate?)


 * __Mutant:__ operator-: Probably a copy paste error


 * __Mutant:__ Developer thought months should be zero-indexed


 * __Mutant:__ Some dates dont have leading zeroes

