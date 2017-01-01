#include <stdio.h>
#include <time.h>

int main(void)
{
  time_t now;
  now = time(NULL);

  struct tm *now_tm;
  now_tm = gmtime(&now);

  char *format = "%m/%d/%Y";
  char buf[25];
  strftime(buf, sizeof(buf), format, now_tm);

  printf("Current time from strftime: %s\n", buf);

  struct tm now2_tm;
  strptime(buf, format, &now2_tm);
  
  printf("Parsed time: \n");
  printf("Month:\t%4d\n",now2_tm.tm_mon+1);
  printf("Day:\t%4d\n",now2_tm.tm_mday);
  printf("Year:\t%4d\n",now2_tm.tm_year+1900);
}


