# LRU Cache Implementation in C++

## Overview

This project implements a **Least Recently Used (LRU) Cache** in **C++**, which supports efficient cache operations with constant time complexity, O(1). The LRU Cache is commonly used in scenarios such as **operating systems**, **web browsers**, and **database management systems**, where recent access patterns influence memory management.

The LRU Cache uses a combination of **hash maps** and **doubly linked lists** to achieve constant-time access and eviction operations.

## Features

- **O(1) Complexity** for cache operations (`get` and `put`).
- **Efficient Eviction**: Automatically removes the least recently used items when the cache reaches its maximum capacity.
- **Key-Value Storage**: Supports storing any data associated with unique keys.
- Demonstrates **memory management** and **pointer manipulation** in C++.

## Project Structure

- **Node Class**: Represents each cache entry with pointers to next and previous entries.
- **LRUCache Class**: Manages the cache operations (insertion, access, and eviction).
  
## Getting Started

### Prerequisites

- C++ compiler (e.g., g++, clang++)
- Basic knowledge of C++ standard libraries

### Compiling the Code

To compile the project, run the following commands:

```bash
g++ -o lru_cache lru_cache_output.cpp
