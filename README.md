[![Build Status](https://travis-ci.org/Yitsushi/cpp-commander.svg?branch=master)](https://travis-ci.org/Yitsushi/cpp-commander)
[![Coverage Status](https://coveralls.io/repos/github/Yitsushi/cpp-commander/badge.svg?branch=master)](https://coveralls.io/github/Yitsushi/cpp-commander?branch=master)

# Testing

```
$ cmake . && cmake --build . && ctest
```

If you want an awesome coverage report, you have to enable it while calling `cmake`.

```
$ cmake -DCMAKE_BUILD_TYPE=Debug -DWITHCOVERAGE=1 . && \
    cmake --build . && \
    make coverage
```

# Example

Check `examples` directory.

```
$ cmake .
$ cmake --build .
$ ./bin/example MyCommand --verbose
My Command is executed...
Verbose mode is active...

# try to execute dynamically loaded command
$ ./bin/example DynamicCommand --verbose
Verbose mode is active...
Dynamic command executed.
```
