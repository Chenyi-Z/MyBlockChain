cmake_minimum_required(VERSION 3.14)
project(Blockchain)

set(CMAKE_CXX_STANDARD 14)

add_executable(Blockchain main.cpp blockchain.cpp blockchain.h block.cpp block.h record.cpp record.h trans_data.cpp trans_data.h sha256.cpp sha256.h observer.cpp observer.h response.cpp response.h printOb.cpp printOb.h message.cpp message.h)