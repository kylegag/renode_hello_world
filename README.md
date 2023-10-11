# renode_hello_world

nRF52840 documentation: https://infocenter.nordicsemi.com/pdf/nRF52840_PS_v1.0.pdf

Steps to run
1. If you don't have renode installed download and run the .msi file here: https://github.com/renode/renode/releases/tag/v1.14.0
2. If you don't have WSL (Windows Subsystem for Linux) installed open a PowerShell terminal and send this command "wsl --install"
3. make project by sending "make" command in directory in a WSL (Windows Subsystem for Linux) terminal
4. start simulation by sending "renode renode-config.resc" in a Windows CMD terminal


Errors:
The "hello world!" print is not coming through on the uart terminal window. It appears renode was not expecting the the TX registers to be written to because it is giving the below warnings.

This warning was given when the uart_configure() function was called which was meant to assign the TX, RX, CTS and RTS functions to pins on the nRF.
[WARNING] uart0: Unhandled write to offset 0x50C. Unhandled bits: [1-31] when writing value 0x1. Tags: PIN (0x1E), PORT (0x1), RESERVED (0x1FFFFFF), CONNECT (0x1).

This warning was given everytime the uart_send() function was called which was meant to send a UART byte to the uart terminal window.
[WARNING] uart0: Unhandled write to offset 0x51C, value 0x68.

To see a working renode project go to commit 326551123846018a1ff808222daf4c1ab5931e51 of this project and follow the same step to run. 
This commit is just a copy of this project for the STM32: https://github.com/memfault/interrupt/tree/master/example/renode
It is discussed in this article: https://interrupt.memfault.com/blog/intro-to-renode


Design considerations:

For this project I had to use the most recent release of the OpenCM3 library because support for the nRF had only recently been added. I used the nRF52840 because renode had an existing config for the board. I attempted to use the OpenCM3 functions to print a uart message to the terminal.
