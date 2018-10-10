add_executable("par" main_par.cc)
target_link_dune_default_libraries("par")

add_executable("nonu" main_nonu.cc)
target_link_dune_default_libraries("nonu")
