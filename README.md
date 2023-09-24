# Paranthesis Balance
Did you ever wonder how text editors and IDE's check for paranthesis balance in your code? They are using "stacks". In this little project I've implemented a paranthesis balance checker in C.

## Paranthesis Balance
In a string containing paranthesis, there should be a balance. For every opening paranthesis or brackets, there should be a closing one in the right place.

`( [ ] )` is a valid string while
`( [ ) ]` is not although every opening paranthesis or brackets have a closing counterpart.

## How to Check Their Balance
Basically, the algorith is: every time there is an occurance of an opening paranthesis in a string while iterating over it, you push it to a stack and anytime there is an occurance of a closing paranthesis you check if the stack is empty, if the stack is empty that means the first paranthesis occurance in that string is a closing paranthesis so you return false. If not empty, you take the top of the stack, if it is the opening counterpart of the closing paranthesis you pop the top of the stack.

eventually if you end up with an empty stack, that means that the string is valid paranthesis-wise otherwise it is not.

- Initialize a char stack
- Iterate the passed in expression
  + If the current character is an opening paranthesis push it to the stack
  + If not, and stack is empty return false
  + If not, and top of the stack is the opening counterpart of the current character pop the top element in the stack.
- When the iteration is over, if the stack is empty return true else return false.

## Source
- [freeCodeCamp (starting from 3:32:19)](https://www.youtube.com/watch?v=B31LgI4Y4DQ)
- [GFG Article](https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/)
