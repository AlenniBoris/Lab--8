#include "Calculator.h"
#include "gtest/gtest.h"

TEST(IsOperation, Test_Operation) {
    char Symbols[5] = {'+', '-', '*', '/', '^'};
    ASSERT_EQ(Operation(Symbols[0]),true);
    ASSERT_EQ(Operation(Symbols[1]),true);
    ASSERT_EQ(Operation(Symbols[2]),true);
    ASSERT_EQ(Operation(Symbols[3]),true);
    ASSERT_EQ(Operation(Symbols[4]),true);
}

TEST(Priority, Test_Priority) {
    char Symbols[5] = {'+', '-', '*', '/', '^'};
    ASSERT_EQ(OperationPriority(Symbols[0]),1);
    ASSERT_EQ(OperationPriority(Symbols[1]),1);
    ASSERT_EQ(OperationPriority(Symbols[2]),2);
    ASSERT_EQ(OperationPriority(Symbols[3]),2);
    ASSERT_EQ(OperationPriority(Symbols[4]),3);
}
TEST(Calculate_Test, Test_Without_Equation) {
    double Numbers[6] = {2, 5.5, 100, -40, 9.7, 3.3};

    ASSERT_EQ(Calculate(Numbers[0], Numbers[2], '+'),102);
    ASSERT_EQ(Calculate(Numbers[1], Numbers[3], '-'),45.5);
    ASSERT_EQ(Calculate(Numbers[0], Numbers[5], '*'),6.6);
    ASSERT_EQ(Calculate(Numbers[2], Numbers[0], '/'),50);
    ASSERT_EQ(Calculate(Numbers[2], Numbers[0], '^'),10000);
}
TEST(Calculate_Test, Test_With_Two_Numbers) {
    string Eq1 = "-9+9";
    ASSERT_EQ(Polish(Eq1),0);
}
TEST(Calculate_Test, Test_With_Four_Negative) {
    string Eq1 = "-1-2-3-4";
    ASSERT_EQ(Polish(Eq1),-10);
}
TEST(Calculate_Test, Test_With_PlusMinus) {
    string Eq1 = "7+-5";
    ASSERT_EQ(Polish(Eq1),2);
}
TEST(Calculate_Test, Test_With_SeveralNumbersAndPlusMinus) {
    string Eq1 = "7+-8+-5+-1";
    ASSERT_EQ(Polish(Eq1),-7);
}
TEST(Calculate_Test, Test_With_Multiply) {
    string Eq1 = "-2*5";
    ASSERT_EQ(Polish(Eq1),-10);
}
TEST(Calculate_Test, Test_With_MultiplyAbdBrackets) {
    string Eq1 = "-(8+8)*3";
    ASSERT_EQ(Polish(Eq1),-48);
}
TEST(Calculate_Test, Test_With_Degree) {
    string Eq1 = "(7^2+51)/100+9^2+2^4+2";
    ASSERT_EQ(Polish(Eq1),100);
}
TEST(Calculate_Test, Test_With_DegreeAndNegative) {
    string Eq1 = "-78-32+11^2";
    ASSERT_EQ(Polish(Eq1),11);
}
TEST(Calculate_Test, Test_With_Brackets) {
    string Eq1 = "(11-9)*28";
    ASSERT_EQ(Polish(Eq1),56);
}
TEST(Calculate_Test, Test_With_DoubleNumbers) {
    string Eq1 = "5.6+89-(6.1)^2+766.877";
    ASSERT_DOUBLE_EQ(Polish(Eq1),824.267);
}
