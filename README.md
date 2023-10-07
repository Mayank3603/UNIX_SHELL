Assignment 1 Documentation
1)Internal Commands:
i)echo command:
”echo” command in linux is used to display lines of text/string that are passed as an
argument. It can be used to display the string which is given with or without quotation
marks(“”).However, the quotation marks are not displayed when the string message is
printed.
● The user can enter as many arguments in the string message of the echo
command.
● If incorrect use of flags is demonstrated then the flag is evaluated as a
string.
● If the user enters only one quotation and forgets to close the quotation
then an error message is displayed “ The given command is missing “
at the end.”
Flags:
-n: If the command is of the form “echo -n” ,then the linux command prompt is continued in
the very next line itself.
If the command has the correct syntax “echo -n “message”, then the string is printed and
the linux command prompt will pop at the very same time.
-E: It is the default flag of echo command.
-e: It implements the escape sequences such as \n ,\t etc in the string message.
The basic demonstration of all these commands is shown in the below figure.
ii)cd command:
The “cd” command allows the user to change directories.The cd command takes an argument,
usually the name of the folder you want to move to, so the full command is cd your-directory .
The user can also enter two flags at a time.
Assumption: Flag can only be present at argument 1 .
Error:
"-bash: cd: -%c: invalid option\n"
"-bash: cd: too many arguments\n"
"-bash: cd: %s: No such file or directory\n",
Flags:
-P: Handle the operand dot-dot physically; symbolic link components shall be resolved before
dot-dot components are processed.
-L:Handle the operand dot-dot logically; symbolic link components shall not be resolved before
dot-dot components are processed

iii) pwd command: print name of current/working directory.
Error:
"bash: pwd: -%c: invalid option\n"
Flags:
-L:use PWD from environment, even if it contains symlinks
-P: avoid all symlinks
2)External commands:
i) ls command- list directory contents
Assumption: The user can enter only two arguments.
The user can enter the flags on any of the two arguments and also two flags at the same
arguments are also valid.
Error:
"ls: cannot access '%s': No such file or directory"
"Invalid flag\n"
"This directory cannot be opened\n"
Flags:
-m: fill width with a comma separated list of entries
-a: do not ignore entries starting with .
ii) cat command: concatenate files and print on the standard output
Assumption: The user can enter two arguments.
The user can enter flags at both argument one and argument two.
Also handled the case when user didn’t enter file name or just enters cat with any flag:
Error:"cat: %s: No such file or directory\n",
"cat: invalid option --'%c'\n"
"cat: unrecognizable option '%s'\n”
Flags:
-E: display $ at end of each line
-n: number all output lines
iii) date command: prints the date or some flags also changes the date and time.
Assumption: The user can enter two arguments.
Errors:
"date: option '--date: requires an argument\n"
"date: invalid date %s\n"
"date: extra operand '%s\n”
"date: unrecognized option'--%c\n'"
Flags:
-u –utc –universal: prints universal time.
–date=”next <day>”: prints the date of the next day.
iv) mkdir command: It makes the directory specified in arguments.
Assumption: The user can enter three arguments . Flags are only present at the first argument.
If there is any Invalid or any use of flag at argument two or three a message is prompted at the
user screen.
”Assumption: No flags at second or third arguments\n”
Errors: "mkdir: missing operand\n"
"mkdir: unrecognizable option '%s'\n"
"mkdir: invalid option --'%c'\n"
"mkdir: cannot create directory '%s' \n"
"mkdir: invalid mode '%s'\n"
Flags:
-m: set file mode ,not a=rwx -umask
-v: print a message for each created directory
v) rm command: remove files or directories
Assumption: The user can enter two arguments. Flags are only present at the first argument.
If there is any Invalid or any use of flag at argument two a message is prompted at the user screen.
”Assumption: No flags at argument\n”
Errors: "rm: missing operand\n"
"rm: cannot remove '%s': No such file or directory\n"
"rm: unrecognizable option '%s'\n"
"rm: invalid option --'%c'"
Flags:
-f:ignore nonexistent files and arguments, never prompt
-v: print a message for each created directory
