#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <libopencm3/nrf/52/uart.h>
#include <libopencm3/nrf/52/gpio.h>

#define UART_BASE UART0
#define UART_TX_PIN GPIO1

/* Forward declarations */
int _write(int file, char *ptr, int len);

static void uart_setup(void)
{
    /* Setup UART parameters. */
	uart_configure(UART_BASE, UART_TX_PIN, GPIO_UNCONNECTED, GPIO_UNCONNECTED, GPIO_UNCONNECTED, UART_BAUD_115200, false);
	
	/* Enable the UART. */
    uart_enable(UART_BASE);
}

static void gpio_setup(void)
{
	gpio_mode_setup(GPIO, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, UART_TX_PIN);
}

static void uart_send_blocking(uint32_t uart, uint16_t byte) {
	uart_send(uart, byte);
	
	/* Wait for our byte to send */
	// while(!UART_EVENT_TXDRDY(uart));
}


int _write(int file, char *ptr, int len)
{
    int i;

    if (file == STDOUT_FILENO || file == STDERR_FILENO) {
        for (i = 0; i < len; i++) {
            if (ptr[i] == '\n') {
                uart_send_blocking(UART_BASE, '\r');
            }
            uart_send_blocking(UART_BASE, ptr[i]);
        }
        return i;
    }
    errno = EIO;
    return -1;
}


int main(void) {
	gpio_setup();
	uart_setup();

	uart_start_tx(UART_BASE);
	printf("hello world!\n");

    return 0;
}
