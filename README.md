# PowerPoint CLI Guide

This CLI tool lets you manage slides and shapes through simple commands. Below are the available commands, options, and usage examples.

---

## Commands

### 1. Add a Slide
To add a new slide, use the following command:
```bash
add -i <index> -n <name>


### 2. Add a Shape
To add a new shape command is 
```bash
add <shape> -i <n> -x <n> -y <n> -t <type> etc.

### 3. Execute file
To execute commands from a file, use:
```bash
run -p <path>

(path is relative to executable file)

### 3. Show something
for pringing a slide
```bash
show <slide> -i <n> -t <type>

## Options

| Option | Description                                                        |
|--------|--------------------------------------------------------------------|
| `-i`   | Index of the slide or item                                         |
| `-x`   | X-coordinate position for shapes                                   |
| `-y`   | Y-coordinate position for shapes                                   |
| `-n`   | Name of the slide                                                  |
| `-p`   | Path to a command file (relative to the executable)                |
| `-t`   | Type of item (depends on the command; e.g., shape type, display type) |

