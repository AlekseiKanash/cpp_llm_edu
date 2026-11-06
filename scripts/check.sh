#!/usr/bin/env bash
# Single "is it green" command for humans and agents.
set -euo pipefail
cd "$(dirname "$0")/.."

echo "== configure + build (debug, -Werror, ASan/UBSan)"
cmake --preset debug >/dev/null
cmake --build --preset debug

echo "== tests"
ctest --preset debug

sources=$(git ls-files --cached --others --exclude-standard -- src app tests | grep -E '\.(cpp|hpp)$' || true)

if command -v clang-format >/dev/null; then
  echo "== clang-format"
  # shellcheck disable=SC2086
  clang-format --dry-run --Werror $sources
else
  echo "== clang-format: not installed, skipped (brew install llvm)"
fi

if command -v clang-tidy >/dev/null; then
  echo "== clang-tidy (warnings only)"
  # shellcheck disable=SC2086
  clang-tidy -p build/debug --quiet $(echo "$sources" | grep -E '\.cpp$') || true
else
  echo "== clang-tidy: not installed, skipped (brew install llvm)"
fi

echo "== CHECK GREEN"
