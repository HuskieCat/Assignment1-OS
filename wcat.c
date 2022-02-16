#include <stdio.h>

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
      printf("wcat: cannot open file\n");
      return 1;
    }

    while(!feof(fp))
    {
      char buffer[1024] = {};
      printf("%s", fgets(buffer, 1024, fp));
    }
  }

  fclose(fp);

  return 0;
}