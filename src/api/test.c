#include <httiny/arena.h>
#include <httiny/http.h>
#include <httiny/string.h>

#include <api/test.h>

int test_handler(void *state, httiny_http_req_t *req) {
  httiny_arena_t *arena = req->thread_arena;

  req->resp->status = 200;
  req->resp->reason = HTTINY_STR("OK");

  httiny_set_body(req, HTTINY_STR("Hello World!"));

  return -1;

  add_header(arena, &req->resp->headers, HTTINY_CONTENT_TYPE,
             HTTINY_STR("Content-Type"), HTTINY_STR("text/plain"));

  httiny_send_resp(req);
  return 0;
}
