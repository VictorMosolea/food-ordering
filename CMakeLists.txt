cmake_minimum_required(VERSION 3.15)
project(food_ordering C)

set(CMAKE_C_STANDARD 99)

add_executable(food_ordering main.c options.h options.c order.h order.c userData.h userData.c constants.h validPassword.h validPassword.c validUser.h validUser.c crypto.h crypto.c menuData.h menuData.c)