# DevFlow

DevFlow is a C++ issue management application designed to organize and track software development tasks. It provides a structured workflow for creating, updating, searching, filtering, sorting, and persistently storing issues.

## Current Features

- Create, view, update, search, and delete issues
- Track issue status, priority, and assignee
- Filter issues by status, priority, and assignee
- Sort issues by priority, ID, and status
- Persistent file-based storage across application sessions
- Input validation and normalization
- Automatic unique issue ID management
- Protection against malformed saved data

## Built With

- C++
- C++ Standard Library
- Object-Oriented Programming
- File I/O
- Git and GitHub

## Current Architecture

DevFlow currently separates issue data from issue-management logic:

- `Issue` — represents an individual issue and its properties
- `IssueManager` — manages issue creation, updates, deletion, searching, filtering, sorting, validation, saving, and loading
- `DevFlow main.cpp` — provides the command-line interface and application flow
- `issues.txt` — local persistent storage generated at runtime and excluded from version control

## Running DevFlow

DevFlow uses CMake as its build system.

Configure the project:

```bash
cmake -S . -B build
```

Build the project:

```bash
cmake --build build
```

Run DevFlow:

```bash
./build/devflow
``` 
## Project Status 

Devflow is actively being developed...