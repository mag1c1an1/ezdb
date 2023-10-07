set_languages("cxx20")

includes("third_party/common")

add_requires("jsoncpp","spdlog")

target("ezdb")
  set_kind("static")
  add_deps("common")
  add_includedirs("src/include", {public = true })
  add_files("src/**.cpp")
  add_packages("jsoncpp")
  add_packages("spdlog")

