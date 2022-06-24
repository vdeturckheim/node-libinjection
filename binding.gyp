{
  "targets": [{
    "target_name": "libinjection",
    "include_dirs": [
      ".",
      "<!@(node -p \"require('node-addon-api').include\")"
    ],
    "libraries": [
    ],
    "sources": [
      "src/main.cpp"
    ],
    'ldflags': [
      '-static-libstdc++',
      '-static-libgcc',
      '-lpthread',
    ],
    "defines": [ "NAPI_DISABLE_CPP_EXCEPTIONS" ],
    "xcode_settings": {
      "MACOSX_DEPLOYMENT_TARGET": "10.10",
    },
    "conditions": [
      ["OS == 'linux'", {
        'ldflags': ['-Wl,--rpath=\$$ORIGIN']
      }],
      ["OS == 'win'", {
        "cflags": [
          "/WX"
        ]
      }]
    ]
  }]
}
