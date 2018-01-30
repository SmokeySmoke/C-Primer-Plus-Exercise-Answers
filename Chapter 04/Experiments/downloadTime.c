/* downloadTime.c -- prompts user for download speed(mbps) and file size(MB) and
 displays download time in minutes. */
#include <stdio.h>

int main(void) {

	float mbps, filesize;

	printf("Enter a download speed in Mbps:\n");	// prompt user for download speed in mbps
	scanf("%f", &mbps);

	printf("Enter a file size in MB:\n");		// prompt user for file size in MB
	scanf("%f", &filesize);

	printf("At %.2f megabits per second, a file of %.2f megabytes "
		"downloads in %.2f minutes.\n", mbps, filesize, ((filesize * 8) / mbps) / 60); // calculate and display download time

	return 0;
}
