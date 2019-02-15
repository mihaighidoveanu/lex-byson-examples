#include <unistd.h>

int main(int argc, char **argv)
{
  if (argc > 1)
  {
  		execlp("python", "python", argv[1], (char*) NULL);
  		
  		printf("Input is OK !\n");
  }

  return 0;
}