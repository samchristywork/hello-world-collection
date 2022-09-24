#include <curl/curl.h>

size_t write_callback(void *ptr, size_t size, size_t nmemb, FILE *stream) {
  return fwrite(ptr, size, nmemb, stream);
}

int main() {
  char *url = "https://s-christy.com/status-banner-service/GPLv3_Logo.svg";
  char *filename = "GPLv3_Logo.svg";
  CURL *handle = curl_easy_init();
  if (handle) {
    FILE *f = fopen(filename, "wb");
    curl_easy_setopt(handle, CURLOPT_URL, url);
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, f);
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, write_callback);
    CURLcode res = curl_easy_perform(handle);
    curl_easy_cleanup(handle);
    fclose(f);
  }
}
