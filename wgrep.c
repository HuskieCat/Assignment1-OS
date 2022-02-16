#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) 
{
  if(argc < 3)
  {
    printf("To few arguments\n");
    return 0;
  }

  char *search_term = argv[1];

  FILE *fp;
  for(int i = 2; i < argc; i++)
  {
    fp = fopen(argv[i], "r");
    if(fp == NULL)
    {
      printf("wgrep: cannot open file\n");
      return 1;
    }

    while(!feof(fp))
    {
      size_t buffer_size = 1024;
      char buffer[1024] = { };
      char *buffer_ptr = buffer;
      getline(&buffer_ptr, &buffer_size, fp);
      char *contains;
      contains = strstr(buffer, search_term);
      if(contains)
        printf("%s", buffer);
    }
  }

  fclose(fp);

  return 0;
}