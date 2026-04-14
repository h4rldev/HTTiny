#include <stdio.h>
#include <string.h>

#include <magic.h>

#include <httiny/mime.h>
#include <httiny/types.h>

const string *get_mime_type(httiny_arena_t *arena, const string *file_path) {
  const cstr *mime_type, *file_path_cstr;

  magic_t magic = magic_open(MAGIC_MIME_TYPE);
  if (!magic) {
    fprintf(stderr, "Failed to open magic database\n");
    return NULL;
  }

  if (magic_load(magic, NULL) != 0) {
    fprintf(stderr, "Failed to load magic database\n");
    magic_close(magic);
    return NULL;
  }

  file_path_cstr = string_get_cstr(arena, file_path);
  mime_type = magic_file(magic, file_path_cstr);
  if (!mime_type) {
    fprintf(stderr, "Failed to get mime type for file %s\n", file_path_cstr);
    magic_close(magic);
    return NULL;
  }

  string *mime_type_str = string_new(arena, mime_type, strlen(mime_type));
  if (!mime_type_str) {
    magic_close(magic);
    return NULL;
  }

  magic_close(magic);
  return mime_type_str;
}
