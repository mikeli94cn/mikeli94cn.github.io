#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	//print now ts,tm,t_fmt,t_str
	time_t ts_now;
	time(&ts_now);
	printf("%lld\n",(long long)ts_now);

	struct tm*  tm_now;
	tm_now=localtime(&ts_now);
	printf("year is %d\n",(tm_now->tm_year)+1900);

	char t_fmt_now[100];
	strftime(t_fmt_now,sizeof(t_fmt_now),"%Y-%m-%d %H:%M:%S %p %a %Z",tm_now);
	printf("%s\n",t_fmt_now);

	char* t_str_now;
	t_str_now=ctime(&ts_now);
	printf("%s\n",t_str_now);

	//print utc ts,tm,t_fmt,t_str
	putenv("TZ=Europe/London");
	tzset();

	struct tm tm_utc;
	localtime_r(&ts_now,&tm_utc);
	printf("year is %d\n",(tm_utc.tm_year)+1900);
	printf("hour is %d\n",tm_utc.tm_hour);
	
	char t_fmt_utc[100];
	strftime(t_fmt_utc,sizeof(t_fmt_utc),"%Y-%m-%d %H:%M:%S %p %a %Z",&tm_utc);
	printf("%s\n",t_fmt_utc);

	time_t ts_utc=mktime(&tm_utc);
	printf("%lld\n",(long long)ts_utc);

	char* t_str_utc;
	t_str_utc=ctime(&ts_utc);
	printf("%s\n",t_str_utc);
}
