# Terminal Portfolio TUI

A Text-Based User Interface (TUI) portfolio built in C++ and hosted on a hardened Azure Linux server. It allows anyone to view my resume and projects instantly via SSH, with zero installation required.

##  Live Demo

```bash
ssh portfolio@shreetejhadge.dev
```

For Non-technical guys, you paste the above command in the terminal(if you don't know what terminal is, just forget it - YOU ARE NOT WORTHY)

## Stack

* **C++**=
* **CMake**
* **Microsoft Azure**: Hosts the Linux VM which serves the TUI application to the world.
* **GitHub Actions**: Automatically builds the binary and deploys it to the Azure server on every push, ensuring the live portfolio is always up to date.

## Why?

I was tired of seeing portfolios with half-assed "terminal aesthetics" when I was looking for inspiration for my own website.

Therefore, I decided to do one better: a portfolio *inside* the terminal. That way, it has the "terminal aesthetic" by default (smart, right?).

*Note: I also came across ThePrimeagen's `terminal.shop`, which was the real inspiration behind this project.*
