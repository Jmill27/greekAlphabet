#include	<stdlib.h>
#include	<stdio.h>
#include	<ctype.h>
#include	<wchar.h>
#include	<locale.h>

int isUpper_greek	(wchar_t	wc)
	{
		if((wc >= 0x391) && (wc <= 0x3A9))
			return 1;
		return 0;
	}
int	isLower_greek	(wchar_t	wc)
	{
		if((wc >= 0x3B1) && (wc <= 0x3C9))
			return 1;
		return 0;
	}
wchar_t	toUpper_greek	(wchar_t	wc)
	{
		if(wc == 0x3c2)
		{
			wc = 0x3c3 - 0x20;
			return wc;
		}
		else
		{
			wc = wc - 0x20;
			return wc;
		}
	}
wchar_t		toLower_greek	(wchar_t	wc)
	{
	wc = wc + 0x20;
	return wc;
	}

int		main		()
{
  setlocale(LC_ALL,"en_US.UTF-8");

  wchar_t	wc;

  for  (wc = 0x391;  wc <= 0x3C9;  wc++)
  {
    if  ((wc >= 0x3AA) && (wc <= 0x3B0))
      continue;
    if  (wc == 0x3A2)
      continue;
    wprintf(L"U+%04X is %lc ",wc ,wc);
    if (isUpper_greek(wc))
    	wprintf(L": uppercase, lower form %lc\n",toLower_greek(wc));
    else if (isLower_greek(wc))
      wprintf(L": lowercase, upper form %lc\n",toUpper_greek(wc));
    else
      wprintf(L"\n");
  }
  return(EXIT_SUCCESS);
	}
