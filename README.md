[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=21901920)
# ELEC2645 Unit 2 – Command Line Converter

This project is a command-line application that performs several engineering-related conversions. The program uses the menu system provided in the template (main.c), and all conversion functions are implemented inside funcs.c. The function prototypes are stored in funcs.h.

## 1. Project Overview

The program supports the following conversions:

• dBm ↔ mW  
• Hz ↔ rad/s  
• Temperature conversions (Celsius ↔ Kelvin, Celsius ↔ Fahrenheit, Fahrenheit ↔ Celsius)  
• Engineering prefixes (k, M, m, u, n, p)  
• Saving and displaying conversion history

Every conversion performed by the user is stored in a file called history.txt, which is created automatically.

## 2. File Structure

main.c      – provided template handling menu and input  
funcs.c     – my implementation of all conversions and history functions  
funcs.h     – function prototypes  
history.txt – created automatically after running the program  
Makefile    – provided for compilation  
README.md   – this file

I did not modify main.c except for using the menu functions already provided. All required logic is written in funcs.c.

## 3. How to Compile

To compile using GCC:

gcc main.c funcs.c -o main.out -lm

The -lm flag links the math library.

You can also compile using the provided Makefile:

make -B

## 4. How to Run

After compiling:

./main.out

## 5. How to Use the Program

1. Run the program to open the main menu.  
2. Select one of the menu items (1–4).  
3. Enter the value requested by the program.  
4. The result is printed and saved to history.txt.  
5. Press 'b' or 'B' to return to the main menu.  
6. Select item 4 to view the saved history.  
7. Select item 5 to exit the program.

## 6. Notes

- history.txt is created automatically after the first conversion.  
- Input checking is already handled safely inside main.c from the provided template.  
- All required functionality for Unit 2 is implemented inside funcs.c as instructed.
