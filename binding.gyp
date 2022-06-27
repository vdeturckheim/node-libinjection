{
  "targets": [
    {
    "target_name": "libinjection",
    "include_dirs": [
      ".",
      "<!@(node -p \"require('node-addon-api').include\")",
      "libinjection/src/"
    ],
    "libraries": [
      "<!@(node -p \"process.cwd()\")/libinjection/src/libinjection.a"
    ],
    "sources": [
      "src/libinjection.cpp"
    ],
    "defines": [ "NAPI_DISABLE_CPP_EXCEPTIONS" ]
  }]
}
