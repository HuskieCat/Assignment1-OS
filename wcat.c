#include <stdio.h>

/*
 * Duplicates the basic functionality of the command 'cat'.
 * Reproduces the plain-text of a file
 * @Author Bradley Henderson
*/

int main(int argc, char** argv) 
{
  if(argc < 2)
  {
    return 0;
  }

  FILE *fp;
  for(int i = 1; i < argc; i++)
  {
    fp = fopen(argv[i], "r");
    if(fp == NULL)
    {
      printf("wcat: cannot open file\n");
      return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
      printf("%s", buffer);
    }
  }
  fclose(fp);

  return 0;
}