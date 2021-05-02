{
  "targets": [
    {
      "target_name": "nan_fibonacci",
      "sources": [ "addon.cc", "nan_fibonacci.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}