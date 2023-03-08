#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>

#define LED_PATH "/sys/class/leds/am62-sk:green:heartbeat"
#define LED_DELAY 1

void writeFile(char filename[], char value[]);

int main(int argc, char* argv[]){
	printf("The current LED path is: " LED_PATH "\n");
	while (1) {
		// Remove any LED triggers
		writeFile("/trigger", "none");
		printf("Turning the LED on\n");
		// Set LED brightness to max
		writeFile("/brightness", "1");
		// Delay
		sleep(LED_DELAY);
		// Remove any LED triggers
	        writeFile("/trigger", "none");
		// Set LED brightness to zero
		printf("Turning the LED off\n");
		writeFile("/brightness", "0");
		// Delay
		sleep(LED_DELAY);
	}
	return 0;
}

void writeFile(char filename[],char value[]){
	FILE* fp;
	char fullFileName[100];
	sprintf(fullFileName, LED_PATH "%s", filename);
	fp = fopen(fullFileName, "w+");
	fprintf(fp, "%s", value);
	fclose(fp);
}
