#include <stdio.h>

void instLogger(char const* instructionName) {
  printf("%s\n", instructionName);
}

void userToInstruction(char const* instructionName, char const* userName) {
  printf("%s <- %s\n", instructionName, userName);
}