#define NAPI_VERSION  4
#include <napi.h>
// #include "libinjection.h"
// #include "libinjection_sqli.h"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  return exports;
}

// Register and initialize native add-on
NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
