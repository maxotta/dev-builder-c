# Docker image `dev-builder-c`

## Introduction

This Docker image is intended for use in multi-stage Docker image builds.
The basic idea behind multi-stage builds is, that you build your app in a Docker container instead of your local machine. This has some advantages that developers like:
* your development environment is setup automatically - just using the `docker pull` and `docker run` commands
* it's platform independent - you can run it on any platform Docker is available for
* it doesn't mess up your machine - you can easily dispose the whole thing when you're done with the `docker stop` and `docker rm` commands

## About this image

This Ubuntu (Focal) based Docker image contains essential tools for building C apps:
* The GNU C, C++ Compiler
* The `make` and `cmake` build utilities
* The Git VCS
* The `curl` utility for downloading stuff from the Internet

For the complete list the essential build tools look at the [`build-essential`](https://packages.ubuntu.com/focal/build-essential) package.

## How to use this image

There are two examples provided in this repo:
* `

docker build -t test/dev-builder-c .

cd examples/udp-simple
docker build -t test/udp-simple .
docker run -d --name node-1 test/udp-simple

docker exec -it node-1 bash

docker stop node-1
docker rm node-1

cd examples/udp-simple-cmake
docker build -t test/udp-simple .
docker run -d --name node-1 test/udp-simple
docker exec -it node-1 bash

# Windows command line (cmd)
docker run -d -v %cd%:/src   --name dev-node test/dev-builder-c
# Windows PowerShell
docker run -d -v $(PWD):/src --name dev-node test/dev-builder-c
# Linux/OS X command line
docker run -d -v $(pwd):/src --name dev-node test/dev-builder-c

docker exec -it dev-node bash

cd /src
cmake -S src -B build
cmake --build build



https://developer.microsoft.com/en-us/microsoft-edge/tools/vms/


