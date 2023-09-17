#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stddef.h>
#include <limits.h>
#include <errno.h>

extern char **environ;

/**
 * struct dir_s - A new type called dir_t for struct dir_s
 * @directory: The directory name
 * @next: A ponter to the next node
 */
typedef struct dir_s
{
	char *directory;
	struct dir_s *next;
} dir_t;

/**
 * _strtok - Split the string into tokens
 * @str: The string to split
 * @delim: The string containing delimiters that
 *	   indicate an end of a word(token)
 *
 * Return: A pointer to the next token everytime it is called
 *	   On failure - NULL
 */
char *_strtok(char *str, char *delim);

/**
 * _getline - Get a line from a file and store it in *lineptr
 * @lineptr: A pointer to the buffer's address
 * @n: A pointer to the place of storing the number of the characters read
 * @stream: The file to read a line from
 *
 * Return: The number of characters read
 *	   On failure(EOF or SIGNINT) - -1
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/**
 * split_string - Split the string into an array of tokens
 * @str: The string to split
 * @delimiter: A string containing all the posibble delimiters
 *
 * Return: An array of splitted words
 *	   Or "NULL" on failure
 */
char **split_string(const char *str, const char *delimiter);

/**
 * main - Get an invironment variable
 * @name: The name of the variable
 * @offset: If "name" is found this member will be
 *	    updated to contain the offset of the
 *	    variable inside the environmet array
 *
 * Return: The address of the variable
 *	   or NULL if the variable is not found
 */
char *_getenv(const char *name, int *offset);

/**
 * add_node_end - Add a new node at the end of a linked list
 * @head: A pointer to a pointer to the first node in the linked list
 * @str: The string to put inside the node
 *
 * Return: A pointer to the new node in the linked list
 */
dir_t *add_node_end(dir_t **head, const char *str);

/**
 * print_list - Print the data stored in the nodes of a linked list
 * @h: A pointer to the first node in the linked list
 *
 * Return: The number of nodes
 */
size_t print_list(const dir_t *h);

/**
 * find_file - check if the file is in the current path
 * @file_name: The file name
 *
 * Return: If the file is found - 1
 *	   Otherwise - 0
 */
char *find_file(char *file_name);

/**
 * _strlen - Returns the length of the string
 * @s: The string to calculate its length
 *
 * Return: The length of the string
 */
int _strlen(const char *s);

/**
 * _strcpy - Copy a string in one variable into another variable
 * @src: The string to be copied
 * @dest: The destination of the copied string
 *
 * Return: The pointer to the destination.
 */
char *_strcpy(char *dest, const char *src);

/**
 * _strdup - Copy a string given as a parameter into
 *		  a newly allocated memory space
 * @str: The string to be copied
 *
 * Return: A pointer to the duplicated string, NULL otherwise
 */
char *_strdup(const char *str);

/**
 * _strcmp - Compare two strings
 * @s1: The first string
 * @s2: The string to compare with the first
 * Return: Zero if both strings are identical,
 *	   greater than zero when the matching
 *	   character of left string has greater
 *	   ASCII value than the character of
 *	   the right string, less than zero
 *	   when the left character has a smaller
 *	   value.
 */
int _strcmp(char *s1, char *s2);

/**
 * copy_to_heap - Copy the environment variable array to the heap
 * @count: The number of elements in the stack environment
 * @alloced: This member should be changed to 1 after the allocation
 *
 * Return: On success - 1
 *	   On error - 0
 */
int copy_to_heap(int count, int *alloced);

/**
 * _setenv - Add or modify an environment variable
 * @name: The name of the variable to add or modify
 * @value: The value to assign to the variable
 * @overwrite: If the variable is present in the environment variable
 *	       and this member is not zero the variable will be updated
 *
 * Return: On success - 0
 *	   On error - -1
 */
int _setenv(const char *name, const char *value, int overwrite);

/**
 * _unsetenv - Delete a a variable from the environment variable
 * @name: The name of the variable to delete
 *
 * Return: On success - 0
 *	   On error - -1
 */
int _unsetenv(const char *name);

/**
 * is_alloced - Check  if the environment variable is alloced
 *
 * Return: The address of the static variable to
 *	   be able to change it to 1 if an allocation is made
 */
int *is_alloced(void);

/**
 * is_valid - Check if the variable name passed to [un]setenv() is a valid name
 * @name: The name of the variable passed to setenv
 *
 * Return: If the name is valid - 1
 *	   otherwise - 0
 */
int is_valid(const char *name);

/**
 * clean - Free the allocations created by [un]setenv
 *
 * Return: void
 */
void clean(void);

/**
 * free_tokens - Free an array of tokens
 * @token: The array to be freed
 *
 * Return: void
 */
void free_tokens(char **token);

/**
 * print_env print the current environment
 *
 * Return: void
 */
void print_env(void);

/**
 * create_args - Create the arguments list
 * @buff: This member will store the input written by user
 * @args: After execution this member should contain
 *	  the array of arguments that will be passed to the execve
 */
char **create_args(char *buff, char **args);

/**
 * execute - Execute the passed command
 * @args: The arguments passed to the command
 * @program_path: The path to the program to be executed
 *
 * Return: On success - 0
 *	   On error - 1
 */
int execute(char **args, char *program_path);

/**
 * search_builtins - Check if the command passed is a builtin
 *		     and if it is a builtin execute it
 * @cmd_name: The name of the command
 * @args: The arguments list to pass to the handler functions
 *
 * Return: If builtin found - 1
 *	   Otherwise - 0
 */
int search_builtins(char *cmd_name, char **args);

/**
 * run_interactive - Execute the shell commands in the interactive mode
 *
 * Return: void
 */
void run_interactive(void);

/**
 * run_non_interactive - Execute the shell commands in
 *			 the non interactive mode
 *
 * Return: void
 */
void run_non_interactive(void);

#endif /* MAIN_H */
