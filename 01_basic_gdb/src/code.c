/*
 * Basic steps using GDB
 *
 * For debugging purposes, the CMake projects must set the variable 
 * CMAKE_BUILD_TYPE to Debug. The application will include debug instructions
 * such as you may follow its execution. On the terminal, execute:
 *
 * $ cd build
 * $ cmake .. -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=../
 * 
 * The application my_app is ready to be debugged.
 *
 * $ gdb
 * (gdb) 
 *
 * The GDB prompt accepts commands to define, follow and execute the
 * application. Let's define the application file to debug and run it:
 *
 * (gdb) file my_app
 * (gdb) run
 *
 * The application output is shown on the GDB prompt as it would on a terminal.
 * Still, we might want to break the application execution to check variables or
 * expressions. Thus, breakpoints must be defined according to:
 *
 * - Source code line numbers
 * - Function calls
 * 
 * Let's insert a breakpoint on the main function:
 *
 * (gdb) break main
 *
 * Please note that GDB shows the Breakpoint ID number, the source file and the
 * line where it is placed. Let's run the application again:
 *
 * (gdb) r
 *
 * Note that we have used a shortcut for run (r). The shortcuts usually are the
 * first character of the word. If you are in doubt, use TAB key for
 * autocompletion anytime you want.
 *
 * The execution has stopped on the first line after the main function, hitting
 * Breakpoint 1. For now, we can check the variables values.
 *
 * (gdb) print i
 *
 * As it returns the value of i, it is not 1 as the line has not been executed
 * yet. Let's perform a single step on the code execution and check i again.
 *
 * (gdb) step
 * (gdb) p i
 * (gdb) p j
 * (gdb) p z
 *
 * As definition, the step command runs the next instruction, not line. If it’s
 * a function, it will jump into the function, execute the first statement, 
 * then pause. step is good for diving into the details of your code.
 *
 * We can also use the next command to execute the application until the next
 * line of code. It runs the program until next line, then pauses. If the 
 * current line is a function, it executes the entire function, then pauses.
 * If the current instruction is setting a variable, it is the same as step.
 * next is good for walking through your code quickly. 
 *
 * (gdb) next
 *
 * Instead of printing the variable everytime, you can display it and check its
 * value for every GDB command.
 *
 * (gdb) display j
 * (gdb) s
 *
 * Please note the display ID is shown and you can use it to identify it. In 
 * addition, it is also possible to unfollow the variable.
 *
 * (gdb) delete display 1
 *
 * For now, let's remember how many breakpoints we have.
 *
 * (gdb) info breakpoints
 *
 * The info command is very useful and I recommend that you explore it. Try the
 * following:
 *
 * (gdb) info source
 * (gdb) info sources
 * (gdb) info types
 * (gdb) info line
 * (gdb) info files
 *
 * We can delete Breakpoint 1 as it is not necessary anymore.
 *
 * (gdb) del 1
 *
 * You may also list code lines which by default show 10 lines around your 
 * current position. You may also specify the line or function you want to 
 * list.
 * 
 * (gdb) list
 * (gdb) l 5
 * (gdb) l main
 *
 * Let's include some breakpoints, display z and check info.
 *
 * b 137
 * b 142
 * display z
 * info breakpoints
 * 
 * Instead of following the code step by step (or next), we may let it continue
 * until a breakpoint is found.
 *
 * (gdb) continue
 *
 * At last, let the application run until its end.
 *
 * (gdb) c
 *
 * Ps.: Have you checked that the output of the last printf command?
 */

#include <stdio.h>

int main(int argc, char* argv[])
{

    int i = 1, j, z;          // i = 1

    printf("%d little\n", i);

    j = i + i;                // j = 2

    printf("%d little\n", j);

    z = i + j;                // z = 3

    printf("%d little indians...\n", z);

    i = 10;
    j = 20;

    printf("i + j = %d\n", i + j);
    printf("i - j = %d\n", i - j);
    printf("i * j = %d\n", i * j);
    printf("i / j = %d\n", i / j);

    return(0);
}
