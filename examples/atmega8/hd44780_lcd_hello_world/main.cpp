/**
 * Copyright (c) 2016, Łukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 * Example code using driver HD44780.
 */

#include "at.hpp"
#include "at/driver/HD44780.hpp"

using namespace at;

HD44780 lcd(/*rs=*/_PC0, /*enable=*/_PC1, /*d4=*/_PC2, /*d5=*/_PC3, /*d6=*/_PC4, /*d7=*/_PC5);

int
main(void)
{

	/* setup */
	lcd.begin();

	/* clear screen and display "Hello World!" */
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.printf("Hello World!");

	/* loop */
	while (1);
}
