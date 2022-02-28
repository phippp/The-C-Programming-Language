All code prior to task [5_14_Reverse_Flag.c](Chapter%205/5.11/5_14_Reverse_Flag.c) were compiled using g++ without any flags so it was treating the files as a C++ file. As of task [5.14](Chapter%205/5.11/5_14_Reverse_Flag.c) I used `-x c` to force it to be treated as a C file which resolved many casting errors I was getting when tryint to cast between `void *` and `char *`.

To compile:
</br>
`g++ -x c <file>`
