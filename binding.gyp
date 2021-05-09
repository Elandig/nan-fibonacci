{
  "targets": [
    {
      "target_name": "nan_fibonacci",
      "sources": [
        "src/addon.cc",
        "src/nan_fibonacci.cc",
        "src/nan_fibonacci_base.cc"
        ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}