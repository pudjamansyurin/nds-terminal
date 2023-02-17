/*
 * terminal.c
 *
 *  Created on: May 5, 2022
 *      Author: pujak
 */

#include "terminal.h"
#include "tinysh/tinysh.h"
#include <stdio.h>

/* Private variables -------------------------------------------------------- */
static char buffer[256];

/* Public function definitions ---------------------------------------------- */
void term_init(NDS_DRIVER_USART *p_usart, uint32_t u32_baud,
	stdin_reader_t reader, stdout_locker_t locker)
{
	/* setup serial */
	serial_init(p_usart, u32_baud, locker);
	serial_start(reader, buffer, sizeof(buffer));

	/* setup tiny-shell */
	tinysh_set_prompt("NDS> ");

	/* add tiny-shell commands */
	// tinysh_add_command(&foo);
}

void term_in(unsigned char *str, uint16_t size)
{
	while (*str && size--)
	{
		tinysh_char_in(*str++);
	}
}

/* we must provide this function to use tinysh  */
void tinysh_puts(char *s)
{
	printf("%s", s);
}

void tinysh_putchar(unsigned char c)
{
	putchar((int) c);
}

