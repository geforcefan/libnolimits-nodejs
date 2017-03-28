{
    "targets": [
        {
            "target_name": "nolimits",
            "sources": [ "nolimits.cpp" ],
            "include_dirs": [
                "<!(node -e \"require('nan')\")"
            ]
        }
    ]
}