{
    "targets": [
        {
            "target_name": "nolimits",
            "sources": [
                "binding/nolimits.cpp",
                "binding/NL2Park/Coaster/Track/Track.cpp",
                "binding/NL2Park/Coaster/Track/Section/Section.cpp"
            ],
            'cflags!': ['-fno-exceptions', '-funwind-tables', '-stdlib=libc++', '-std=c++11', '-O3', '-g0'],
            'cflags_cc!': ['-fno-exceptions', '-funwind-tables', '-stdlib=libc++', '-std=c++11', '-O3', '-g0'],
            'conditions': [
              ['OS=="mac"', {
                'xcode_settings': {
                  'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
                  'OTHER_CFLAGS': ['-stdlib=libc++', '-std=c++11', '-O3', '-g0'],
                  'OTHER_LDFLAGS': ['-lz', '-lnolimits']
                }
              }]
            ],
            "include_dirs": [
                "<!(node -e \"require('nan')\")",
                "lib",
                ".",
                "/Users/ercanakyurek/Daten/Projects/libnolimits/src/"
            ]
        }
    ]
}
