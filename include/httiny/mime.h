#ifndef HTTINY_MIME_H
#define HTTINY_MIME_H

#include <httiny/string.h>
#include <httiny/types.h>

const string *get_mime_type(httiny_arena_t *arena, const string *file_path);

#endif // !HTTINY_MIME_H
