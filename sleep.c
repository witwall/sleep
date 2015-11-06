#include <stdio.h>
#include <windows.h>
#include <getopt.h>

static long
argdecode (const char *s)
{
  long value;
  register const char *p = s;
  register char c;

  value = 0;
  while ((c = *p++) >= '0' && c <= '9')
    value = value * 10 + c - '0';

  switch (c)
    {
    case 's':
      value *= 1000;
      break;
    case 'm':
      value *= 60*1000;
      break;
    case 'h':
      value *= 60 * 60*1000;
      break;
    case 'd':
      value *= 60 * 60 * 24*1000;
      break;
    default:
      p--;
    }

  if (*p)
    printf("invalid time interval %s", s);
  return value;
}

/* The name by which this program was run. */
char *program_name;

/* If nonzero, display usage information and exit.  */
static int show_help;

/* If nonzero, print the version on standard output and exit.  */
static int show_version;

static struct option const long_options[] =
{
  {"help", no_argument, &show_help, 1},
  {"version", no_argument, &show_version, 1},
  {0, 0, 0, 0}
};

static void
usage (int status)
{
  if (status != 0)
    printf ("Try %s --help for more information.\n", program_name);
  else
    {
      printf ("Usage: %s [OPTION]... NUMBER[SUFFIX]\n", program_name);
      printf ("\
Pause for NUMBER milliseconds.\n\
SUFFIX may be s to keep seconds, m for minutes, h for hours or d for days.\n\
\n\
  --help      display this help and exit\n\
  --version   output version information and exit\n");
      printf ("\nReport bugs to rocsky@gmail.com");
    }
  exit (status);
}


int
main (int argc, char **argv)
{
  int i;
  unsigned milliseconds = 0;
  int c;
  program_name = argv[0];

  while ((c = getopt_long (argc, argv, "", long_options, (int *) 0)) != EOF)
    {
      switch (c)
	{
	case 0:
	  break;

	default:
	  usage (1);
	}
    }

  if (show_version)
    {
      printf ("sleep  %s\n", 1.0);
      exit (0);
    }

  if (show_help)
    usage (0);

  if (argc == 1)
    {
      printf ("too few arguments\n");
      usage (1);
    }

  for (i = 1; i < argc; i++)
    milliseconds += argdecode (argv[i]);
    
  Sleep(milliseconds);
  exit (0);
}
