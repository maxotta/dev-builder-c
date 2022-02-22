# dev-builder-c
Ubuntu based Docker image with essential tools for building C apps


docker build -t test/dev-builder-c .

cd examples/udp-simple
docker build -t test/udp-simple .
docker run -d --name psi-node-1 test/udp-simple

cd examples/udp-simple-cmake
docker build -t test/udp-simple .
docker run -d --name psi-node-1 test/udp-simple
