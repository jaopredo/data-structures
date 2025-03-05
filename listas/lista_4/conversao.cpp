#include "conversao.h"

float farenheit_to_celsius(float farenheit) {
    return (farenheit - 32) * 5/9;
}

float celsius_to_farenheit(float celsius) {
    return (celsius*5/9 + 32);
}
