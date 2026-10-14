#include <stdint.h>

#define RCC_BASE	0x40023800UL
#define GPIOA_BASE	0x40020000UL

#define RCC_AHB1ENR (*(volatile uint32_t *)(RCC_BASE + 0x30))
#define GPIOA_MODER (*(volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_ODR   (*(volatile uint32_t *)(GPIOA_BASE + 0x14))
#define LED_PIN 5U

int main(void)
{

	/* 1. Enable the GPIOA clock: set the GPIOA bit in RCC_AHB1ENR. */
	RCC_AHB1ENR |= (1U << 0);

	/*2. Make PA5 an output: clear, then set, the 2 MODER bits for pin 5.
	 * (Each pin n uses bits 2n+1 : 2n; output mode is binary 01.)*/
	GPIOA_MODER &= ~(3U << (LED_PIN * 2U));
	GPIOA_MODER |= (1U << (LED_PIN * 2U));

	while (1) {
		/* 3. Toggle bit 5 of GPIOA_ODR (XOR with 1 << 5). */
		GPIOA_ODR ^= (1U << LED_PIN);

		/* 4. Delay: a loop counting down a volatile variable. */
		for (volatile uint32_t i =0; i < 500000; i++) {}
	}
}
