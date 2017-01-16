FROM alpine:latest

MAINTAINER Balazs Nadasdi <balazs.nadasdi@cheppers.com>

RUN apk add --no-cache \
      boost-dev git \
      gcc g++ cmake make \
      bash perl

RUN cd /tmp/ && \
      git clone https://github.com/linux-test-project/lcov.git && \
      cd lcov && make install

