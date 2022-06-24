#include <stdio.h>
#include <stdlib.h>
#include <cjson/cJSON.h>

int main() {

  /*
   * Open the JSON file for reading
   */
  FILE *f=fopen("sample.json", "rb");
  if(!f){
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  /*
   * Get the size of the file so that we know how large we need to make the
   * buffer
   */
  fseek(f, 0, SEEK_END);
  int size=ftell(f);
  rewind(f);

  /*
   * Read the JSON data into memory
   */
  char buffer[size+1];
  buffer[size]=0;
  int ret=fread(buffer, 1, size, f);
  if(ret!=size){
    fprintf(stderr, "Could not read the expected number of bytes.\n");
    exit(EXIT_FAILURE);
  }

  /*
   * Close the file
   */
  fclose(f);

  /*
   * Parse the data using cJSON
   */
  cJSON *cjson = cJSON_Parse(buffer);
  if (!cjson) {
    const char *error_ptr = cJSON_GetErrorPtr();
    if (error_ptr) {
      fprintf(stderr, "Error before: %s\n", error_ptr);
    }
    cJSON_Delete(cjson);
    exit(EXIT_FAILURE);
  }

  /*
   * Select a particular element in the tree
   */
  const cJSON *foo = cJSON_GetObjectItemCaseSensitive(cjson, "foo");
  if (cJSON_IsString(foo) && (foo->valuestring != NULL)) {
    printf("\"foo\" = \"%s\"\n", foo->valuestring);
  }else{
    printf("\"foo\" could not be found.\n");
  }
  cJSON_Delete(cjson);
}
