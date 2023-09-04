#!/bin/bash

COLUMNS=$(tput sc; tput cuf 999; tput rc; tput cols);
ROWS=$(tput sc; tput cuu 999; tput rc; tput lines);
