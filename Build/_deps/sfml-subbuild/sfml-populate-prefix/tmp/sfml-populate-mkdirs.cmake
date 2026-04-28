# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/Student/Documents/GitHub/angry-birds-clone-assignment-SundaysWithoutGod/Build/_deps/sfml-src"
  "C:/Users/Student/Documents/GitHub/angry-birds-clone-assignment-SundaysWithoutGod/Build/_deps/sfml-build"
  "C:/Users/Student/Documents/GitHub/angry-birds-clone-assignment-SundaysWithoutGod/Build/_deps/sfml-subbuild/sfml-populate-prefix"
  "C:/Users/Student/Documents/GitHub/angry-birds-clone-assignment-SundaysWithoutGod/Build/_deps/sfml-subbuild/sfml-populate-prefix/tmp"
  "C:/Users/Student/Documents/GitHub/angry-birds-clone-assignment-SundaysWithoutGod/Build/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
  "C:/Users/Student/Documents/GitHub/angry-birds-clone-assignment-SundaysWithoutGod/Build/_deps/sfml-subbuild/sfml-populate-prefix/src"
  "C:/Users/Student/Documents/GitHub/angry-birds-clone-assignment-SundaysWithoutGod/Build/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/Student/Documents/GitHub/angry-birds-clone-assignment-SundaysWithoutGod/Build/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/Student/Documents/GitHub/angry-birds-clone-assignment-SundaysWithoutGod/Build/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
