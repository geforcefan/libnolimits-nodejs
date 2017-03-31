{
    "targets": [
        {
            "target_name": "nolimits",
            "sources": [
                "binding/nolimits.cpp",
                "lib/Stream/NoLimitsStream.cpp",
                "lib/NL2Park/Park.cpp",
                "lib/NL2Park/Info/Info.cpp",
                "lib/NL2Park/Info/Sky.cpp",
                "lib/NL2Park/Info/Weather.cpp",
                "lib/File/File.cpp",
                "lib/File/BufferFile.cpp",
            ],
            'cflags!': ['-fno-exceptions', '-funwind-tables', '-stdlib=libc++', '-std=c++11'],
            'cflags_cc!': ['-fno-exceptions', '-funwind-tables', '-stdlib=libc++', '-std=c++11'],
            'conditions': [
              ['OS=="mac"', {
                'xcode_settings': {
                  'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
                  'OTHER_CFLAGS': ['-stdlib=libc++', '-std=c++11']
                }
              }]
            ],
            "include_dirs": [
                "<!(node -e \"require('nan')\")",
                "<!(node -e \"require('v8pp')\")",
                "lib",
                ".",
                "ext-lib",
                "ext-lib/glm",
                "ext-lib/glm/detail"
            ]
        }
    ]
}
