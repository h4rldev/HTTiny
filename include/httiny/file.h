#ifndef HTTINY_FILE_H
#define HTTINY_FILE_H

#include <httiny/types.h>

/*
 * @brief Serves a directory.
 *
 * @param path_conf The path configuration to use.
 * @param path The path to serve.
 * @param server_path The path to serve the directory from.
 *
 * @return The updated path configuration.
 */
httiny_path_conf_t *serve_dir(httiny_path_conf_t **path_conf,
                              const string *dir_path,
                              const string_nullable *server_path);

/*
 * @brief Serves a file.
 *
 * @param path_conf The path configuration to use.
 * @param file_path The path of the file to serve.
 * @param server_path The path to serve the file from.
 *
 * @return The updated path configuration.
 */
httiny_path_conf_t *serve_file(httiny_path_conf_t **path_conf,
                               const string *file_path,
                               const string_nullable *server_path);

#endif // !HTTINY_FILE_H
