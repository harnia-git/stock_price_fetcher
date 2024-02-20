#include <stdlib.h> // getenv関数を使用するために必要
#include <stdio.h>

int main() {
    char* apiKey = getenv("API_KEY");
    if (apiKey == NULL) {
        printf("API_KEY is not set.\n");
    } else {
        printf("API_KEY is %s\n", apiKey);
    }
    return 0;
}
