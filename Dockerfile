FROM ubuntu:focal
LABEL maintainer="maxmilio@kiv.zcu.cz" \
      org.opencontainers.image.source="https://github.com/maxotta/dev-builder-c"

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    autoconf \
    git \
    curl

CMD [ "sh", "-c", "while :; do cd; bash -i; echo '==> NOPE ! Exiting the shell would also stop the Docker container! Please close the terminal window instead.'; done" ]
