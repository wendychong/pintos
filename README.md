# PintOS
Completing an implementation of an operating system

## Authors

#### Wendy Chong, Jessica Grazziotin, Paulo Lemus, Jessica Grazziotin

## Table of Contents

* [Purpose](#purpose)
* [Installation](#installation)
* [Run](#run)

## Purpose

Pintos is a simple instructional operating system skeleton originally developed by Ben Pfaff of Stanford University. To read the full documentation of Pintos click on the link below: 
https://web.stanford.edu/class/cs140/projects/pintos/pintos.html#SEC_Top

This project is split into 3 different parts and the purpose of each part is to improve its capabilities as an operating system and make it into a fully functional operating system that supports all features.

In the first part of the project is implementing user programs into Pintos. This is ensure that 13 systems calls will be implemented (I.E wait, exec, halt, etc) as well as argument passing. We must ensure that the processes behind the system calls have proper permissions and do not access improper memory; otherwise, call a page fault. This will be implemented through stacks and processes.

Full documentation for part 1 can be found here: https://web.stanford.edu/class/cs140/projects/pintos/pintos_3.html#SEC32

The second part of the project is implementing threads into Pintos. This will manage threads using different sychronization techniques (locks, semaphores, montiors, etc) to manage resources. It will also implement priority scheduling. 

Full documentation for part 2 can be found here: https://web.stanford.edu/class/cs140/projects/pintos/pintos_2.html#SEC15

The third part of the project  is accessing virtual memory in Pintos. This will help us implement virtual memory by creating a page table and simple replacement policy. 

Full documentation for part 3 can be found here: https://web.stanford.edu/class/cs140/projects/pintos/pintos_4.html#SEC53

This project is run through a virtual machine using Ubutuu and Linux. 

Updates are pending on how to install and run the program. 


## Installation


## Run
