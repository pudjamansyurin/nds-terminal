# Andes terminal module using serial and tiny-shell

## Module description
- Terminal with stdout and stdin interface.
- Support multiple commands.

#### **`main.c`**
```c
#include "nds-terminal/terminal.h"

/* Private function definitions */
static void stdin_reader(void *p_buffer, uint16_t u16_cnt)
{
	/* replace with flag or queue message */
	/* as this is still in interrupt context call */
	term_in(p_buffer, u16_cnt);
}


/* public function definition */
int main(void)
{
	extern NDS_DRIVER_USART Driver_USART1;

	// Initialize terminal
	term_init(&Driver_USART1, 250000, stdin_reader, NULL);

	/* simulate in-direct stdout */
	printf("Hello World\n");

	/* infinite loop */
	while(1) {
		/* do other concurrent task */

		delay(1);
	}

	return 0;
}

```
