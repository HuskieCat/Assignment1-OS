#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) 
{
  if(argc < 2)
  {
    printf("To few arguments\n");
    return 0;
  }

  FILE *fp;
  for(int i = 1; i < argc; i++)
  {
    fp = fopen(argv[i], "r");
    if(fp == NULL)
    {
      printf("wunzip: cannot open file\n");
      return 1;
    }

    while(!feof(fp))
    {
      int counter;
      fread(&counter, 2, 1, fp);
      char character;
      fread(&character, 1, 1, fp);

      printf("%d\n", counter);
      for(int i = 0; i < counter; i++)
      {
        printf("%c", character);
      }
    }
  }

  fclose(fp);

  return 0;
}