/* Write a program that requests the download speed in megabits per second (Mbps) and
 the size of a file in megabytes (MB). The program should calculate the download time 
 for the file. Note that in this context one byte is eight bits. Use type float, and
 use / for division. The program should report all three values (download speed, file
 size, and download time) showing two digits to the right of the decimal point, as in
 the following:

At 18.12 megabits per second, a file of 2.20 megabytes downloads in 0.97 seconds.
*/
#include <stdio.h>

int main(void) {

	float mbps, filesize;

	printf("Enter a download speed in Mbps:\n");	// prompt user for download speed in mbps
	scanf("%f", &mbps);

	printf("Enter a file size in MB:\n");		// prompt user for file size in MB
	scanf("%f", &filesize);

	printf("At %.2f megabits per second, a file of %.2f megabytes "
		"downloads in %.2f seconds.\n", mbps, filesize, (filesize * 8) / mbps); // calculate and display download time

	return 0;
}
