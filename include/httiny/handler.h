#ifndef HTTINY_HANDLER_H
#define HTTINY_HANDLER_H

#include <httiny/http.h>
#include <httiny/types.h>

// TODO: Implement handler registration logic, and handling of paths.

/*
 * @brief A function pointer type to handle a request.
 *
 * @param req The request to handle.
 *
 * @return The status code to send.
 */
typedef int (*httiny_handler)(httiny_http_req *req);

/*
 * @brief A list of handlers to handle requests.
 *
 * @param handlers The handlers to handle requests.
 * @param size The size of the list.
 * @param capacity The capacity of the list.
 */
typedef struct {
  httiny_handler *handlers;
  u64 size;
  u64 capacity;
} httiny_handler_list;

/*
 * @brief A list of paths to handle, used to register a handler for a specific
 * path.
 *
 * @param paths The paths to handle.
 * @param size The size of the list.
 * @param capacity The capacity of the list.
 */
typedef struct {
  string **paths;
  u64 size;
  u64 capacity;
} httiny_path_list_t;

/*
 * @brief The global path configuration for handling what path is for each
 * handler.
 *
 * @param path_list The list of paths to handle.
 * @param handler_list The list of handlers to handle requests.
 *
 * @note path_list[index] corresponds to handler_list[index]
 */
typedef struct {
  httiny_path_list_t *path_list;
  httiny_handler_list *handler_list;
} httiny_path_conf;

#endif // !HTTINY_HANDLER_H
