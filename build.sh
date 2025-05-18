#!/bin/bash

set -e

# Output file
OUTPUT="mosaic.html"

# Compiler and flags
CXX=em++  # Emscripten C++ compiler
CXXFLAGS="-std=c++17 -Wall -Wextra"

# Source files
SRC="src/main.cpp src/ui.cpp"

# SDL2, SDL2_image, SDL2_ttf with Emscripten
EM_FLAGS="
  -s USE_SDL=2
  -s USE_SDL_IMAGE=2
  -s SDL2_IMAGE_FORMATS='[\"png\"]'
  -s USE_SDL_TTF=2
  -s FORCE_FILESYSTEM=1
  -s FULL_ES3=1
  -s ALLOW_MEMORY_GROWTH=1
  --preload-file assets
"

# Linker output flags
OUT_FLAGS="-o $OUTPUT"

# Build
echo "Building with Emscripten..."
$CXX $CXXFLAGS $SRC $EM_FLAGS $OUT_FLAGS

echo "Build complete: open $OUTPUT in a browser"
