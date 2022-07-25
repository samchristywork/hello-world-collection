#include <openssl/hmac.h>
#include <string.h>
#include <unistd.h>

int main() {
  char *pass = "changeme";
  char *salt = "somesalt";
  unsigned char result[1024];

  fprintf(stderr, "Generating PBKDF2 hash:\n");
  PKCS5_PBKDF2_HMAC_SHA1(pass, strlen(pass), salt, strlen(salt), 1000000, 48,
                         result);

  write(1, result, 48);
}
