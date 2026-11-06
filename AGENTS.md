# AGENTS.md

Shared instructions for every coding agent working in this repo (Claude Code, Codex, OpenCode, and others).
This file is the single source of truth. Agent-specific files (`CLAUDE.md`, `opencode.json`) only point here.

## Project

Educational C++ project for learning how to work with coding agents on C++ code.
Small, readable examples are preferred over clever ones.

## Layout

- `src/` library code (`cpp_llm_edu` static library). Headers live next to sources.
- `app/` executables that use the library.
- `tests/` GoogleTest unit tests, one `*_test.cpp` per library unit.
- `docs/` permanent documentation of finished features.
- `scripts/check.sh` full verification.
- `build/` out-of-source build output (git-ignored, never edit).

## Build and test

Requires CMake >= 3.25 and a C++20 compiler. GoogleTest is fetched by CMake on first configure.

```sh
scripts/check.sh              # build (-Werror, ASan/UBSan) + tests + format/tidy if installed
cmake --preset debug          # configure only
cmake --build --preset debug  # build only
ctest --preset debug          # tests only
./build/debug/app/cpp_llm_edu_app
```

Use `release` instead of `debug` for an optimized build.
`build/<preset>/compile_commands.json` is generated for clangd and clang-tidy.

## Definition of done

1. `scripts/check.sh` ends with `CHECK GREEN`.
2. New behavior has a test in `tests/`.

Report the actual check output when summarizing work. Do not claim tests pass without running them.

## Code style

- C++20. Prefer the standard library over hand-rolled utilities.
- `snake_case` for functions, variables, files; `PascalCase` for types; `kPascalCase` for constants.
- Everything in the library lives in `namespace edu`.
- RAII for all resources. No raw `new`/`delete`; use `std::unique_ptr` / containers.
- Prefer `std::string_view` and `std::span` for non-owning parameters.
- Errors: return `std::optional` / `std::expected`-style results for expected failures; exceptions only for truly exceptional cases.
- Keep headers minimal: forward-declare where reasonable, include what you use.
- Comments explain why, not what.

## Adding code

- New library unit: add `src/<name>.hpp` + `src/<name>.cpp`, list the `.cpp` in `src/CMakeLists.txt`, add `tests/<name>_test.cpp` and list it in `tests/CMakeLists.txt`.
- New executable: add it under `app/` and register it in `app/CMakeLists.txt`.

## Boundaries

- Do not edit files under `build/` or third-party code fetched by CMake.
- Do not add new dependencies without asking.
- Do not commit or push unless explicitly asked.
