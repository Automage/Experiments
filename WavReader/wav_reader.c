#include <stdio.h>
#include <assert.h>

#define HEADER_SIZE (44)

int main () {
  FILE *fp = fopen("mus.wav", "rb");
  assert(fp != NULL);

  for (int pos = 0; pos < HEADER_SIZE; pos++) {
    unsigned char byte;
    fread(&byte, 1, 1, fp);
    printf("%0x ", byte);
  }

  fseek(fp, 4, SEEK_SET);

  //Endianless read
  unsigned char bytes[4];
  int sum = 0;
  while (fread(bytes, 4, 1, fp) != 0) {
    sum += bytes[0] | (bytes[1]<<8) | (bytes[2]<<16) | (bytes[3]<<24);
    break;
  }


  printf("%d\n", sum);
}
