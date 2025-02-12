#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

const uint servo_pin = 22; // Pino GPIO 

// Utilizando a fórmula para o cálculo da frequência do PWM:
// frequência = clock / (DI * (WRAP + 1))
// Portanto, para uma frequência de 50Hz, temos:
const uint16_t WRAP = 19999; // Valor de wrap para o PWM
const float DI = 125.0; // Divisor de clock do PWM
// 125MHz / (125 * (19999 + 1)) = 50Hz

const uint16_t pin_step = 5; // Passo de incremento/decremento para o duty cycle do LED 
uint16_t pin_level = 500; // Nível do duty cycle do pino GPIO 
bool up_down = 0; // Flag para indicar a direção do movimento

void pwm_setup()
{
    gpio_set_function(servo_pin, GPIO_FUNC_PWM); // Habilitar o pino GPIO como PWM
    uint slice = pwm_gpio_to_slice_num(servo_pin); // Obter o canal PWM da GPIO
    pwm_set_clkdiv(slice, DI); // Define o divisor de clock do PWM
    pwm_set_wrap(slice, WRAP); // Definir o valor de wrap
    pwm_set_enabled(slice, true); // Habilita o pwm no slice correspondente
}

void initial_movement() {
    uint32_t delay = 5000; // Delay entre os movimentos
    pwm_set_gpio_level(servo_pin, 2400); // Movimento para 180°
    sleep_ms(delay);
    pwm_set_gpio_level(servo_pin, 1470); // Movimento para 90°
    sleep_ms(delay);
    pwm_set_gpio_level(servo_pin, 500); // Movimento para 0°
    sleep_ms(delay);
}

// Rotina de movimento periódico do braço do servomotor
void periodic_movement() {
    pwm_set_gpio_level(servo_pin, pin_level); // Define o nível do servomotor
    if (up_down) 
    {
        pin_level += pin_step; // Incrementa o nível do servomotor
        if (pin_level >= 2400)
            up_down = 0; // Muda direção para diminuir quando atingir o período máximo
    }
    else
    {
        pin_level -= pin_step; // Decrementa o nível do servomotor
        if (pin_level <= 500)
            up_down = 1; // Muda direção para aumentar quando atingir o mínimo
    }
    
}

int main() {
    stdio_init_all();
    pwm_setup(); // Configuração do PWM

    initial_movement(); // Movimento inicial do servomotor

    while (true) {
        periodic_movement(); // Movimento periódico do servomotor
        sleep_ms(10);
    }
}
