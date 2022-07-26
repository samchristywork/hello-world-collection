#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>

static int callback(void *param, int argc, char **argv, char **columnNames) {
  for (int i = 0; i < argc; i++) {
    printf("%s = %s\n", columnNames[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}

void exec_sql(sqlite3 *db, char *sql) {
  char *error = 0;

  int ret = sqlite3_exec(db, sql, callback, 0, &error);
  if (ret != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", error);
    sqlite3_free(error);
  }
}

int main() {
  sqlite3 *db;

  int ret = sqlite3_open(":memory:", &db);
  if (ret) {
    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
    return EXIT_FAILURE;
  }

  exec_sql(db, "create table hello("
               "  id int primary key  not null,"
               "  key            text not null,"
               "  value          int  not null"
               ");");
  exec_sql(db, "insert into hello (id, key, value) values (1, 'foo', 123);");
  exec_sql(db, "insert into hello (id, key, value) values (2, 'bar', 456);");
  exec_sql(db, "select * from hello;");

  sqlite3_close(db);
}
