*This project has been created as part of the 42 curriculum by aboussab*.

# GET_NEXT_LINE

## “Description”
 The Get Next Line project is a practical C programming exercise focused on creating a function that reads a line from a file descriptor, one line at a time. This function is essential for processing input from files or standard input in an organized way. By working on this project, you will explore concepts like static variables, memory management, and buffer handling, which are critical for efficient and clean code.

## “Instructions”
 
  For thid project you cloned the repository from with "git clone " CMD then u check  norminette  then you creat a  proramme to test the fct on the main programme you creat a file  give it a FD then you change the content of the file for each you want and its important to compile it with this flags cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c the "BUFFER_SIZE=42" is a defined variable indicate how mush char the fct read() read to the buffer any way you can modife it as you want that's it. 
  
## “Resources”

 On this project i based on my old peers to build my own logique and to understand  the topic I  used some geeks for geeks help but not to mush ,as also i used the AI to explain the  errors that i got and to more understand gdb cmd + valgrind.
 
## “Detailes”

 the algorithm selected for this project was based on taking a SV ineser it with what the read read then check this buffer if it contian the "/n" if (yes : you take the buffer spelit and return the first line than save the rest on a SV ) (no: its loop over an while to take the rest of the file inser it the buffer entile it take a /n or finde the end of file ).
