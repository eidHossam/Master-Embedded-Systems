# Task Scheduler Documentation

## Overview
This document provides an overview and documentation for a simple task scheduler designed for ARM architecture. The task scheduler manages two tasks (Task A and Task B) and switches between them based on external interrupts.

## Architecture
The task scheduler operates on ARM architecture and utilizes the Cortex-M3 processor. It leverages different stacks and privilege levels to manage tasks efficiently.

## Stacks
- **Main Stack**: Used for general system operation and initialization.
- **Process Stack (PSP)**: Dedicated stack space for executing tasks.

## Privilege Levels
- **Privileged Access**: Full access to system resources and instructions.
- **Unprivileged Access**: Restricted access to certain resources and instructions.
