#define NAPI_VERSION  4
#include <napi.h>
#include "libinjection.h"
#include "libinjection_sqli.h"

Napi::Value IsSQLI(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[0].IsString()) {
    Napi::TypeError::New(env,"Wrong argument, expected a string")
                          .ThrowAsJavaScriptException();
    return env.Undefined();
  }

  struct libinjection_sqli_state state;
  int issqli;
  std::string argv = info[0].ToString().Utf8Value();
  const char* input = argv.c_str();
  size_t slen = strlen(input);
  libinjection_sqli_init(&state, input, slen, FLAG_NONE);
  issqli = libinjection_is_sqli(&state);

  if (issqli) {
    return Napi::Boolean::New(env, true);
  }

  return Napi::Boolean::New(env, false);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  Napi::Function func = Napi::Function::New(env, IsSQLI);
  exports.Set("IsSQLI", func);
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
