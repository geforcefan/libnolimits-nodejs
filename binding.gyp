{
    "targets": [
        {
            "target_name": "nolimits",
            "sources": [
                "src/Nolimits.cpp",
                "src/NL2/Coaster/Track/Track.cpp",
                "src/NL2/Coaster/Track/Section/Section.cpp"
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
                ".",
            ],
            "libraries": ['-lnolimits', '-lz']
        }
    ]
}
