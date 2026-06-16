FROM gcc:12.5

RUN apt update -y && apt install cmake libpq-dev -y

COPY ../src /usr/src/app
WORKDIR /usr/src/app

# Build the c++ project using cmake
# https://cmake.org/cmake/help/latest/guide/tutorial/Getting%20Started%20with%20CMake.html#build-and-run
RUN cmake -B build 
RUN cmake --build build

CMD ["./build/monbrain"]
