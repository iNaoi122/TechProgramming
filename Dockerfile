FROM ubuntu:latest

RUN apt-get update
RUN apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools -y
RUN apt-get install build-essential -y

RUN mkdir server
WORKDIR /server/

RUN qmake && make
