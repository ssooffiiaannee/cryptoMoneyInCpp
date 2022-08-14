file(REMOVE_RECURSE
  "libacrodictLib.a"
  "libacrodictLib.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/acrodictLib.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
