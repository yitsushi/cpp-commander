FROM ubuntu:latest

MAINTAINER Balazs Nadasdi <balazs.nadasdi@cheppers.com>

RUN apt-get update && \
      apt-get install -y gcc g++ cmake \
      lcov libboost-all-dev \
      ruby gem && \
      rm -rf /var/lib/apt/lists/*

RUN apt-get update && \
      apt-get install -y git-core && \
      rm -rf /var/lib/apt/lists/*

RUN gem install coveralls-lcov

VOLUME /code

WORKDIR /code

ENTRYPOINT ["./build-and-run.sh"]

