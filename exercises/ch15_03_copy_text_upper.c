// This program copies text from one file to another, changing lower to upper
#include <stdio.h>

int copyFileUpper(char inName[], char outName[]);

int main(void) {
  char inName[64], outName[64];
  int result;

  printf("Please enter the name of the original file: \n");
  scanf("%63s", inName);

  printf("\nPlease enter the name of the output file:\n");
  scanf("%63s", outName);

  result = copyFileUpper(inName, outName);

  return result;
}

int copyFileUpper(char inName[], char outName[]) {
  FILE *in, *out;
  int c;

  // Try opening files
  if ((in = fopen(inName, "r")) == NULL) {
    fprintf(stderr, "\nError accessing file: %s\n", inName);
    return 1;
  }

  if ((out = fopen(outName, "w")) == NULL) {
    fprintf(stderr, "\nError accessing file: %s\n", outName);
    return 2;
  }

  while ((c = getc(in)) != EOF) {
    if ((c >= 'a') && (c <= 'z')) {
      c -= 32;
      fputc(c, out);
    } else {
      fputc(c, out);
    }
  }

  fclose(in);
  fclose(out);

  return 0;
}
