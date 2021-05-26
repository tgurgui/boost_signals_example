# boost_signals_example

Simple example of Boost signals. This project uses [Conan](https://conan.io/) to install and use [boost](https://www.boost.org/)

## Build

Conan must be [installed](https://docs.conan.io/en/latest/installation.html) to build this project.

Once Conan is installed, you can build the project with the following steps:

1. Clone repo
2. Create 'build' folder inside repo folder
3. Execute conan to install dependencies from 'build' folder:
```bash
$ conan install ..
```
4. Execute cmake to create the project/solution and compile it
```bash
(win)
$ cmake .. -G "Visual Studio 16"
$ cmake --build . --config Release

(linux, mac)
$ cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
$ cmake --build .
```
