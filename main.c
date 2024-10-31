#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {
  char url[10];
  bool validInput = false;

  while (!validInput) {
    printf("Enter a URL (max 9 characters):\n");

    if (fgets(url, sizeof(url), stdin) == NULL) {
      printf("Error reading input.\n");
      continue;
    }

    int length = strlen(url);

    if (length == sizeof(url) - 1 && url[length - 1] != '\n') {
      int ch;
      while ((ch = getchar()) != '\n' && ch != EOF)
        ;

      printf("Input too long (max %lu characters). Please try again.\n",
             sizeof(url) - 1);
      continue;
    }

    url[strcspn(url, "\n")] = 0;

    printf("%s!\n", url);
    validInput = true;
  }

  return 0;
}
