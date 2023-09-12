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
char **split_string(char *str, const char *delimiter);


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
 * @path: The path of the file
 * @file: The file name
 *
 * Return: If the file is found - 1
 *	   Otherwise - 0
 */
int find_file(char *path, char *file);

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
 * _setenv - Add or modify an environment variable
 * @name: The name of the variable to add or modify
 * @value: The value to assign to the variable
 * @overwrite: If the variable is present in the environment variable
 *	       and this member is not zero the variable will be updated
 *
 * Return: On success without allocation - 0
 *	   On success and there is memory allocation - 1
 *	   On error - -1
 */
int _setenv(const char *name, const char *value, int overwrite);

#endif /* MAIN_H */
