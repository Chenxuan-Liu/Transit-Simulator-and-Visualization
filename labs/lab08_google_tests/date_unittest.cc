#include "gtest/gtest.h"

#include <iostream>
#include <math.h>
#include <ctime>

#include "date.h"


class DateTest : public ::testing::Test {
 public:
  void SetUp( ) { 
    // code here will execute just before the test ensues 
	first_day = Date(2018, 9, 4);
	last_day = Date(2018, 12, 11);
  }
 protected:
  Date first_day;          // first day of classes
  Date last_day;           // last day of classes
};



TEST_F(DateTest, PrintDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "1999-12-31\n";
  std::string expected_out_2 = "1776-07-04\n";
  std::string expected_out_3 = "2018-10-31\n";
  
  testing::internal::CaptureStdout();
  y2k.PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-10-31";
  
  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

/**
  *
  * Note, this is the only provided test case which actually uses our test fixture
  * 
  * However, it is illegal to mix TEST() and TEST_F() in the same test case (file).
  *
  */

TEST_F(DateTest,ConstructorTest1){
  Date today;

  std::time_t t = std::time(0);
  std::tm* now = std::localtime(&t);
  
  //tm year's value is years since 1900
  int yyyy_ = now->tm_year + 1900;
  //tm month's value is zero-indexed
  int mm_ = now->tm_mon+1;
  //tm day's value is one-indexed
  int dd_ = now->tm_mday;

  Date ExpectDate(yyyy_,mm_,dd_);

  EXPECT_STREQ(today.GetDate().c_str(), ExpectDate.GetDate().c_str());
}

TEST_F(DateTest,ConstructorTest2){
  int _epoch = 999999999;
  Date best_day = Date(_epoch);

  std::time_t epoch_t = _epoch;
  std::tm* yyyy_mm_dd = std::gmtime( &epoch_t );
  
  //tm year's value is years since 1900
  int yyyy_ = yyyy_mm_dd->tm_year + 1900;
  //tm month's value is zero-indexed
  int mm_ = yyyy_mm_dd->tm_mon + 1;
  //tm day's value is one-indexed
  int dd_ = yyyy_mm_dd->tm_mday;

  Date ExpectDate(yyyy_,mm_,dd_);
  EXPECT_EQ(best_day.GetDate(),ExpectDate.GetDate());
}

TEST_F(DateTest,OperatorPlusTest){
  Date y2k(1999, 12, 31);              // y2k
  Date y2k_(2000, 1, 29);
  Date ind_day(1776, 7, 4);            // US Independence
  Date ind_day_(1776,6,30);
  Date best_holiday(2018, 10, 31);     // Halloween
  Date best_holiday_(2018,11,4);

  EXPECT_EQ((y2k+29).GetDate(),y2k_.GetDate());
  EXPECT_EQ((ind_day+(-4)).GetDate(),ind_day_.GetDate());
  EXPECT_EQ((best_holiday+4).GetDate(),best_holiday_.GetDate());
}

TEST_F(DateTest,OperatorMinusTest){
  Date y2k(1999, 12, 31);              // y2k
  Date y2k_(2000, 1, 29);
  Date ind_day(1776, 7, 4);            // US Independence
  Date ind_day_(1776,6,30);
  Date best_holiday(2018, 10, 31);     // Halloween
  Date best_holiday_(2018,10,27);

  EXPECT_EQ((y2k-(-29)).GetDate(),y2k_.GetDate());
  EXPECT_EQ((ind_day-4).GetDate(),ind_day_.GetDate());
  EXPECT_EQ((best_holiday-4).GetDate(),best_holiday_.GetDate());
}



TEST_F(DateTest, GetDateTest){  
  //Mutant 1
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  EXPECT_EQ(y2k.GetDate(), "1999-12-31");
  EXPECT_EQ(ind_day.GetDate(), "1776-07-04");
  EXPECT_EQ(best_holiday.GetDate(),"2018-10-31");

  //Mutant 2
  Date y2k_(1999, 02, 01);              // y2k
  Date ind_day_(1776, 7, 4);            // US Independence
  Date best_holiday_(2018, 1, 01);     // Halloween

  EXPECT_EQ(y2k_.GetDate(), "1999-02-01");
  EXPECT_EQ(ind_day_.GetDate(), "1776-07-04");
  EXPECT_EQ(best_holiday_.GetDate(),"2018-01-01");

}

TEST_F(DateTest,GetUsDateTest){
  //mutant 2&4
  Date y2k(1999, 02, 01);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 1, 01);     // Halloween

  EXPECT_EQ(y2k.GetUsDate(), "02-01-1999");
  EXPECT_EQ(ind_day.GetUsDate(), "07-04-1776");
  EXPECT_EQ(best_holiday.GetUsDate(),"01-01-2018");

  Date today;

  std::time_t t = std::time(0);
  std::tm* now = std::localtime(&t);
  
  //tm year's value is years since 1900
  int yyyy_ = now->tm_year + 1900;
  //tm month's value is zero-indexed
  int mm_ = now->tm_mon+1;
  //tm day's value is one-indexed
  int dd_ = now->tm_mday;

  Date ExpectDate(yyyy_,mm_,dd_);

  //Mutant 3
  EXPECT_STREQ(today.GetUsDate().c_str(), ExpectDate.GetUsDate().c_str());
}

TEST_F(DateTest,PrintDateTest){
  //mutant 2
  Date y2k(1999, 02, 01);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 1, 01);     // Halloween

  std::string expected_out_1 = "1999-02-01";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-01-01";
  
  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);

}

TEST_F(DateTest,PrintUsDateTest){
  //Mutant 2
  Date y2k(1999, 02, 01);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 1, 01);     // Halloween

  std::string expected_out_1 = "02-01-1999";
  std::string expected_out_2 = "07-04-1776";
  std::string expected_out_3 = "01-01-2018";
  
  testing::internal::CaptureStdout();
  y2k.PrintUsDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  ind_day.PrintUsDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintUsDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}
  
TEST_F(DateTest, DaysBetweenTests) {
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Last day of class not setup properly";
  EXPECT_EQ(first_day.DaysBetween(last_day), 98) << "Days between is not calculated properly";
}

/**
  *
  * NOPE!  Can't test PRIVATE methods
  *
  */
/*
TEST(DateTest, ConvertFromDays) {
	Date convert_first_day = ConvertToDays(2458365);
	EXPECT_STREQ(convert_first_day.GetUsDate(), "09-04-2018");
}
*/
