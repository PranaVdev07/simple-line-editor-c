# Simple Line Editor in C

## Team Members

1. Pranav Pandey
2. Mitarth Rai

## Project Description

A simple command-line line editor written in C.

The editor stores lines of text in memory and allows users to
insert, delete and display lines.

## Data Structure

We use an array of strings to store the document lines.

Advantages:
- Simple to implement
- Easy to access lines
- Easy to display

Disadvantage:
- Maximum number of lines is fixed

## Features Implemented

- Insert a line
- Delete a line
- Display the document
- Help command
- Error handling for invalid line numbers
- Empty document handling

## Commands

| Command | Description |
|---|---|
| i <line> <text> | Insert a line |
| d <line> | Delete a line |
| p | Display document |
| h | Display help |
| q | Quit |

## Compilation

```bash
gcc main.c -o line_editor
