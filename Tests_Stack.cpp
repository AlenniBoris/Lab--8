#include "Stack.h"
#include "gtest/gtest.h"


TEST(StackTryMethods, StackInt){
    Stack<int> stack1;
    stack1.push(3);
    stack1.push(5);
    stack1.push(4);
    stack1.push(2);

    ASSERT_EQ(stack1.getSize(),4);
    ASSERT_EQ(stack1.top(),2);
    ASSERT_EQ(stack1.isEmpty(),false);
    ASSERT_EQ(stack1[3],5);
}

TEST(StackTryMethods, EmptyStack){
    Stack<int> stack1;
    ASSERT_EQ(stack1.isEmpty(),true);

}

TEST(StackTryMethods, StackDouble){
    Stack<double> stack1;
    stack1.push(2.222);
    stack1.push(1.111);
    ASSERT_EQ(stack1.pop(),1.111);

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

    ASSERT_EQ(stack1 < stack2, false);
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
    ASSERT_EQ(stack1[2] == stack2[2], true);
    ASSERT_EQ(stack1[1] > stack2[3], true);

}

