FROM gcc:16.1.0

RUN apt update -y && apt install cmake libpqxx-dev gdb -y

COPY ../src /usr/src/app
WORKDIR /usr/src/app

