{
  "targets": [
    {
      "target_name": "addon",
      "cflags!": [ "-fno-exceptions", "-fstrict-aliasing" ],
      "cflags_cc!": [ "-fno-exceptions", "-fstrict-aliasing" ],
      "sources": [ 
          "addon.cc"
      ],
      "libraries": [
          "<(module_root_dir)/compression/libic.a"
      ],
      "include_dirs": [
          "<!@(node -p \"require('node-addon-api').include\")"
        , "<(module_root_dir)/compression/"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}