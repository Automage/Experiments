/* Pranav Nair, core.c
 * Created: 15/4/19
 */

#include "core.h"
#include "memory.h"

#include <stdio.h>
#include <assert.h>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("No file specified\n");
    return 0;
  }

  FILE *fp = NULL;
  fp = fopen(argv[1], "r");
  assert(fp);

  char line[BUFFER_SIZE];

  while (fscanf(fp, "%[^\n]\n", line) != EOF) {
    printf("%s\n", line);
  }

  fclose(fp);
  fp = NULL;

  return 0;
}
