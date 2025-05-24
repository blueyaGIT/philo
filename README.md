<p align="center">
  <img src="https://github.com/blueyaGIT/blueyaGIT/blob/master/42_badges/philosophersn.png?raw=true" alt="philo"/>
</p>

<p align="center">
  Score: <i>WIP/100</i><br>
  Finished: <i>??.??.2025</i><br>
</p>

###

# Philosophers
Philosophers is a multithreaded dining philosophers problem simulator. The problem is a classic multi-process synchronization problem which was originally formulated in 1965 by Edsger Dijkstra.

## Problem Statement
There are `N` philosophers sitting around a round table. Each philosopher has a dish of spaghetti. A fork is placed between each pair of adjacent philosophers, and each philosopher must alternately think, eat and sleep. However, a philosopher can only eat spaghetti when they have both left and right forks. Each fork can be held by only one philosopher and so a philosopher can use the fork only if it's not being used by another philosopher. After an individual philosopher finishes eating, they need to put down both forks so the forks become available to others. A philosopher can take the fork on their right or the one on their left as they become available, but can't start eating before getting both forks.

_For more information, see [Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)._

---

## Features

### Core Functionality

- **Thread-Based Simulation**:
  - Each philosopher is represented by a thread.
  - Synchronization mechanisms ensure safe resource allocation (forks).

- **Dynamic Parameters**:
  - Adjustable number of philosophers and timings:
    - `number_of_philosophers`
    - `time_to_die`
    - `time_to_eat`
    - `time_to_sleep`
    - `[optional] number_of_times_each_philosopher_must_eat`

- **Actions**:
  - Philosophers alternate between:
    - Eating (requires two forks).
    - Sleeping.
    - Thinking.

- **Log Outputs**:
  - Displays events such as:
    - `timestamp_in_ms X has taken a fork`
    - `timestamp_in_ms X is eating`
    - `timestamp_in_ms X is sleeping`
    - `timestamp_in_ms X is thinking`
    - `timestamp_in_ms X died`

---

## Structure

### Directories and Files

#### `philo/` (Mandatory)

- **`philosophers.c`**:
  Handles initialization, thread creation, and simulation lifecycle.
- **`actions.c`**:
  Implements eating, thinking, and sleeping behaviors.
- **`sync.c`**:
  Provides synchronization logic using mutexes.
- **`utils.c`**:
  Contains helper functions for logging, time management, and error handling.

#### `includes/`

- **`philo.h`**:
  Declares structures, macros, and function prototypes for consistency.

### Key Files

- **Makefile**:
  Automates compilation with targets:
  - `all`, `clean`, `fclean`, `re` and more.

---

## Example Usage

### Compilation

1. **Compile Mandatory Part**:
   ```bash
   make
   ```
   
Run Simulation
Mandatory:

   ```
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
   ```
Example:


   ```
./philo 5 800 200 200
   ```

Rules and Constraints
**Global Variables:**
Forbidden to use global variables.

**Thread Safety:**
Mutexes ensure no data races.

**Error Handling:**
Exits cleanly with explicit error messages for invalid inputs or runtime issues.
Learning Outcomes

**Threading Basics:**
Create and manage threads using pthread_create and pthread_join.
Synchronization Mechanisms:
Prevent race conditions with mutexes and semaphores.
Performance Optimization:

Minimize resource contention and ensure smooth execution.
Philosophers – Bringing concurrency and synchronization to life! 🍝

###

<!-- ## 🚀 Next Project

<a href="https://github.com/blueyaGIT/cub3d"><img src="https://readme-typing-svg.demolab.com?font=Fira+Code&pause=1000&color=BF94E4&width=435&lines=cub3d"></a> -->

## ⏳ Previous Project

<a href="https://github.com/blueyaGIT/minishell"><img src="https://readme-typing-svg.demolab.com?font=Fira+Code&pause=1000&color=BF94E4&width=435&lines=Minishell"></a>
