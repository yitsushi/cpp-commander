FROM ubuntu:latest

MAINTAINER Balazs Nadasdi <balazs.nadasdi@cheppers.com>

RUN apt-get update && \
      apt-get install -y gcc g++ cmake \
      lcov libboost-all-dev && \
      rm -rf /var/lib/apt/lists/*

VOLUME /code

WORKDIR /code

ENTRYPOINT ["./build-and-run.sh"]

