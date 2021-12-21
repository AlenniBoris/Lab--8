#include "Stack.h"
#include "gtest/gtest.h"


TEST(StackGetSize, StackInt){
    Stack<int> stack1;
    stack1.push(3);
    stack1.push(5);
    stack1.push(4);
    stack1.push(2);
    ASSERT_EQ(stack1.getSize(),4);
}

TEST(StackGetSize, StackInt2){
    Stack<int> stack1;
    stack1.push(3);
    stack1.push(5);
    stack1.push(4);
    stack1.push(2);
    stack1.push(0);
    stack1.push(18);
    ASSERT_EQ(stack1.getSize(),6);
}

TEST(StackGetSize, StackChar){
    Stack<char> stack1;
    stack1.push('a');
    stack1.push('v');
    stack1.push('s');
    stack1.push('a');
    stack1.push('q');
    stack1.push('t');
    ASSERT_EQ(stack1.getSize(),6);
}

TEST(StackGetSize, StackDouble){
    Stack<double> stack1;
    stack1.push(3.558);
    stack1.push(5.488848);
    stack1.push(-4);
    stack1.push(2.008);
    stack1.push(0.000);
    ASSERT_EQ(stack1.getSize(),5);
}

TEST(StackTop, StackDouble){
    Stack<double> stack1;
    stack1.push(3.558);
    stack1.push(5.488848);
    stack1.push(-4);
    stack1.push(2.008);
    ASSERT_EQ(stack1.top(),2.008);
}
TEST(StackTop, StackChar){
    Stack<char> stack1;
    stack1.push('a');
    stack1.push('v');
    stack1.push('s');
    stack1.push('a');
    stack1.push('q');
    stack1.push('t');
    ASSERT_EQ(stack1.top(),'t');
}
TEST(StackTop, StackInt){
Stack<int> stack1;
    stack1.push(3);
    stack1.push(5);
    stack1.push(4);
    stack1.push(2);
    stack1.push(0);
    stack1.push(18);
    ASSERT_EQ(stack1.top(),18);
}
TEST(GetNumByIndex, StackInt){
    Stack<int> stack1;
    stack1.push(3);
    stack1.push(5);
    stack1.push(4);
    stack1.push(2);
    stack1.push(0);
    stack1.push(18);
    ASSERT_EQ(stack1[2],0);
}
TEST(GetNumByIndex, StackChar){
    Stack<char> stack1;
    stack1.push('a');
    stack1.push('v');
    stack1.push('s');
    stack1.push('a');
    stack1.push('q');
    stack1.push('t');
    ASSERT_EQ(stack1[2],'q');
}
TEST(TestLogic, StackChar){
    Stack<char> stack1;
    stack1.push('a');
    stack1.push('v');
    stack1.push('s');
    stack1.push('a');
    stack1.push('q');
    stack1.push('t');

    Stack<char> stack2;
    stack2.push('a');
    stack2.push('v');
    stack2.push('s');
    stack2.push('a');
    stack2.push('q');

    ASSERT_EQ(stack1 < stack2,false);
}
TEST(TestLogic, StackChar2){
    Stack<char> stack1;
    stack1.push('a');
    stack1.push('v');
    stack1.push('s');
    stack1.push('a');
    stack1.push('q');
    stack1.push('t');

    Stack<char> stack2;
    stack2.push('a');
    stack2.push('v');
    stack2.push('s');
    stack2.push('a');
    stack2.push('q');

    ASSERT_EQ(stack1 > stack2,true);
}
TEST(TestLogic, StackChar3){
    Stack<char> stack1;
    stack1.push('a');
    stack1.push('v');
    stack1.push('s');
    stack1.push('a');
    stack1.push('q');
    stack1.push('t');

    Stack<char> stack2;
    stack2.push('a');
    stack2.push('v');
    stack2.push('s');
    stack2.push('a');
    stack2.push('q');

    ASSERT_EQ(stack1 == stack2,false);
}
    TEST(TestLogic, StackInt){
    Stack<int> stack1;
    stack1.push(3);
    stack1.push(5);
    stack1.push(4);
    stack1.push(2);
    stack1.push(0);
    stack1.push(18);

    Stack<int> stack2;
    stack2.push(3);
    stack2.push(5);
    stack2.push(4);
    stack2.push(2);
    stack2.push(0);
    stack2.push(18);

    ASSERT_EQ(stack1[2] > stack2[1],false);
}
TEST(TestLogic, StackInt2){
    Stack<int> stack1;
    stack1.push(3);
    stack1.push(5);
    stack1.push(4);
    stack1.push(2);
    stack1.push(0);
    stack1.push(18);

    Stack<int> stack2;
    stack2.push(3);
    stack2.push(5);
    stack2.push(4);
    stack2.push(2);
    stack2.push(0);
    stack2.push(18);

    ASSERT_EQ(stack1[5] < stack2[1],true);
}
TEST(TestLogic, StackInt3){
    Stack<int> stack1;
    stack1.push(3);
    stack1.push(5);
    stack1.push(4);
    stack1.push(2);
    stack1.push(0);
    stack1.push(18);

    Stack<int> stack2;
    stack2.push(3);
    stack2.push(5);
    stack2.push(4);
    stack2.push(2);
    stack2.push(0);
    stack2.push(18);

    ASSERT_EQ(stack1[2] == stack2[2],true);
}
TEST(StackEmpty, StackChar){
    Stack<char> stack1;
    stack1.push('a');
    stack1.push('v');
    stack1.push('s');
    stack1.push('a');
    stack1.push('q');
    stack1.push('t');
    ASSERT_EQ(stack1.isEmpty(),false);
}
TEST(StackEmpty, StackChar2){
    Stack<char> stack1;
    ASSERT_EQ(stack1.isEmpty(),true);
}