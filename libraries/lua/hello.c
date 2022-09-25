#include <lauxlib.h>
#include <lualib.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int error;
  char *buf;

  /*
   * Initialization. This worked differently prior to version 5.1
   */
  lua_State *L = luaL_newstate();
  luaL_openlibs(L);

  /*
   * Evaluate a string that sets up some global variables.
   */
  buf = "a=1\nb=2;";
  error = luaL_loadbuffer(L, buf, strlen(buf), "") || lua_pcall(L, 0, 0, 0);
  if (error) {
    fprintf(stderr, "%s\n", lua_tostring(L, -1));
    exit(EXIT_FAILURE);
  }

  /*
   * Evaluate a string that defines a function
   */
  buf = "function eval(n);return load('return '..n)();end";
  error = luaL_loadbuffer(L, buf, strlen(buf), "") || lua_pcall(L, 0, 0, 0);
  if (error) {
    fprintf(stderr, "%s\n", lua_tostring(L, -1));
    exit(EXIT_FAILURE);
  }

  /*
   * Call the function and get the integer result
   */
  lua_getglobal(L, "eval");
  lua_pushstring(L, "a+b");
  error = lua_pcall(L, 1, 1, 0);
  printf("%d\n", lua_tointeger(L, -1));
  if (error) {
    fprintf(stderr, "%s\n", lua_tostring(L, -1));
    exit(EXIT_FAILURE);
  }

  error = luaL_dofile(L, "sample.lua");
  if (error) {
    fprintf(stderr, "%s\n", lua_tostring(L, -1));
    exit(EXIT_FAILURE);
  }

  /*
   * Cleanup
   */
  lua_pop(L, 1);
  lua_close(L);
}
