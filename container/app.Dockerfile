FROM gcc:12.5

RUN apt update -y && apt install cmake libpq-dev gdb -y

COPY ../src /usr/src/app
WORKDIR /usr/src/app

