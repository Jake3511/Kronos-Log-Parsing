# PS7: Kronos Log Parsing

## Contact
Name: Jake Shick
Section: 202
Time to Complete: 4 hours


## Description
The project takes in an input file, opens a new file, and reads in all whether or not the the device started and completed successfully or failed.  If it failed, it would print the first startup, line number, time, and below it was an incomplete message and move through the log file until next start up initiated, or would print the secod message followed by the total time in milliseconds it took to get from the first start message to boot success message.

### Features
I used a basic while loop to go through my log files, and would essentialy check each line to see if that line matched with its regex.  If it did, it would trigger the if statement and do one of two things.  I would either print device boot up along with the line number and current log file actually being opened.  It would also display the date along with the time as well.  The other option is that it would display an incomplete startup message and move to the next startup.  If it was a successful startup, that means the second if statement would trigger which checked to see if the oejs string matched with the regex form.  It would then output the success message along with the total time message.  In both if statements I searched each string to get the specific date and time in order to calculate the total time in milliseconds, which I then did by subtracting the time at the complete startup message by the orginal startup message.

### Approach
The approach I used was to first figure out if the string I was getting from the log file matched with the regex I created for the specific string.  Once I had that figured out, I created a file and just outputed the entire string that matched the regex into the file to see if I was doing it correctly.  Once I did that, I added a count to get the line number and started thinking of ways to cut off the date in order to calculate the time.  Once I figured that out by using smatch and searching the string for a match, I was basically done at that point, but I had to actually calculate the total time taken, so I did that by creating a time_duration variable and subtracting the two dates in order to get the total time, and then spcified that I wanted it in milliseconds.

### Regex
I used three regex, one to represent the start of the device, one to represent the start complete of the device, and another to represent the date of the two startups.  All three regex's start the same by checking for the date and time first and then splitting off into their own seperate checks (besides the date regex) to match the correct string to the regex.  If the date and time was followed by a log.c.166 as well as the server started, it matched the first regex, and if 
:INFO:oejs.AbstractConnector:Started SelectChannelConnector followed the date, then the second regex matched.  The third regex was used specifically for getting the date split off from both the first and second strings.

### Issues
No issues, passed all tests when submitted correctly

### Extra Credit


## Acknowledgements
Doctor Daly- Office hours

Porchhay B- Tutor hours

https://stackoverflow.com/questions/20525528/matching-single-digit-with-stdregex-match

https://cplusplus.com/reference/regex/smatch/

https://www.geeksforgeeks.org/smatch-regex-regular-expressions-in-c/

https://www.boost.org/doc/libs/1_31_0/libs/date_time/doc/class_time_duration.html