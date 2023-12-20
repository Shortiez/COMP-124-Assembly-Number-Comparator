#include <stdio.h> 
#include <stdlib.h> 

int main(void) {

    // Declare variables here (C syntax) 
    int _positiveCount = 0;
    int _negativeCount = 0;
    int _zeroCount = 0;
    
    char _fmt[] = "%d";

    char _loopAmountMessage[] = "How many numbers: ";
    int _loopAmount;

    char _numberInputMessage[] = "Enter a number: ";
    int _currentNumber;

    char _seperatorMessage[] = "------------\n";
    char _positiveMessage[] = "Positive: %d\n";
    char _negativeMessage[] = "Negative: %d\n";
    char _zerosMessage[] = "Zero: %d\n";

    _asm {
        
        // Put assembly code here 
        lea eax, _loopAmountMessage// Gets the address of loop amount message
        push eax                   // Pushes the address of loop amount message
        call printf
        add esp, 8                 // Cleans up stack

        lea eax, _loopAmount       // Gets the address of loop amount
        push eax                   // Pushes the address of loop amount
        lea eax, _fmt              // Gets the address of loop amount message
        push eax                   // Pushes the address of loop amount message
        call scanf                 // Gets input
        add esp, 8                 // Cleans up stack

        // Loops for the given number of times // 
        mov ecx, _loopAmount       // Set the amount of times to loop for
floop:  
        push ecx

        lea eax, _numberInputMessage  // Gets the address of loop amount message
        push eax                   // Pushes the address of loop amount message
        call printf
        pop eax                    // Cleans up stack

        // Prompts the user to input a number each time  round the loop //
        lea eax, _currentNumber    // Gets the address of current number
        push eax                   // Pushes the address of current number/
        lea eax, _fmt              // Gets the address of number input message
        push eax                   // Pushes the address of number input message
        call scanf                 // Gets current number
        add esp, 8                 // Cleans up stack

        // Number Comparison //
        cmp _currentNumber, 0
        jg positiv
        jl negativ

        mov eax, _zeroCount
        add eax, 1
        mov _zeroCount, eax
        jmp endloop
positiv:
        mov eax, _positiveCount
        add eax, 1
        mov _positiveCount, eax
        jmp endloop
negativ:
        mov eax, _negativeCount
        add eax, 1
        mov _negativeCount, eax
        jmp endloop
endloop:
        pop ecx
        loop floop                 // Goes to the next loop cycle and decrements by 1       

        // Displays a summary of how many positive, negative and zero numbers were entered //
        lea eax, _seperatorMessage
        push eax
        call printf

        push _positiveCount        // Push the positive count onto the stack
        lea eax, _positiveMessage  // Get the value of _positiveCount
        push eax                   // Push the value onto the stack
        call printf                // Call printf
        add esp, 8                 // Clean up the stack
           
        push _negativeCount        // Push the negative count onto the stack
        lea eax, _negativeMessage  // Get the value of _positiveCount
        push eax                   // Push the value onto the stack
        call printf                // Call printf
        add esp, 8                 // Clean up the stack
            
        push _zeroCount            // Push the zero count onto the stack
        lea eax, _zerosMessage     // Get the value of _positiveCount
        push eax                   // Push the value onto the stack
        call printf                // Call printf
        add esp, 8                 // Clean up the stack
    }

    return 0;
}